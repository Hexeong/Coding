import java.util.*;

public class Main {

    static int n;
    static int[][] in;
    static int[][][] dp;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        in = new int[n][3];
        dp = new int[n][3][3]; // i = 현재 층, j = 현재 층에서 고른 방, k = 1층에서 고른 방
        
        for (int i = 0; i < n; i++) {
            in[i][0] = sc.nextInt();
            in[i][1] = sc.nextInt();
            in[i][2] = sc.nextInt();
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                Arrays.fill(dp[i][j], -1);

        dp[0][0][0] = in[0][0];
        dp[0][1][1] = in[0][1];
        dp[0][2][2] = in[0][2];
        
        for (int i = 1; i < n - 1; i++) {
            for (int k = 0; k < 3; k++) {
                if (dp[i - 1][0][k] != -1) {
                    dp[i][1][k] = Math.max(dp[i][1][k], in[i][1] + dp[i - 1][0][k]);
                    dp[i][2][k] = Math.max(dp[i][2][k], in[i][2] + dp[i - 1][0][k]);
                }
                if (dp[i - 1][1][k] != -1) {
                    dp[i][0][k] = Math.max(dp[i][0][k], in[i][0] + dp[i - 1][1][k]);
                    dp[i][2][k] = Math.max(dp[i][2][k], in[i][2] + dp[i - 1][1][k]);
                }
                if (dp[i - 1][2][k] != -1) {
                    dp[i][0][k] = Math.max(dp[i][0][k], in[i][0] + dp[i - 1][2][k]);
                    dp[i][1][k] = Math.max(dp[i][1][k], in[i][1] + dp[i - 1][2][k]);
                }
            }
        }

        dp[n - 1][1][0] = in[n - 1][1] + Math.max(dp[n - 2][2][0], dp[n - 2][0][0]);
        dp[n - 1][2][0] = in[n - 1][2] + Math.max(dp[n - 2][1][0], dp[n - 2][0][0]);
        dp[n - 1][0][1] = in[n - 1][0] + Math.max(dp[n - 2][2][1], dp[n - 2][1][1]);
        dp[n - 1][2][1] = in[n - 1][2] + Math.max(dp[n - 2][0][1], dp[n - 2][1][1]);
        dp[n - 1][0][2] = in[n - 1][0] + Math.max(dp[n - 2][1][2], dp[n - 2][2][2]);
        dp[n - 1][1][2] = in[n - 1][1] + Math.max(dp[n - 2][0][2], dp[n - 2][2][2]);

        int max = 0;
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                max = Math.max(max, dp[n - 1][j][k]);

        System.out.println(max);
    }
}