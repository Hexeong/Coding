import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++)
                grid[i][j] = Integer.parseInt(st.nextToken());
        }

        for (int t = 0; t < m; t++) {
            int target_j = Integer.parseInt(br.readLine()) - 1;

            int target_i = -1;
            for (int i = 0; i < n; i++) {
                if (grid[i][target_j] != 0) {
                    target_i = i;
                    break;
                } 
            }

            if (target_i == -1)
                continue;

            // 지우기 작업
            int len = grid[target_i][target_j];
            int rj = target_j;
            int lj = target_j;
            for (int k = 0; k < len; k++) {
                // 아래 지우기 작업
                if (target_i + k < n)
                    grid[target_i + k][target_j] = 0;

                // 양 옆 지우기 작업
                int nj = target_j + k;
                if (nj < n) {
                    grid[target_i][nj] = 0;
                    rj = nj;
                } 
                nj = target_j - k;
                if (nj > -1) {
                    grid[target_i][nj] = 0;
                    lj = nj;
                }
            }

            for (int j = lj; j <= rj; j++) {
                for (int i = target_i; i > 0; i--) {
                    grid[i][j] = grid[i - 1][j];
                }
                grid[0][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                System.out.print(grid[i][j] + " ");
            System.out.println();
        }
    }
}