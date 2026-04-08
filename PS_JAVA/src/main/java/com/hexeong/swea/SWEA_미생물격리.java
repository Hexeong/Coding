package com.hexeong.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SWEA_미생물격리 {

    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1};

    static class Pos {
        public int max_micro_cnt;
        public int max_micro_idx;
        public int tot_cnt;
        public Pos(int max_micro_cnt, int max_micro_idx, int tot_cnt) {
            this.max_micro_cnt = max_micro_cnt;
            this.max_micro_idx = max_micro_idx;
            this.tot_cnt = tot_cnt;
        }
    }

    static class Micro{
        public int x;
        public int y;
        public int cnt;
        public int decision;
        public Micro(int y, int x, int cnt, int decision) {
            this.y = y;
            this.x = x;
            this.cnt = cnt;
            this.decision = decision;
        }
    }

    // 1. 이동 방향은 상하좌우 4방향 중 하나다. 1시간 마다 이동방향에 있는 다음 셀로 이동한다.
    // 2. 약품이 칠해진 셀에 도착하면 미생물의 절반이 죽고, 이동방향이 반대로 변경된다.
    // 3. 이동 후 두 개 이상의 군집이 한 셀에 모이는 경우 군집들이 합쳐지며,
    //    cnt가 높은 미생물의 방향으로 고착화 된다.

    public static void moveMicro(Micro[] micro_list, int N, boolean[] existed, Pos[][] cnt_map) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cnt_map[i][j] = new Pos(0, 0, 0);
            }
        }

        for (int i = 0; i < micro_list.length; i++) {
            if (!existed[i]) continue;

            int ny = micro_list[i].y + dy[micro_list[i].decision];
            int nx = micro_list[i].x + dx[micro_list[i].decision];

            // 이동했을 때 테두리면 방향 전환과 함께 나누어져야 한다.
            if (ny == 0 || ny == N - 1 || nx == 0 || nx == N - 1) {
                micro_list[i].cnt /= 2;
                micro_list[i].decision = (micro_list[i].decision == 0 || micro_list[i].decision == 2)
                        ? micro_list[i].decision + 1
                        : micro_list[i].decision - 1;
            }

            if (cnt_map[ny][nx].tot_cnt == 0) {
                // 처음 칸에 도착한 사람
                cnt_map[ny][nx].max_micro_cnt = micro_list[i].cnt;
                cnt_map[ny][nx].max_micro_idx = i;
            } else {
                // 두 번쨰로 도착한 사람
                if (cnt_map[ny][nx].max_micro_cnt < micro_list[i].cnt) {
                    // 겹쳐진 미생물의 경우, 기존 max_micro_cnt보다 클 때, 기존 micro를 비활성화 시켜야 한다.
                    cnt_map[ny][nx].max_micro_cnt = micro_list[i].cnt;
                    existed[cnt_map[ny][nx].max_micro_idx] = false;
                    cnt_map[ny][nx].max_micro_idx = i;
                } else {
                    existed[i] = false;
                }
            }

            cnt_map[ny][nx].tot_cnt += micro_list[i].cnt;
            micro_list[i].y = ny;
            micro_list[i].x = nx;
        }

        for (int i = 0; i < micro_list.length; i++) {
            if (!existed[i]) continue;

            micro_list[i].cnt = cnt_map[micro_list[i].y][micro_list[i].x].tot_cnt;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken()); // 한 변의 셀의 수
            int M = Integer.parseInt(st.nextToken()); // 격리 시간 M
            int K = Integer.parseInt(st.nextToken()); // 미생물 군집의 개수 K

            // 맵에 남은 미생물 양
            Pos[][] cnt_map = new Pos[N][N];

            Micro[] micro_list = new Micro[K];
            boolean[] existed = new boolean[K];
            Arrays.fill(existed, true);

            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
                int y = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                int cnt = Integer.parseInt(st.nextToken());
                int decision = Integer.parseInt(st.nextToken()) - 1;

                micro_list[i] = new Micro(y, x, cnt, decision);
            }

            for (int m = 1; m <= M; m++) {
                moveMicro(micro_list, N, existed, cnt_map);
            }

            // 주의: 겹쳐질 떄 한번에 모이는 모든 미생물 개인의 군집 크기만을 비교해서 가장 큰 친구로 해야함.

            int result = 0;
            for (int i = 0; i < K; i++) {
                if (!existed[i]) continue;

                result += micro_list[i].cnt;
            }

            System.out.println("#" + t + " " + result);
        }
    }
}
