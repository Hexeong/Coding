import java.util.*;

public class Main {

    static int N, K;
    static int[][] grid;
    static int[][][][] mem; 
    // mem[i][j][d][k] = 인접한 높이의 차들 간 최댓값
    // i = 현재 행 idx
    // j = 현재 열 idx
    // d = 현재 위치로 넘어온 방향
    // k = 현재까지 등산로의 길이

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        grid = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                grid[i][j] = sc.nextInt();

        mem = new int[N][N][4][K + 1];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int d = 0; d < 4; d++) 
                    Arrays.fill(mem[i][j][d], -1);

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int d = 0; d < 4; d++)
                    min = Math.min(min, dfs(i, j, d, 0));

        if (min == Integer.MAX_VALUE)
            System.out.println(-1);
        else
            System.out.println(min);
    }

    static int[] dy = {1, 0 ,-1, 0};
    static int[] dx = {0, 1, 0, -1};

    static int dfs(int cy, int cx, int cd, int ck) {
        if (ck == K - 1) return -1;
        if (mem[cy][cx][cd][ck] != -1) return mem[cy][cx][cd][ck];

        int cnt = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            if ((cd + 2) % 4 == i) continue;

            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (grid[ny][nx] <= grid[cy][cx]) continue;

            int res = dfs(ny, nx, i, ck + 1);
            if (res == Integer.MAX_VALUE) continue;

            res = Math.max(grid[ny][nx] - grid[cy][cx], res);
            cnt = Math.min(cnt, res);
        }

        return mem[cy][cx][cd][ck] = cnt;
    }
}