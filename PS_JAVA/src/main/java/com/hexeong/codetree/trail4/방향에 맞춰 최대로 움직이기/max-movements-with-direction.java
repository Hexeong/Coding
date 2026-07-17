import java.util.*;
import java.io.*;

public class Main {

    static int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dx = {0, 1, 1, 1, 0, -1, -1, -1};

    static int maxV = 0;

    public static void main(String[] args) throws IOException {
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] decision = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                decision[i][j] = Integer.parseInt(st.nextToken()) - 1;
            }
        }


        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken()) - 1;
        int c = Integer.parseInt(st.nextToken()) - 1;

        backt(grid, decision, r, c, 0, n);

        System.out.println(maxV);
    }

    private static void backt(int[][] grid, int[][] decision, int cur_y, int cur_x, int cnt, int n) {
        if (cnt > maxV)
            maxV = cnt;

        int k = 1;
        while (true) {
            int ny = cur_y + dy[decision[cur_y][cur_x]] * k;
            int nx = cur_x + dx[decision[cur_y][cur_x]] * k;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;

            k++;
            if (grid[ny][nx] < grid[cur_y][cur_x]) continue;

            backt(grid, decision, ny, nx, cnt + 1, n);
        }
    }
}