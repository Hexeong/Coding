package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1520 {
    static int[] dy = {1, 0 ,-1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[][] map = new int[M][N];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // dp? 올수 있는 방향을 일단 체크하자
        dp = new int[M][N];
        for (int i = 0; i < M; i++) Arrays.fill(dp[i], -1);

        System.out.println(solve(map, 0, 0, M, N));
    }

    private static int solve(int[][] map, int curY, int curX, int M, int N) {
        // 목적지 도달 시 경로 1개 반환
        if (curY == M - 1 && curX == N - 1) return 1;

        // 이미 계산된 적이 있다면 그 값을 즉시 반환
        if (dp[curY][curX] != -1) return dp[curY][curX];

        // 아직 계산 전이라면 0으로 초기화하고 탐색 시작
        dp[curY][curX] = 0;

        for (int i = 0; i < 4; i++) {
            int nxtY = curY + dy[i];
            int nxtX = curX + dx[i];

            if (nxtY < 0 || nxtY >= M || nxtX < 0 || nxtX >= N) continue;

            // 내리막 길 조건 체크
            if (map[curY][curX] > map[nxtY][nxtX]) {
                dp[curY][curX] += solve(map, nxtY, nxtX, M, N);
            }
        }

        return dp[curY][curX];
    }
}
