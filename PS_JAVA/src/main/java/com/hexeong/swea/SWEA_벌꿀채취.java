package com.hexeong.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class SWEA_벌꿀채취 {

    static int result = 0;

    // 완전 탐색
    // 가로로만 채취 가능
    // N <= 10
    // M <= 5, M <= N
    // C <= 30;
    // 러프하게 N * N에 대해서 2명의 일꾼이 돈다고 했을 때
    // N^2*(N^2+1)/2 가 되므로 O(N^4)이라고 쳐도 10000이된다.
    // 모든 조합을 살펴봐서 C를 넘지 않지만 profit이 최고가 되는 경우를 살펴봐도 2^M <= 32이다.
    // (N^4 * 2^M) = 320000 정도로 충분히 가능하다.

    public static void recur(int[][] map, List<Boolean> member, int baseY, int baseX, int C, int M) {
        if (member.size() == M) {
            int cnt = 0;
            for (int i = 0; i < member.size(); i++) {
                if (member.get(i)) {
                    cnt += map[baseY][baseX + i];
                }
            }

            if (cnt > C) return;

            int profit = 0;
            for (int i = 0; i < member.size(); i++) {
                if (member.get(i)) {
                    profit += (map[baseY][baseX + i] * map[baseY][baseX + i]);
                }
            }

            if (result < profit) {
                result = profit;
            }
            return;
        }

        member.add(true);
        recur(map, member, baseY, baseX, C, M);
        member.set(member.size() - 1, false);
        recur(map, member, baseY, baseX, C, M);
        member.remove(member.size() - 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            int[][] map = new int[N][N];
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int output = 0;
            List<Boolean> member = new LinkedList<>();
            for (int i = 0; i < N * N; i++) {
                int worker1Y = i / N;
                int worker1X = i % N;

                // 가로로만 검사하는지 확인
                if (worker1X + M - 1 >= N) continue;

                for (int j = i + M; j < N * N; j++) {
                    int worker2Y = j / N;
                    int worker2X = j % N;

                    // 가로로만 검사하는지 확인
                    if (worker2X + M - 1 >= N) continue;

                    int tmp = 0;

                    result = 0;
                    recur(map, member, worker1Y, worker1X, C, M);
                    tmp = result;
                    result = 0;
                    recur(map, member, worker2Y, worker2X, C, M);
                    tmp += result;

                    output = Math.max(output, tmp);
                }
            }

            System.out.println("#" + t + " " + output);
        }

    }
}
