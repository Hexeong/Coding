package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_15989 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        int[] dp = new int[10001];

        dp[0] = 1;
        for (int coin = 1; coin <= 3; coin++) {
            for (int i = coin; i <= 10000; i++) {
                dp[i] = dp[i] + dp[i - coin];
            }
        }

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());

            System.out.println(dp[N]);
        }
    }
}
