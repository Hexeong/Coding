package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1253 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 1. 입력 받기
        int N = Integer.parseInt(br.readLine());
        if (N < 3) { // 3개 미만이면 어떤 수도 '다른 두 수의 합'이 될 수 없음
            System.out.println(0);
            return;
        }

        long[] list = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            list[i] = Long.parseLong(st.nextToken());
        }

        // 2. 정렬 (투 포인터의 필수 조건)
        Arrays.sort(list);

        int count = 0;

        // 3. 각 숫자 i를 '타겟'으로 정하고 투 포인터 탐색
        for (int i = 0; i < N; i++) {
            long target = list[i];
            int left = 0;
            int right = N - 1;

            while (left < right) {
                // 자기 자신(인덱스 i)은 합의 재료로 쓸 수 없음
                if (left == i) {
                    left++;
                    continue;
                }
                if (right == i) {
                    right--;
                    continue;
                }

                long sum = list[left] + list[right];

                if (sum == target) {
                    // 서로 다른 두 인덱스의 합으로 target을 만들 수 있음!
                    count++;
                    break; // i번째 숫자는 '좋은 수' 확정이므로 다음 i로 이동
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        System.out.println(count);
    }
}
