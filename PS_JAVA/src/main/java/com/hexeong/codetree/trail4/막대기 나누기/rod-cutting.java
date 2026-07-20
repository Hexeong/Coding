import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] price = new int[n + 1];
        for (int i = 1; i <= n; i++)
            price[i] = sc.nextInt();
        
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                dp[i] = Math.max(dp[i], dp[i - k] + price[k]);
            }
        }

        // for (int i = 0; i <= n; i++)
        //     System.out.print(dp[i] + " ");
        // System.out.println();

        System.out.println(dp[n]);
    }
}