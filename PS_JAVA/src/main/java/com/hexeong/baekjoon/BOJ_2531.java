package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2531 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int[] belt = new int[N];
        for (int i = 0; i < N; i++) {
            belt[i] = Integer.parseInt(br.readLine());
        }

        // 초밥 종류별로 내가 현재 먹고 있는 개수를 저장하는 배열 (가장 중요!)
        int[] counts = new int[d + 1];
        int uniqueCount = 0; // 현재 내가 먹은 초밥의 종류(가짓수)

        // 1. 첫 번째 창문(0번 인덱스부터 k개)을 먼저 세팅합니다.
        for (int i = 0; i < k; i++) {
            if (counts[belt[i]] == 0) {
                uniqueCount++; // 처음 먹어보는 종류면 가짓수 증가
            }
            counts[belt[i]]++; // 먹은 초밥 개수 증가
        }

        // 쿠폰 처리: 현재 윈도우에 쿠폰 초밥(c)이 없다면 가짓수 +1
        int maxOut = uniqueCount;
        if (counts[c] == 0) {
            maxOut++;
        }

        // 2. 창문을 한 칸씩 옆으로 밉니다. (Sliding Window)
        for (int i = 0; i < N - 1; i++) {
            // 맨 왼쪽 초밥은 뱉어냅니다 (창문에서 빠짐)
            int left = belt[i];
            counts[left]--;
            if (counts[left] == 0) {
                uniqueCount--; // 뱉었더니 이제 그 종류가 하나도 안 남았다면 가짓수 감소
            }

            // 오른쪽의 새로운 초밥을 먹습니다 (창문에 들어옴)
            // (i + k) % N 을 통해 원형 레일을 처리합니다.
            int right = belt[(i + k) % N];
            if (counts[right] == 0) {
                uniqueCount++; // 새로 들어온 놈이 처음 먹어보는 종류라면 가짓수 증가
            }
            counts[right]++;

            // 현재 상태에서 쿠폰을 적용했을 때의 최댓값 갱신
            int currentOut = uniqueCount;
            if (counts[c] == 0) {
                currentOut++;
            }
            maxOut = Math.max(maxOut, currentOut);
        }

        System.out.println(maxOut);
    }
}
