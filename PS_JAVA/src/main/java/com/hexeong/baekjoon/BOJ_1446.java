package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1446 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        Road[] roads = new Road[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            roads[i] = new Road(
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(roads, (r1, r2) -> {
            if (r1.end == r2.end) {
                return Integer.compare(r1.length, r2.length);
            }
            return Integer.compare(r1.end, r2.end);
        });

        int[] dp = new int[D + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        int road_idx = 0;
        for (int i = 1; i <= D; i++) {
            if (road_idx < N && roads[road_idx].end == i) {
                while (road_idx < N && roads[road_idx].end == i) {
                    dp[i] = dp[i] == -1
                            ? Math.min(dp[i - 1] + 1, dp[roads[road_idx].start] + roads[road_idx].length)
                            : Math.min(dp[i], dp[roads[road_idx].start] + roads[road_idx].length);
                    road_idx++;
                }
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }

        System.out.println(dp[D]);
    }

    static class Road {
        public int start;
        public int end;
        public int length;
        public Road(int start, int end, int length) {
            this.start = start;
            this.end = end;
            this.length = length;
        }
    }
}
