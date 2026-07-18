import java.util.*;

public class Main {

    static long[] dp;

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long mod = 1000000007;
        dp = new long[1001];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 7;
        for (int i = 3; i <= n; i++)
            dp[i] = (dp[i - 1] * 3 % mod + dp[i - 2] % mod - dp[i - 3] % mod + mod) % mod;

        System.out.println(dp[n]);
    }
}