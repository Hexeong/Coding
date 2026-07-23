import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();

        int n = a.length();
        int m = b.length();

        // dp[i][j] = 문자열 A의 i번째 길이까지와 문자열 B의 j번째 길이까지의 편집 거리
        int[][] dp = new int[n + 1][m + 1];

        // 1. 초기화: 빈 문자열과의 비교
        // A의 i번째 길이에서 빈 문자열이 되려면 i번 삭제해야 함
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i; 
        }
        // B의 j번째 길이에서 빈 문자열이 되려면 j번 삭제(또는 A에서 j번 삽입)해야 함
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j; 
        }

        // 2. DP 테이블 채우기
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // 문자열 인덱스는 0부터 시작하므로 i-1, j-1로 비교
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    // 문자가 같으면 이전 상태의 값을 그대로 가져옴 (비용 추가 없음)
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 문자가 다르면 삽입, 삭제, 교체 중 최소 비용 + 1
                    dp[i][j] = Math.min(
                        dp[i - 1][j - 1], // 교체
                        Math.min(
                            dp[i - 1][j], // 삭제
                            dp[i][j - 1]  // 삽입
                        )
                    ) + 1;
                }
            }
        }

        // 결과 출력
        System.out.println(dp[n][m]);
    }
}