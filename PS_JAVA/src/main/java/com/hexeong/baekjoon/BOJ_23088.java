package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_23088 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        Task[] taskLists =  new Task[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            taskLists[i] = new Task(
                    i + 1,
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(taskLists, (t1, t2) -> Integer.compare(t1.req_time, t2.req_time));

        PriorityQueue<Task> pq = new PriorityQueue<>();
        StringBuilder out = new StringBuilder();
        long time = 0;
        int taskListIdx = 0;
        while (taskListIdx < N || !pq.isEmpty()) {
            while (taskListIdx < N && taskLists[taskListIdx].req_time <= time) {
                pq.add(taskLists[taskListIdx++]);
            }

            if (pq.isEmpty()) {
                time = taskLists[taskListIdx].req_time;
                continue;
            }

            Task p = pq.poll();
            out.append(p.num).append(" ");
            time += p.exec_time;
        }

        System.out.println(out);
    }

    static class Task implements Comparable<Task> {
        public int num;
        public int req_time;
        public int priority;
        public int exec_time;
        public Task(int num, int req_time, int priority, int exec_time) {
            this.num = num;
            this.req_time = req_time;
            this.priority = priority;
            this.exec_time = exec_time;
        }

        @Override
        public int compareTo(Task o) {

            // 현재 우선순위 = 초기 우선순위 + (현재 시간 - 초기 요청 시간);
            // 현재 시간 값은 모두에게 동일하니 삭제하고 초기 우선순위 - 초기 요청 시간 값을 기준으로 설정;
            int myRelativePriority = this.priority - this.req_time;
            int oRelativePriority = o.priority - o.req_time;

            // 1. (우선순위 + 대기시간)이 큰 순서대로 (내림차순)
            if (myRelativePriority != oRelativePriority) {
                return Integer.compare(oRelativePriority, myRelativePriority);
            }
            // 2. 실행 시간이 짧은 순서대로 (오름차순)
            if (this.exec_time != o.exec_time) {
                return Integer.compare(this.exec_time, o.exec_time);
            }
            // 3. 작업 번호가 작은 순서대로 (오름차순)
            return Integer.compare(this.num, o.num);
        }
    }
}
