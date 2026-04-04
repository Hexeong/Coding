package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1766 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] indegree = new int[N];
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < N; i++)
            adj.add(new ArrayList<>());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj.get(a - 1).add(b - 1); // a를 풀어야 b를 풀 수 있음
            indegree[b - 1]++;         // b 입장에선 나를 가리키는 화살표가 하나 늘어남
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0)
                pq.add(i); // 처음에 바로 풀 수 있는 문제들
        }

        List<String> output = new ArrayList<>();
        // 1. 진입 차수(in-degree)가 0인 문제를 PQ에서 꺼낸다.
        while (!pq.isEmpty()) {
            int cur = pq.poll();

            // 2. 문제를 풀었으므로 결과 리스트에 담는다. (1번 문제부터 시작하므로 +1)
            output.add(String.valueOf(cur + 1));

            // 3. 이 문제(cur)와 연결된 다음 문제들을 확인한다.
            for (int next : adj.get(cur)) {
                // 4. 선수 조건을 하나 해결했으므로 다음 문제의 진입 차수를 1 줄인다.
                indegree[next]--;

                // 5. 만약 진입 차수가 0이 되었다면, 이제 풀 수 있는 상태이므로 PQ에 넣는다.
                if (indegree[next] == 0) {
                    pq.add(next);
                }
            }
        }

        System.out.println(String.join(" ", output));
    }
}
