package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_25395 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());

        int[] x = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            x[i] = Integer.parseInt(st.nextToken());
        }
        int[] h = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            h[i] = Integer.parseInt(st.nextToken());
        }

        boolean[] visited = new boolean[N];

        // 범위 기반으로 S 기준 최소 최대 범위를 확장하는 방식으로 늘려야 함
        visited[S - 1] = true;
        int min_pos = x[S - 1] - h[S - 1];
        int max_pos = x[S - 1] + h[S - 1];
        int last_min_idx = S - 1;
        int last_max_idx = S - 1;

        while (true) {
            int cur_max_idx = last_max_idx;
            int cur_min_idx = last_min_idx;

            for (int i = cur_max_idx + 1; i < N; i++) {
                if (x[i] <= max_pos) {
                    visited[i] = true;
                    min_pos = Integer.min(min_pos, x[i] - h[i]);
                    max_pos = Integer.max(max_pos, x[i] + h[i]);
                    last_max_idx = i;
                } else break;
            }

            for (int i = cur_min_idx - 1; i >= 0; i--) {
                if (x[i] >= min_pos) {
                    visited[i] = true;
                    min_pos = Integer.min(min_pos, x[i] - h[i]);
                    max_pos = Integer.max(max_pos, x[i] + h[i]);
                    last_min_idx = i;
                } else break;
            }

            // 한번 돌려봤는데도 범위 확장이 안되면 break;
            if (cur_max_idx == last_max_idx && cur_min_idx == last_min_idx) {
                break;
            }
        }

        // visited에 true인 애들을 모두 순서대로 출력
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < N; i++)
            if (visited[i]) {
                output.append(i + 1);
                output.append(" ");
            }

        System.out.println(output);
    }
}
