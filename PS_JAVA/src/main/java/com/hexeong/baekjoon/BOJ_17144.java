package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.StringTokenizer;


public class BOJ_17144 {

    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());

        int purify_y = -1;

        int[][] map = new int[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());

                if (purify_y == -1 && map[i][j] == -1) {
                    purify_y = i;
                }
            }
        }

        while (T > 0) {
            expandDust(map, R, C, purify_y);
            startPurify(map, R, C, purify_y);
            T--;
        }

        long totalDust = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] == -1) continue;

                totalDust += map[i][j];
            }
        }

        System.out.println(totalDust);
    }

    private static void expandDust(int[][] map, int R, int C, int purify_y) {
        List<Pos> target = new ArrayList<>();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] > 0)
                    target.add(new Pos(i, j, map[i][j]));
            }
        }

        for (Pos p : target) {
            int decision_cnt = 0;

            for (int i = 0; i < 4; i++) {
                int nxt_y = p.y + dy[i];
                int nxt_x = p.x + dx[i];

                if (nxt_y < 0 || nxt_y >= R || nxt_x < 0 || nxt_x >= C) // map을 벗어나면 확산 불가
                    continue;
                if ((nxt_y == purify_y || nxt_y == purify_y + 1) && nxt_x == 0) // 공기처정기 위치로는 확산 불가
                    continue;

                // 각 방향으로 확산
                decision_cnt++;
                map[nxt_y][nxt_x] += (p.dust / 5);
            }

            // 확산 이후 남은 dust 양 계산
            map[p.y][p.x] -= (decision_cnt * (p.dust / 5));
        }
    }

    private static void startPurify(int[][] map, int R, int C, int purify_y) {
        // 윗쪽 순환
        for (int i = purify_y - 1; i > 0; i--) map[i][0] = map[i - 1][0];
        for (int i = 0; i < C - 1; i++) map[0][i] = map[0][i + 1];
        for (int i = 0; i < purify_y; i++) map[i][C - 1] = map[i + 1][C - 1];
        for (int i = C - 1; i > 1; i--) map[purify_y][i] = map[purify_y][i - 1];
        map[purify_y][1] = 0;

        // 아랫쪽 순환
        for (int i = purify_y + 2; i < R - 1; i++) map[i][0] = map[i + 1][0];
        for (int i = 0; i < C - 1; i++) map[R - 1][i] = map[R - 1][i + 1];
        for (int i = R - 1; i > purify_y + 1; i--) map[i][C - 1] = map[i - 1][C - 1];
        for (int i = C - 1; i > 1; i--) map[purify_y + 1][i] = map[purify_y + 1][i - 1];
        map[purify_y + 1][1] = 0;
    }

    static class Pos {
        int x;
        int y;
        int dust;
        public Pos(int y, int x, int dust) {
            this.x = x;
            this.y = y;
            this.dust = dust;
        }
    }
}
