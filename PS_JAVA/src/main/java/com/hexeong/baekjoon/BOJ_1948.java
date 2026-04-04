package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1948 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        List<List<Path>> adj = new ArrayList<>();
        List<List<Path>> reverseAdj = new ArrayList<>(); // 역추적을 위한 역방향 그래프
        int[] inDegree = new int[n + 1]; // 위상 정렬을 위한 진입 차수

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
            reverseAdj.add(new ArrayList<>());
        }

        StringTokenizer st;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            adj.get(u).add(new Path(v, w));
            reverseAdj.get(v).add(new Path(u, w)); // 역방향 저장
            inDegree[v]++;
        }

        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        // 1. 정방향: 위상 정렬을 이용한 최대 거리(임계 경로) 계산
        int[] dist = new int[n + 1];
        Queue<Integer> q = new ArrayDeque<>();
        q.add(start);

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (Path next : adj.get(cur)) {
                // 더 긴 경로 발견 시 업데이트 (Memoization 성격)
                if (dist[next.end] < dist[cur] + next.price) {
                    dist[next.end] = dist[cur] + next.price;
                }

                inDegree[next.end]--;
                if (inDegree[next.end] == 0) {
                    q.add(next.end);
                }
            }
        }

        // 2. 역방향: 목적지부터 역추적하며 모든 임계 경로의 도로 개수 카운트
        int routeCnt = 0;
        boolean[] visited = new boolean[n + 1]; // 노드 중복 방문 방지 (중요!)
        Queue<Integer> reverseQ = new ArrayDeque<>();

        reverseQ.add(end);
        visited[end] = true;

        while (!reverseQ.isEmpty()) {
            int cur = reverseQ.poll();

            for (Path prev : reverseAdj.get(cur)) {
                // 핵심 로직: (현재 노드까지의 최대 거리) == (이전 노드 최대 거리 + 도로 가중치)
                // 이 조건이 맞으면 이 도로는 '황금 도로(임계 경로)'에 포함됩니다.
                if (dist[cur] == dist[prev.end] + prev.price) {
                    routeCnt++; // 도로는 보일 때마다 카운트

                    // 노드는 한 번만 방문하여 큐에 넣음 (시간 초과 방지)
                    if (!visited[prev.end]) {
                        visited[prev.end] = true;
                        reverseQ.add(prev.end);
                    }
                }
            }
        }

        System.out.println(dist[end]);
        System.out.println(routeCnt);
    }

    static class Path {
        public int end;
        public int price;
        public Path(int end, int price) {
            this.end = end;
            this.price = price;
        }
    }
}