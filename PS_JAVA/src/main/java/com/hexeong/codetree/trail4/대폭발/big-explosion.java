import java.util.*;
import java.io.*;

public class Main {

    static int[] dy = {1, 0, -1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken()) - 1;
        int c = Integer.parseInt(st.nextToken()) - 1;

        boolean[][] grid = new boolean[n][n];
        grid[r][c] = true;

        for (int t = 1; t <= m; t++) {
            int len = 1 << (t - 1);

            boolean[][] tmp = new boolean[n][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (!grid[i][j]) continue;
                    
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k] * len;
                        int nx = j + dx[k] * len;

                        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

                        tmp[ny][nx] = true;
                    }
                }
            }

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (tmp[i][j])
                        grid[i][j] = true;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    cnt++;

        System.out.println(cnt);
    }
}