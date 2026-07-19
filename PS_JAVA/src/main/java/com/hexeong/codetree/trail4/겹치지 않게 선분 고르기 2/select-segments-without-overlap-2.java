import java.util.*;

public class Main {

    static int n;
    static int[][] line;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        line = new int[n][2];
        for (int i = 0; i < n; i++) {
            line[i][0] = sc.nextInt();
            line[i][1] = sc.nextInt();
        }

        Arrays.sort(line, (a, b) -> {
            if (a[1] == b[1]) return a[0] - b[0];
            return a[1] - b[1];
        });

        int[] dp = new int[n];
        dp[0] = 0;
        int max = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (line[j][1] < line[i][0]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    max = Math.max(dp[i], max);
                }
        }

        System.out.println(max + 1);
    }
}