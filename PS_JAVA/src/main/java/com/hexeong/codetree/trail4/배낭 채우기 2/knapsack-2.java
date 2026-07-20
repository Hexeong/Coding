import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] jewel = new int[n][2];

        for (int i = 0; i < n; i++) {
            jewel[i][0] = sc.nextInt();
            jewel[i][1] = sc.nextInt();
        }

        int[] dp = new int[10001]; // index는 무게
        for (int i = 0; i < n; i++) { // jewel 순회
            for (int k = jewel[i][0]; k <= m; k++) {
                dp[k] = Math.max(dp[k], dp[k - jewel[i][0]] + jewel[i][1]);
            }
        }

        // for (int i = 0; i <= m; i++)
        //     System.out.print(dp[i] + " ");
        // System.out.println();

        System.out.println(dp[m]);
    }
}