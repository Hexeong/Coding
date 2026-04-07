package com.hexeong.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class SWEA_점심식사시간 {

    static int result = Integer.MAX_VALUE;
    static List<Pos> personList = new ArrayList<>();
    static List<Pos> stairList = new ArrayList<>();

    static class Pos {
        public int y;
        public int x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static class Task {
        public int endTime;
        public int num;
        public Task(int endTime, int num) {
            this.endTime = endTime;
            this.num = num;
        }
    }

    static void solve(List<Integer> a, List<Integer> b, int cur_person, int[][] map) { // 1000
        if (cur_person == personList.size()) {
            // 여기서 처리
            process(a, b, map);
            return;
        }

        a.add(cur_person);
        solve(a, b, cur_person + 1, map);
        a.remove(a.size() - 1);
        b.add(cur_person);
        solve(a, b, cur_person + 1, map);
        b.remove(b.size() - 1);
    }

    static void process(List<Integer> a, List<Integer> b, int[][] map) {
        int finish_cnt = 0;

        PriorityQueue<Task> waitingQ1 = new PriorityQueue<>((aa, bb) -> {
            if (aa.endTime != bb.endTime)
                return aa.endTime - bb.endTime;
            return aa.num - bb.num;
        });

        PriorityQueue<Task> waitingQ2 = new PriorityQueue<>((aa, bb) -> {
            if (aa.endTime != bb.endTime)
                return aa.endTime - bb.endTime;
            return aa.num - bb.num;
        });

        boolean[] finished = new boolean[personList.size()];
        Arrays.fill(finished, false);

        int cur_t = 0;
        int finished_time = Integer.MAX_VALUE;

//        if (b.size() == 4 && a.size() == 3) {
//            if (b.get(0) == 0
//                    && b.get(1) == 1
//                    && b.get(2) == 5
//                    && b.get(3) == 6
//                    && a.get(0) == 2
//                    && a.get(1) == 3
//                    && a.get(2) == 4)
//                System.out.println();
//        }

        while (finish_cnt < personList.size()) {
            while (!waitingQ1.isEmpty() && waitingQ1.peek().endTime <= cur_t) {
                finished_time = waitingQ1.poll().endTime;
                finish_cnt++;
            }

            for (int a_i: a) {
                if (finished[a_i])
                    continue;

                int dist = Math.abs(personList.get(a_i).x - stairList.get(0).x)
                        + Math.abs(personList.get(a_i).y - stairList.get(0).y) + 1;

                if (cur_t >= dist && waitingQ1.size() < 3) {
                    waitingQ1.add(new Task(cur_t + map[stairList.get(0).y][stairList.get(0).x], a_i + 1));
                    finished[a_i] = true;
                }
            }

            while (!waitingQ2.isEmpty() && waitingQ2.peek().endTime <= cur_t) {
                finished_time = waitingQ2.poll().endTime;
                finish_cnt++;
            }

            for (int b_i : b) {
                if (finished[b_i])
                    continue;

                int dist = Math.abs(personList.get(b_i).x - stairList.get(1).x)
                        + Math.abs(personList.get(b_i).y - stairList.get(1).y) + 1;

                if (cur_t >= dist && waitingQ2.size() < 3) {
                    waitingQ2.add(new Task(cur_t + map[stairList.get(1).y][stairList.get(1).x], b_i + 1));
                    finished[b_i] = true;
                }
            }

            cur_t++;
        }

        if (result > finished_time)
            result = finished_time;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for (int t = 1; t <= T; t++) {
            // 한 변의 길이인 N은 4이상 10이하
            int N = Integer.parseInt(br.readLine());
            int[][] map = new int[N][N];

            // 사람의 수는 10 이하

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    // 사람은 1, 계단 길이는 2 이상 10 이하
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if (map[i][j] == 1) {
                        personList.add(new Pos(i, j));
                    }
                    if (map[i][j] >= 2) {
                        stairList.add(new Pos(i, j));
                    }
                }
            }

            // 입력 완료

            List<Integer> a = new LinkedList<>();
            List<Integer> b = new LinkedList<>();
            solve(a, b, 0, map);

            System.out.println("#" + t + " " + result);

            result = Integer.MAX_VALUE;
            personList.clear();
            stairList.clear();
        }
    }
}
