import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }

    static int n, ans = 0;
    static int[][][] grids; 
    static boolean[][][] visitedPool;

    public static void main(String[] args) {
        // Please write your code here.

        n = nextInt();
        grids = new int[4][3 * n][n];
        visitedPool = new boolean[4][3 * n][n];

        for (int i = 0; i < 3 * n; i++) {
            for (int j = 0; j < n; j++) {
                grids[0][i][j] = nextInt();
            }
        }

        dfs(0, 0);

        System.out.println(ans);
    }

    // (N*N)^3 <= 255^3 < 27,000,000
    static void dfs(int ck, int cmnt) {
        if (ck == 3) {
            ans = Math.max(ans, cmnt);
            return;
        }

        // 현재 턴(ck)에서 사용할 visited 배열을 매번 초기화하여 재사용합니다.
        for (int i = 2 * n; i < 3 * n; i++) {
            for (int j = 0; j < n; j++) {
                visitedPool[ck][i][j] = false;
            }
        }

        for (int i = 2 * n; i < 3 * n; i++) {
            for (int j = 0; j < n; j++) {
                // 이미 이번 턴에서 같은 덩어리로 묶여 터진 적 있는 칸이면 스킵
                if (visitedPool[ck][i][j]) continue;

                // 미리 만들어둔 다음 뎁스(ck + 1)의 배열에 값만 덮어씌우기
                for (int k = 0; k < 3 * n; k++) {
                    System.arraycopy(grids[ck][k], 0, grids[ck + 1][k], 0, n);
                }

                // 복사된 배열(grids[ck + 1]) 위에서 시뮬레이션을 진행합니다
                int cnt = splash(grids[ck + 1], visitedPool[ck], i, j);
                drop(grids[ck + 1]);
                dfs(ck + 1, cmnt + cnt);
            }
        }
    }

    static int[] dy = {1, 0, -1, 0};
    static int[] dx = {0, 1, 0, -1};

    static int splash(int[][] grid, boolean[][] visited, int cy, int cx) {
        // 직사각형 넓이를 측정하는 건 쉬움
        // 터지는 칸마다 maxY, maxX, minY, minX를 측정하고 (maxY - minY + 1) * (maxX - minX + 1)로 계산 가능
        int maxY = Integer.MIN_VALUE, maxX = Integer.MIN_VALUE;
        int minY = Integer.MAX_VALUE, minX = Integer.MAX_VALUE;

        // bfs로 터질 곳 마킹 및 측정, 추가로 visited를 true 시키기.
        Queue<int[]> q = new LinkedList<>();
        int target = grid[cy][cx];
        int popped = 1;
        visited[cy][cx] = true;
        grid[cy][cx] = -1;
        maxY = Math.max(maxY, cy);
        minY = Math.min(minY, cy);
        maxX = Math.max(maxX, cx);
        minX = Math.min(minX, cx);

        q.add(new int[]{cy, cx});

        while(!q.isEmpty()) {
            int[] cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int ny = cur[0] + dy[i];
                int nx = cur[1] + dx[i];

                if (ny < 2 * n || ny >= 3 * n || nx < 0 || nx >= n) continue;
                if (visited[ny][nx] || grid[ny][nx] != target) continue;

                popped++;
                visited[ny][nx] = true;
                grid[ny][nx] = -1;
                maxY = Math.max(maxY, ny);
                minY = Math.min(minY, ny);
                maxX = Math.max(maxX, nx);
                minX = Math.min(minX, nx);

                q.add(new int[]{ny, nx});
            } 
        }

        // 가장 작은 직사각형 넓이 return
        return (maxY - minY + 1) * (maxX - minX + 1) + popped;
    }

    static void drop(int[][] grid) {
    for (int j = 0; j < n; j++) {
        int writeIdx = 3 * n - 1; // 맨 밑바닥부터 채워 넣을 위치
        
        // 1. 터지지 않은(-1이 아닌) 자동차만 밑에서부터 끌어내림
        for (int readIdx = 3 * n - 1; readIdx >= 0; readIdx--) {
            if (grid[readIdx][j] != -1) {
                grid[writeIdx][j] = grid[readIdx][j];
                writeIdx--;
            }
        }
        
        // 2. 남은 윗부분은 전부 빈 공간(0)으로 초기화 (유령 자동차 방지!)
        while (writeIdx >= 0) {
            grid[writeIdx][j] = 0;
            writeIdx--;
        }
    }
}
}