import java.util.*;

public class Main {

    static int N, K;
    static int[][] grid;
    static int[][] visited; // 해당 칸에 대해 최소

    static int stY, stX, edY, edX;

    static int[] dy = {1, 0 ,-1, 0};
    static int[] dx = {0, 1, 0, -1};

    static int minV = Integer.MAX_VALUE;

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        K = sc.nextInt();

        grid = new int[N][N];
        visited = new int[N][N];
        for (int i = 0; i < N; i++)
            Arrays.fill(visited[i], Integer.MAX_VALUE);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                grid[i][j] = sc.nextInt();

        stY = sc.nextInt() - 1;
        stX = sc.nextInt() - 1;
        edY = sc.nextInt() - 1;
        edX = sc.nextInt() - 1;

        bfs();

        if (minV == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(minV);
        }
    }

    private static void bfs() {
        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(stY, stX, 0, 0));
        visited[stY][stX] = 0;

        while(!q.isEmpty()) {
            Pos c = q.poll();

            if (c.y == edY && c.x == edX) {
                minV = Math.min(minV, c.cnt);
                continue;
            }

            if (visited[c.y][c.x] < c.k)
                continue;

            for (int i = 0; i < 4; i++) {
                int ny = c.y + dy[i];
                int nx = c.x + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

                if (grid[ny][nx] == 1) {
                    if (c.k + 1 > K) continue;
                    if (visited[ny][nx] <= c.k + 1) continue;

                    visited[ny][nx] = c.k + 1;
                    q.add(new Pos(ny, nx, c.k + 1, c.cnt + 1));
                } else {
                    if (visited[ny][nx] <= c.k) continue;

                    visited[ny][nx] = c.k;
                    q.add(new Pos(ny, nx, c.k, c.cnt + 1));
                }
            }
        }
    }

    static class Pos {
        int y;
        int x; 
        int k;
        int cnt;
        public Pos(int y, int x, int k, int cnt) {
            this.y = y;
            this.x = x;
            this.k = k;
            this.cnt = cnt;
        }
    }
}