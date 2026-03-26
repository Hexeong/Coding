package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class BOJ_2143 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        int A_n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int[] A = new int[A_n];
        for (int i = 0; i < A_n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int B_n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int[] B = new int[B_n];
        for (int i = 0; i < B_n; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        HashMap<Integer, Integer> A_map = new HashMap<>();
        HashMap<Integer, Integer> B_map = new HashMap<>();

        for (int k = 1; k <= A_n; k++) {
            for (int i = 0; i <= A_n - k; i++) {
                int sum = 0;
                for (int j = 0; j < k; j++) {
                    sum += A[i + j];
                }
                if (A_map.containsKey(sum)) {
                    A_map.put(sum, A_map.get(sum) + 1);
                } else  {
                    A_map.put(sum, 1);
                }
            }
        }

        for (int k = 1; k <= B_n; k++) {
            for (int i = 0; i <= B_n - k; i++) {
                int sum = 0;
                for (int j = 0; j < k; j++) {
                    sum += B[i + j];
                }
                if (B_map.containsKey(sum)) {
                    B_map.put(sum, B_map.get(sum) + 1);
                } else  {
                    B_map.put(sum, 1);
                }
            }
        }

        long output = 0;
        List<Integer> list = A_map.keySet().stream().sorted().collect(Collectors.toList());
        for (int a_key : list) {
            long a_cnt = A_map.get(a_key);

            if (!B_map.containsKey(T - a_key)) continue;

            long b_cnt = B_map.get(T - a_key);
            output += a_cnt * b_cnt;
        }

        System.out.println(output);
    }
}
