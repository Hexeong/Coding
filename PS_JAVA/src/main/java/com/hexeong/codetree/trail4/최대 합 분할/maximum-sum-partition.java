import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] val = new int[n];
        for(int i = 0; i < n; i++) {
            val[i] = sc.nextInt();
        }

        int offset = 100000;
        int[] dp = new int[200001];
        
        // 도달 불가능한 상태는 -1로 초기화
        Arrays.fill(dp, -1);
        
        // 아무 숫자도 고르지 않았을 때: 차이는 0, A의 합도 0
        dp[offset] = 0; 

        for(int i = 0; i < n; i++) {
            int x = val[i];
            
            // 현재 숫자를 배치한 결과를 담을 임시 배열
            int[] next_dp = new int[200001];
            Arrays.fill(next_dp, -1);

            for(int j = 0; j <= 200000; j++) {
                if(dp[j] == -1) continue; // 도달할 수 없는 상태는 패스

                // 1. C에 넣기 (차이 그대로)
                next_dp[j] = Math.max(next_dp[j], dp[j]);

                // 2. A에 넣기 (차이 + x, A의 합 + x)
                if(j + x <= 200000) {
                    next_dp[j + x] = Math.max(next_dp[j + x], dp[j] + x);
                }

                // 3. B에 넣기 (차이 - x, A의 합 유지)
                if(j - x >= 0) {
                    next_dp[j - x] = Math.max(next_dp[j - x], dp[j]);
                }
            }
            // 갱신된 상태를 원본 dp에 덮어씌움
            dp = next_dp;
        }

        // 최종적으로 A와 B의 합의 차이가 0(즉, offset)일 때의 A의 합 최댓값 출력
        System.out.println(dp[offset]);
    }
}