package com.hexeong.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA_수영장 {

    // 모든 종류의 이용권 요금은 3000 이하
    static int solve(int[] plan, int[] price) {
        // dp[i]는 i월까지의 최소 이용 요금
        int[] dp = new int[13];

        for (int i = 1; i <= 12; i++) {
            int costDay = dp[i - 1] + (plan[i] * price[0]);
            int costMonth = dp[i - 1] + price[1];

            dp[i] = Math.min(costDay, costMonth);

            if (i >= 3) {
                dp[i] = Math.min(dp[i], dp[i - 3] + price[2]);
            } else {
                // 작년 11월 또는 12월에 3달권을 끊는 경우 (이전 비용이 0이므로 그냥 3달권 가격)
                // 11월, 12월에 끊는 경우를 앞으로 땡겨오는 방식
                dp[i] = Math.min(dp[i], price[2]);
            }
        }

        return Math.min(dp[12], price[3]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            int[] price = new int[4];
            for (int i = 0; i < 4; i++) {
                price[i] = Integer.parseInt(st.nextToken());
            }

            int[] plan = new int[13];
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= 12; i++) plan[i] = Integer.parseInt(st.nextToken());

            System.out.println("#" + t + " " + solve(plan, price));
        }
    }
}

// 2 2 4 5 1 1 5 4 3 3
// 2 1 3 5 1 2 5 3 3 3
// 5 4 4 2 3
// 4 3 2 4 2 4 3