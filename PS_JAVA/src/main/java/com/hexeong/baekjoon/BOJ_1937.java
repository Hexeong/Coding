package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1937 {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st;

        int[][] map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        boolean[][] visited = new boolean[n][n];
        int maxCnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = true;
                maxCnt = Math.max(maxCnt, solve(map, visited, i, j, n));
                visited[i][j] = false;
            }
        }

        System.out.println(maxCnt);
    }

    private static int solve(int[][] map, boolean[][] visited, int curY, int curX, int n) {
        if (dp[curY][curX] != -1)
            return dp[curY][curX];

        int sum = 1;
        for (int i = 0; i < 4; i++) {
            int nxtY = curY + dy[i];
            int nxtX = curX + dx[i];

            if (nxtY < 0 || nxtY >= n || nxtX < 0 || nxtX >= n) continue;
            if (visited[nxtY][nxtX] || map[nxtY][nxtX] <= map[curY][curX]) continue;

            if (dp[nxtY][nxtX] != -1) {
                sum = Math.max(sum, dp[nxtY][nxtX] + 1);
                continue;
            }

            visited[nxtY][nxtX] = true;
            sum = Math.max(sum, solve(map, visited, nxtY, nxtX, n) + 1);
            visited[nxtY][nxtX] = false;
        }

        dp[curY][curX] = sum;
        return sum;
    }
}
