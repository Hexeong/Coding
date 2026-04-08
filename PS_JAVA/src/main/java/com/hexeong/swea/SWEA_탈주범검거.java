package com.hexeong.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class SWEA_탈주범검거 {

    static int[] dy = {-1, 0 ,1, 0};
    static int[] dx = {0, 1, 0, -1};

    static class Pos {
        public int y;
        public int x;
        public int time;
        public Pos(int y, int x, int time) {
            this.y = y;
            this.x = x;
            this.time = time;
        }
    }

    static int bfs(int[][] map, int N, int M, int R, int C, int L) {
        boolean[][] visited = new boolean[N][M];
        for (int i = 0; i < N; i++)
            Arrays.fill(visited[i], false);
        Deque<Pos> q = new ArrayDeque<>();

        int cnt = 1;
        q.add(new Pos(R, C, 1));
        visited[R][C] = true;

        while (!q.isEmpty()) {
            Pos cur = q.poll();

            if (cur.time >= L)
                continue;

            for (int i = 0; i < 4; i++) {
                if (!isPossible(map, cur.y, cur.x, i)) continue;

                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (map[ny][nx] == 0) continue;
                if (!isNextPossible(map, ny, nx, i)) continue;

                if (!visited[ny][nx]) {
                    cnt++;
                    q.add(new Pos(ny, nx, cur.time + 1));
                    visited[ny][nx] = true;
                }
            }
        }

        return cnt;
    }

    static boolean isPossible(int[][] map, int curY, int curX, int decision) {
        if (map[curY][curX] == 1) return true;
        else if (map[curY][curX] == 2) {
            if (decision % 2 == 0) return true;
        }
        else if (map[curY][curX] == 3) {
            if (decision % 2 == 1) return true;
        }
        else if (map[curY][curX] == 4) {
            if (decision == 0 || decision == 1) return true;
        }
        else if (map[curY][curX] == 5) {
            if (decision == 1 || decision == 2) return true;
        }
        else if (map[curY][curX] == 6){
            if (decision == 2 || decision == 3) return true;
        }
        else if (map[curY][curX] == 7) {
            if (decision == 3 || decision == 0) return true;
        }

        return false;
    }

    static boolean isNextPossible(int[][] map, int ny, int nx, int decision) {
        if (decision == 0) {
            if (map[ny][nx] == 1
                    || map[ny][nx] == 2
                    || map[ny][nx] == 5
                    || map[ny][nx] == 6)
                return true;
        } else if (decision == 1) {
            if (map[ny][nx] == 1
                    || map[ny][nx] == 3
                    || map[ny][nx] == 6
                    || map[ny][nx] == 7)
                return true;

        } else if (decision == 2) {
            if (map[ny][nx] == 1
                    || map[ny][nx] == 2
                    || map[ny][nx] == 4
                    || map[ny][nx] == 7)
                return true;
        } else if (decision == 3) {
            if (map[ny][nx] == 1
                    || map[ny][nx] == 3
                    || map[ny][nx] == 4
                    || map[ny][nx] == 5)
                return true;
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            int L = Integer.parseInt(st.nextToken());

            int[][] map = new int[N][M];
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            System.out.println("#" + t + " " + bfs(map, N, M, R, C, L));
        }
    }
}
