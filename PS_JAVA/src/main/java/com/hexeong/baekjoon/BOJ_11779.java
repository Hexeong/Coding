package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_11779 {
    static int[] min_price;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        StringTokenizer st;
        List<List<Path>> edges = new LinkedList<>();
        for (int i = 0; i <= n; i++)
            edges.add(new LinkedList<>());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int price = Integer.parseInt(st.nextToken());
            edges.get(start).add(new Path(end, price));
        }

        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        int[] parent = new int[n + 1];

        min_price = new int[n + 1];
        Arrays.fill(min_price, Integer.MAX_VALUE);

        PriorityQueue<Path> pq = new PriorityQueue<>((a, b) -> a.price - b.price);
        pq.add(new Path(start, 0));
        min_price[start] = 0;
        while (!pq.isEmpty()) {
            Path cur = pq.poll();

            if (cur.price > min_price[cur.end]) continue;

            for (Path p : edges.get(cur.end)) {
                if (min_price[p.end] > min_price[cur.end] + p.price) {
                    min_price[p.end] = min_price[cur.end] + p.price;
                    parent[p.end] = cur.end;
                    pq.add(new Path(p.end, min_price[p.end]));
                }
            }
        }

        Deque<Integer> stack = new ArrayDeque<>();
        int curr = end;

        while (curr != 0) {
            stack.push(curr); // 스택의 맨 위에 추가
            curr = parent[curr];
        }

        StringBuilder sb = new StringBuilder();
        System.out.println(min_price[end]); // 최소 비용
        System.out.println(stack.size());   // 경로 도시 개수

        while (!stack.isEmpty()) {
            sb.append(stack.pop());
            if (stack.size() > 0) sb.append(" ");
        }

        System.out.println(sb.toString());
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
