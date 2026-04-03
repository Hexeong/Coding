package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_12865 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] weight = new int[N];
        long[] price = new long[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            weight[i] = Integer.parseInt(st.nextToken());
            price[i] = Long.parseLong(st.nextToken());
        }

        long[] dp = new long[M + 1];
        Arrays.fill(dp, 0);
        for (int i = 0; i < N; i++) {
            for (int j = M; j >= weight[i]; j--) {
                dp[j] = Math.max(dp[j], dp[j - weight[i]] + price[i]);
            }
        }

        System.out.println(dp[M]);
    }
}
