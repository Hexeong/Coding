package com.hexeong.baekjoon;

import java.util.*;
import java.nio.*;
import java.io.*;

public class BOJ_1103 {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int[][] maxMap;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] map = new int[N][M];
        maxMap = new int[N][M];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();

            for (int j = 0; j < M; j++) {
                char ch = line.charAt(j);

                if (ch == 'H') {
                    map[i][j] = -1; // H인 경우 -1 저장
                } else {
                    map[i][j] = ch - '0';
                }
            }
        }

        // 입력 완료

        boolean[][] visited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            Arrays.fill(visited[i], false);
            Arrays.fill(maxMap[i], -1);
        }

        visited[0][0] = true;
        int max_cnt = solve(map, visited, 0, 0, N, M);
        visited[0][0] = false;

        if (max_cnt != -1) max_cnt++;

        System.out.println(max_cnt);
    }

    private static int solve(int[][] map, boolean[][] visited, int curY, int curX, int N, int M) {
        if (maxMap[curY][curX] != -1)
            return maxMap[curY][curX];

        int local_max = 0;
        for (int i = 0; i < 4; i++) {
            int nxtY = curY + map[curY][curX] * dy[i];
            int nxtX = curX + map[curY][curX] * dx[i];

            if (nxtY <  0 || nxtY >= N || nxtX < 0 || nxtX >= M || map[nxtY][nxtX] == -1) continue;

            if (visited[nxtY][nxtX])
                return -1; // 무한 반복이 가능한 경우

            visited[nxtY][nxtX] = true;
            int tmp = solve(map, visited, nxtY, nxtX, N, M); // 앞 단계에서 최대로 이동 가능했던 횟수
            visited[nxtY][nxtX] = false;

            if (tmp == -1) {
                return -1;
            };

            local_max = Math.max(local_max, tmp + 1);
        }

        maxMap[curY][curX] = local_max;
        return local_max;
    }
}
