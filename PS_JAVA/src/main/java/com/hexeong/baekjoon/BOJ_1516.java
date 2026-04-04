package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1516 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<>());
        }

        int[] indeg = new int[N];
        Arrays.fill(indeg, 0);

        int[] time = new int[N];
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            time[i] = Integer.parseInt(st.nextToken());

            int a;
            while ((a = Integer.parseInt(st.nextToken())) != -1) {
                edges.get(a - 1).add(i);
                indeg[i]++;
            }
        }

        int[] result = new int[N];
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.cur_time - b.cur_time);
        for (int i = 0; i < N; i++)
            if (indeg[i] == 0) {
                result[i] = time[i];
                pq.add(new Node(i, time[i]));
            }

        while(!pq.isEmpty()){
            Node node = pq.poll();

            for (int next : edges.get(node.num)) {
                result[next] = Math.max(result[next], node.cur_time + time[next]);
                if (--indeg[next] == 0) pq.add(new Node(next, result[next]));
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++)
            sb.append(result[i]).append(" ");

        System.out.println(sb.toString());
    }

    static class Node {
        public int num;
        public int cur_time;
        public Node(int num, int cur_time) {
            this.num = num;
            this.cur_time = cur_time;
        }
    }
}
