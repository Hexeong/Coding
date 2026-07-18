import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // dp[i][j] = 노드 i개가 있고, 루트 노드가 j일 때 가능한 BST 개수
        // dp[i][j] = (dp[i - 1][1] + ... + dp[i - 1][j - 1])
        //              * (dp[n - i - 1][j + 1] + ... + dp[n - i - 1][n])

        // 노드가 0개일 때(공백 트리)와 1개일 때는 모양이 1가지입니다.
        int[] dp = new int[20];
        dp[0] = 1;
        dp[1] = 1;

        // 노드 개수가 i개일 때 (2부터 N까지 구하기)
        for (int i = 2; i <= n; i++) {
            // 루트 노드를 j로 지정할 때 (1부터 i까지 가능)
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        System.out.println(dp[n]);
    }
}