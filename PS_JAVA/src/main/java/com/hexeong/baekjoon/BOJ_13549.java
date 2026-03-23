package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class BOJ_13549 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        if (N == K) {
            System.out.println(0);
            return;
        }

        int[] dp = new int[100001];
        Arrays.fill(dp, 200000);
        dp[N] = 0;
        Deque<Integer> q = new ArrayDeque<>();
        q.addLast(N);
        while (!q.isEmpty()) {
            int cur = q.pollFirst();

            if (cur == K) break;

            if (cur * 2 <= 100000 && dp[cur * 2] > dp[cur]) {
                dp[cur * 2] = dp[cur];
                q.addFirst(cur * 2);
            }

            if (cur - 1 >= 0 && dp[cur - 1] > dp[cur] + 1) {
                dp[cur - 1] = dp[cur] + 1;
                q.addLast(cur - 1);
            }

            if (cur + 1 <= 100000 && dp[cur + 1] > dp[cur] + 1) {
                dp[cur + 1] = dp[cur] + 1;
                q.addLast(cur + 1);
            }
        }

        System.out.println(dp[K]);
    }
}
