package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1504 {
    // 경로 합산 시 int 범위를 넘을 수 있으므로 넉넉한 INF 설정
    static final int INF = 200_000_000;
    static List<List<Path>> adj;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        adj = new ArrayList<>();
        for (int i = 0; i <= N; i++) adj.add(new ArrayList<>());

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            adj.get(a).add(new Path(b, c));
            adj.get(b).add(new Path(a, c));
        }

        st = new StringTokenizer(br.readLine());
        int u = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());

        // 1. u를 시작점으로 하는 다익스트라
        int[] distU = dijkstra(u);
        // 2. v를 시작점으로 하는 다익스트라
        int[] distV = dijkstra(v);

        // 시나리오 1: 1 -> u -> v -> N
        // 무방향이므로 (1->u)는 distU[1]과 같고, (v->N)은 distV[N]과 같음
        long path1 = (long)distU[1] + distU[v] + distV[N];

        // 시나리오 2: 1 -> v -> u -> N
        // 무방향이므로 (1->v)는 distV[1]과 같고, (u->N)은 distU[N]과 같음
        long path2 = (long)distV[1] + distV[u] + distU[N];

        long minPath = Math.min(path1, path2);

        // 결과가 INF보다 크거나 같으면 경로가 없는 것
        if (minPath >= INF) {
            System.out.println(-1);
        } else {
            System.out.println(minPath);
        }
    }

    static int[] dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(n -> n.price));
        int[] dist = new int[N + 1];
        Arrays.fill(dist, INF);

        dist[start] = 0;
        pq.add(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (dist[cur.num] < cur.price) continue;

            for (Path next : adj.get(cur.num)) {
                if (dist[next.end] > cur.price + next.price) {
                    dist[next.end] = cur.price + next.price;
                    pq.add(new Node(next.end, dist[next.end]));
                }
            }
        }
        return dist;
    }

    static class Path {
        int end, price;
        public Path(int end, int price) {
            this.end = end;
            this.price = price;
        }
    }

    static class Node {
        int num, price;
        public Node(int num, int price) {
            this.num = num;
            this.price = price;
        }
    }
}