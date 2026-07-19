import java.util.*;

public class Main {

    static int[][] dp;

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] in = new int[n];
        for (int i = 0; i < n; i++)
            in[i] = sc.nextInt();
        
        // 1. 모든 원소는 그 자체로 길이 1인 수열이 될 수 있으므로 1로 초기화합니다.
        dp = new int[n][2];
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }

        // 2. DP 탐색 진행
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                
                // 증가하는 경우
                if (in[j] < in[i]) {
                    // 계속 증가하는 경로만 연장할 수 있습니다.
                    dp[i][0] = Math.max(dp[i][0], dp[j][0] + 1);
                } 
                // 감소하는 경우
                else if (in[j] > in[i]) {
                    // 1. j까지 증가만 하다가 i부터 처음 꺾이는 경우 (dp[j][0] + 1)
                    // 2. 이미 j에서부터 감소 중이었던 경로를 계속 잇는 경우 (dp[j][1] + 1)
                    // 둘 중 더 큰 값을 선택합니다.
                    dp[i][1] = Math.max(dp[i][1], Math.max(dp[j][0], dp[j][1]) + 1);
                }
            }
        }

        // 3. DP 배열 전체에서 가장 큰 값이 정답이 됩니다.
        int maxV = 0;
        for (int i = 0; i < n; i++) {
            maxV = Math.max(maxV, Math.max(dp[i][0], dp[i][1]));
        }

        System.out.println(maxV);
    }
}