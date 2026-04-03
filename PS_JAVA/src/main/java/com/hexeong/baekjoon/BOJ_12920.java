package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ_12920 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        List<Integer> weight = new ArrayList<>();
        List<Long> price = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int V = Integer.parseInt(st.nextToken());
            long C = Long.parseLong(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            for (int k = 1; K > 0; k <<= 1) {
                int num = Math.min(k, K);
                weight.add(num * V);
                price.add(num * C);
                K -= num;
            }
        }

        long[] dp =  new long[M + 1];
        Arrays.fill(dp, 0);
        for (int i = 0; i < weight.size(); i++) {
            for (int j = M; j >= weight.get(i); j--) {
                dp[j] = Math.max(dp[j], dp[j - weight.get(i)] + price.get(i));
            }
        }

        System.out.println(dp[M]);
    }
}
