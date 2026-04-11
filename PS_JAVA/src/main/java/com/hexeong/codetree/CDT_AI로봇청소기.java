package com.hexeong.codetree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class CDT_AI로봇청소기 {

    static int[] dy = {0, 1, 0, -1}; // 우(0), 하(1), 좌(2), 상(3)
    static int[] dx = {1, 0, -1, 0};

    static class Pos {
        public int y;
        public int x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static class Path {
        public int y;
        public int x;
        public int dist;
        public Path(int y, int x, int dist) {
            this.y = y;
            this.x = x;
            this.dist = dist;
        }
    }

    // 1. 청소기 이동 (순차적 이동 + 서로 방해물 판정)
    public static void moveCleaner(int[][] map, Pos[] cleaner) {
        for (int c = 0; c < cleaner.length; c++) {
            // 현재 위치에 이미 먼지가 있다면 이동하지 않음
            if (map[cleaner[c].y][cleaner[c].x] > 0) {
                continue;
            }

            Queue<Path> q = new LinkedList<>();
            boolean[][] visited = new boolean[map.length][map.length];

            q.add(new Path(cleaner[c].y, cleaner[c].x, 0));
            visited[cleaner[c].y][cleaner[c].x] = true;

            Path max_dist_pos = new Path(cleaner[c].y, cleaner[c].x, Integer.MAX_VALUE);

            while (!q.isEmpty()) {
                Path cur = q.poll();

                // 이미 찾은 최단 거리보다 멀어지면 더 탐색할 필요 없음
                if (cur.dist >= max_dist_pos.dist) continue;

                for (int i = 0; i < 4; i++) {
                    int ny = cur.y + dy[i];
                    int nx = cur.x + dx[i];

                    if (ny < 0 || ny >= map.length || nx < 0 || nx >= map.length) continue;
                    if (visited[ny][nx]) continue;
                    if (map[ny][nx] == -1) continue; // 물건(-1) 통과 불가

                    // [핵심] 다른 청소기가 있는 위치는 통과 및 도착 불가
                    boolean hasRobot = false;
                    for (int other = 0; other < cleaner.length; other++) {
                        if (c != other && cleaner[other].y == ny && cleaner[other].x == nx) {
                            hasRobot = true;
                            break;
                        }
                    }
                    if (hasRobot) continue;

                    visited[ny][nx] = true;

                    // 먼지가 있는 곳 발견
                    if (map[ny][nx] > 0) {
                        if (max_dist_pos.dist > cur.dist + 1) {
                            max_dist_pos.dist = cur.dist + 1;
                            max_dist_pos.y = ny;
                            max_dist_pos.x = nx;
                        } else if (max_dist_pos.dist == cur.dist + 1) {
                            // 거리가 같으면 행이 작은 순 -> 열이 작은 순
                            if (ny < max_dist_pos.y || (ny == max_dist_pos.y && nx < max_dist_pos.x)) {
                                max_dist_pos.dist = cur.dist + 1;
                                max_dist_pos.y = ny;
                                max_dist_pos.x = nx;
                            }
                        }
                    }

                    q.add(new Path(ny, nx, cur.dist + 1));
                }
            }

            // 도달 가능한 먼지가 있었다면 즉시 위치 갱신 (다음 로봇의 방해물이 됨)
            if (max_dist_pos.dist != Integer.MAX_VALUE) {
                cleaner[c].y = max_dist_pos.y;
                cleaner[c].x = max_dist_pos.x;
            }
        }
    }

    // 2. 청소 (순차적 처리: 앞선 로봇이 청소한 결과가 다음 로봇에 영향을 줌)
    public static void cleanDust(int[][] map, Pos[] cleaner) {
        for (int i = 0; i < cleaner.length; i++) {
            int decision = 0;
            int max_v = -1;

            // 4가지 방향 탐색
            for (int d = 0; d < 4; d++) { // 우선순위: 0(우), 1(하), 2(좌), 3(상)
                int sum = 0;

                // 1. 자신의 위치 (Center)
                if (isCleanPossible(map, cleaner[i].y, cleaner[i].x)) {
                    sum += Math.min(20, map[cleaner[i].y][cleaner[i].x]);
                }

                // 2. 앞(d), 오른쪽, 왼쪽 탐색 (이것이 상대적인 ㅗ 모양이 됨)
                int[] subDirs = {d, (d + 1) % 4, (d + 3) % 4};
                for (int sd : subDirs) {
                    int ny = cleaner[i].y + dy[sd];
                    int nx = cleaner[i].x + dx[sd];
                    if (isCleanPossible(map, ny, nx)) {
                        sum += Math.min(20, map[ny][nx]);
                    }
                }

                // > 사용으로 우선순위(우->하->좌->상) 자동 유지
                if (sum > max_v) {
                    max_v = sum;
                    decision = d;
                }
            }

            // 결정된 방향으로 즉시 청소 실행 (맵 업데이트)
            if (isCleanPossible(map, cleaner[i].y, cleaner[i].x)) {
                map[cleaner[i].y][cleaner[i].x] = Math.max(0, map[cleaner[i].y][cleaner[i].x] - 20);
            }
            int[] subDirs = {decision, (decision + 1) % 4, (decision + 3) % 4};
            for (int sd : subDirs) {
                int ny = cleaner[i].y + dy[sd];
                int nx = cleaner[i].x + dx[sd];
                if (isCleanPossible(map, ny, nx)) {
                    map[ny][nx] = Math.max(0, map[ny][nx] - 20);
                }
            }
        }
    }

    public static boolean isCleanPossible(int[][] map, int y, int x) {
        if (x < 0 || x >= map.length || y < 0 || y >= map.length) return false;
        if (map[y][x] < 0) return false; // 물건(-1) 청소 불가
        return true;
    }

    // 3. 먼지 축적 (동시)
    public static void accumulateDust(int[][] map) {
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map.length; j++) {
                if (map[i][j] > 0) map[i][j] += 5;
            }
        }
    }

    // 4. 먼지 확산
    // "깨끗한 격자에 주변 4방향 격자의 먼지량 합을 10으로 나눈 값"
    public static void expandDust(int[][] map) {
        int[][] result = new int[map.length][map[0].length];

        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map.length; j++) {
                if (map[i][j] == 0) { // 오직 깨끗한 격자에만 확산됨
                    int sum = 0;
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];

                        if (ny >= 0 && ny < map.length && nx >= 0 && nx < map.length) {
                            if (map[ny][nx] > 0) {
                                sum += map[ny][nx]; // 주변 먼지를 합산
                            }
                        }
                    }
                    result[i][j] = sum / 10;
                }
            }
        }

        // 동시에 적용
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map.length; j++) {
                map[i][j] += result[i][j];
            }
        }
    }

    // 5. 총 먼지량 출력
    public static void printTotalDust(int[][] map) {
        int result = 0;
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map.length; j++) {
                if (map[i][j] > 0)
                    result += map[i][j];
            }
        }
        System.out.println(result);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        int[][] map = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        Pos[] cleaner = new Pos[K];
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            cleaner[i] = new Pos(
                    Integer.parseInt(st.nextToken()) - 1,
                    Integer.parseInt(st.nextToken()) - 1
            );
        }

        // 시뮬레이션 L번 진행
        while (L-- > 0) {
            moveCleaner(map, cleaner);
            cleanDust(map, cleaner);
            accumulateDust(map);
            expandDust(map);
            printTotalDust(map); // 각 테스트 끝날 때마다 출력
        }
    }
}