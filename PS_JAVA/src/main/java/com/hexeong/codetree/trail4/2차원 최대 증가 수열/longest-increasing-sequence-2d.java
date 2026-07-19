import java.util.*;

public class Main {

    static int n, m;
    static int[][] grid;
    static int[][] dp;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        grid = new int[n][m];
        dp = new int[n][m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = sc.nextInt();

        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);
        dp[0][0] = 0;

        int maxV = 0;
        for (int y = 1; y < n; y++) {
            for (int x = 1; x < m; x++) {

                for (int i = 0; i < y; i++) {
                    for (int j = 0; j < x; j++) {
                        if (dp[i][j] == -1) continue;

                        if (grid[i][j] < grid[y][x]) {
                            dp[y][x] = Math.max(dp[y][x], dp[i][j] + 1);
                            maxV = Math.max(maxV, dp[y][x]);
                        }
                    }
                }
            }
        }

        System.out.println(maxV + 1);
    }
}