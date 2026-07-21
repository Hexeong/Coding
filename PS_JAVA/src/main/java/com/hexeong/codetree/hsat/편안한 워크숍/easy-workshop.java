import java.util.*;
import java.io.*;

public class Main {

    static int[][][] mem;

    static int n = 0, k = 0, min = Integer.MAX_VALUE;
    static int[][] grid;

    public static void main(String[] args) throws IOException {
        // Please write your code here.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        grid = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0 ; j < n; j++) 
                grid[i][j] = Integer.parseInt(st.nextToken());
        }

        mem = new int[n][n][k + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                Arrays.fill(mem[i][j], -1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                min = Math.min(min, dfs(i, j, 1));
            }
        
        System.out.println(min == Integer.MAX_VALUE ? -1 : min);
    }

    static int[] dy = {1, 0, -1, 0};
    static int[] dx = {0, 1, 0, -1};

    static int dfs(int cy, int cx, int len) {
        if (len == k) {
            return 0;
        }

        if (mem[cy][cx][len] != -1) {
            return mem[cy][cx][len];
        }

        int cmin = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (grid[cy][cx] >= grid[ny][nx]) continue;

            int diff = grid[ny][nx] - grid[cy][cx];

            int maxDiffOnThisPath = Math.max(diff, dfs(ny, nx, len + 1));
            cmin = Math.min(cmin, maxDiffOnThisPath);
        }
        return mem[cy][cx][len] = cmin;
    }
}

