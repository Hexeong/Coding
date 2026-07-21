import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] in = new int[n];
        for (int i = 0; i < n; i++)
            in[i] = sc.nextInt();

        // 1. DP 배열 초기화: 모든 칸을 매우 작은 값으로 세팅
        int[][] dp = new int[n][k + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1000000000);
        }

        // 2. 첫 번째 원소(i = 0) 처리
        if (in[0] >= 0) {
            dp[0][0] = in[0]; // 양수면 음수 0개 사용
        } else {
            dp[0][1] = in[0]; // 음수면 음수 1개 사용
        }

        // 3. DP 진행
        for (int i = 1; i < n; i++) {
            if (in[i] >= 0) {
                // [양수일 때] 
                // 1) 완전히 새로 시작하는 경우 (음수 0개)
                dp[i][0] = Math.max(dp[i - 1][0] + in[i], in[i]);
                
                // 2) 이전 합에 이어 붙이는 경우 (j: 1 ~ K)
                for (int j = 1; j <= k; j++) {
                    dp[i][j] = Math.max(dp[i - 1][j] + in[i], dp[i][j]); 
                }
            } else {
                // [음수일 때]
                // 1) 완전히 새로 시작하는 경우 (방금 뽑은 음수 1개가 됨)
                dp[i][1] = Math.max(dp[i - 1][0] + in[i], in[i]);
                
                // 2) 이전 합에 이어 붙이는 경우 (j: 1 ~ K)
                // 음수를 하나 추가했으므로, 이전 단계의 j-1 상태에서 가져옵니다.
                for (int j = 1; j <= k; j++) {
                    dp[i][j] = Math.max(dp[i - 1][j - 1] + in[i], dp[i][j]);
                }
            }
        }

        // 4. 정답 도출: dp 배열 전체에서 가장 큰 값을 찾기
        int max = -1000000000;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                max = Math.max(max, dp[i][j]);
                // System.out.print(dp[i][j] + " ");
            }
            // System.out.println();
        }
        System.out.println(max);
    }
}