import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);
        int[] dp = new int[10001];

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] info = new int[n][2];
        for (int i = 0; i < n; i++) {
            info[i][0] = sc.nextInt(); // 무게
            info[i][1] = sc.nextInt(); // 가치
        }

        for (int i = 0; i < n; i++) {
            for (int k = m; k >= info[i][0]; k--) {
                dp[k] = Math.max(dp[k], dp[k - info[i][0]] + info[i][1]);
            }
        }

        System.out.println(dp[m]);
    }
}