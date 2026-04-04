package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_2143_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        int A_n = Integer.parseInt(br.readLine());
        int[] A = new int[A_n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < A_n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int B_n = Integer.parseInt(br.readLine());
        int[] B = new int[B_n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < B_n; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        // 입력 완료

        // A 배열에서 부배열 합으로 만들 수 있는 경우의 수 계산
        HashMap<Integer, Integer> dp_A = new HashMap<>();
        for (int i = 0; i < A_n; i++) {
            int sum = 0;
            for (int k = 0; i + k < A_n; k++) {
                sum += A[i + k];
                dp_A.put(sum, dp_A.getOrDefault(sum, 0) + 1);
            }
        }

        // B 배열에서 부배열 합으로 만들 수 있는 경우의 수 계산
        HashMap<Integer, Integer> dp_B = new HashMap<>();
        for (int i = 0; i < B_n; i++) {
            int sum = 0;
            for (int k = 0; i + k < B_n; k++) {
                sum += B[i + k];
                dp_B.put(sum, dp_B.getOrDefault(sum, 0) + 1);
            }
        }

        long output = 0;
        for (Integer A_key : dp_A.keySet().stream().toList()) {
            output += (long) dp_A.get(A_key) * (long) dp_B.getOrDefault(T - A_key, 0);
        }

        System.out.println(output);
    }
}
