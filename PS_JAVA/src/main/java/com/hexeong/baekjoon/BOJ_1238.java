package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1238 {
    static List<List<Path>> adj = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= N; i++)
            adj.add(new ArrayList<>());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            adj.get(a).add(new Path(b, c));
        }

        // 가는 길
        int[] go_result = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            int[] dist = new int[N + 1];
            Arrays.fill(dist, Integer.MAX_VALUE);
            go_result[i] = solve(i, X, dist);
        }

        // 오는 길
        int[] return_result = new int[N + 1];
        Arrays.fill(return_result, Integer.MAX_VALUE);
        solve(X, 1, return_result);

        int max_value = go_result[1] + return_result[1];
        for (int i = 2; i <= N; i++)
            max_value = Math.max(max_value, go_result[i] + return_result[i]);

        System.out.println(max_value);
    }

    static public int solve(int start, int target, int[] dist) {
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
            if (a.cur_price == b.cur_price)
                return a.num - b.num;
            return a.cur_price - b.cur_price;
        });
        pq.add(new Node(start, 0));
        dist[start] = 0;

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (dist[cur.num] < cur.cur_price) continue;

            for (Path next : adj.get(cur.num)) {
                if (dist[next.end] > cur.cur_price + next.price) {
                    dist[next.end] = cur.cur_price + next.price;
                    pq.add(new Node(next.end, dist[next.end]));
                }
            }
        }

        return dist[target];
    }

    static class Path {
        public int end;
        public int price;
        public Path(int end, int price) {
            this.end = end;
            this.price = price;
        }
    }

    static class Node {
        public int num;
        public int cur_price;
        public Node(int num, int cur_price) {
            this.num = num;
            this.cur_price = cur_price;
        }
    }
}
