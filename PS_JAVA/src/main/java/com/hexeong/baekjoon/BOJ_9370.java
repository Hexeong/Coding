package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_9370 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()); // 노드 수
            int m = Integer.parseInt(st.nextToken()); // 엣지 수
            int t = Integer.parseInt(st.nextToken()); // 도착지 후보 수

            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()); // 출발 노드
            int g = Integer.parseInt(st.nextToken()); // 무조건 지나간 도로의 노드 1
            int h = Integer.parseInt(st.nextToken()); // 무조건 지나간 도로의 노드 2

            List<List<Edge>> edges = new ArrayList<>();
            for (int i = 0; i <= n; i++)
                edges.add(new ArrayList<>());

            for (int i = 0; i < m; i++) { // 엣지 정보
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken()) * 2;
                if ((a == g && b == h) || (a == h && b == g)) d--;
                edges.get(a).add(new Edge(b, d));
                edges.get(b).add(new Edge(a, d));
            }

            List<Integer> end_point = new ArrayList<>(); // 목표 후보지
            for (int i = 0; i < t; i++)
                end_point.add(Integer.parseInt(br.readLine()));
            end_point.sort(Comparator.naturalOrder());

            // 입력 완료

            // 무조건 지나간 도로의 노드 1과 2에서 다익스트라로 모든 노드로의 최소 거리 계산
            PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
                if (a.price == b.price) {
                    return a.num - b.num;
                }
                return a.price - b.price;
            });

            int[] min_price = new int[n + 1];
            Arrays.fill(min_price, Integer.MAX_VALUE);
            dijkstra(min_price, pq, edges, new Node(s, 0), g, h); // s를 기준으로 계산

            StringBuilder sb = new StringBuilder();
            for (int dest : end_point) {
                if (min_price[dest] < Integer.MAX_VALUE && min_price[dest] % 2 != 0) {
                    sb.append(dest).append(" ");
                }
            }
            System.out.println(sb.toString());
        }

    }

    static void dijkstra(int[] min_price, PriorityQueue<Node> pq, List<List<Edge>> edges, Node start, int g, int h) {
        pq.add(start);
        Arrays.fill(min_price, Integer.MAX_VALUE);
        min_price[start.num] = 0;
        while(!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.price > min_price[cur.num]) continue;

            for (Edge e : edges.get(cur.num)) {
                if (min_price[e.end] > e.price + cur.price) {
                    min_price[e.end] = e.price + cur.price;
                    pq.add(new Node(e.end, min_price[e.end]));
                }
            }
        }
    }

    static class Edge {
        int end;
        int price;
        Edge(int end, int price) {
            this.end = end;
            this.price = price;
        }
    }

    static class Node {
        int num;
        int price;
        Node(int num, int price) {
            this.num = num;
            this.price = price;
        }
    }
}
