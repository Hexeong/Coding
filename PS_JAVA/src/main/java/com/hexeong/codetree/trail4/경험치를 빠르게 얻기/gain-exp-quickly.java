import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        // Please write your code here.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        // 8MB

        int[][] exp = new int[n][2];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            exp[i][0] = Integer.parseInt(st.nextToken());
            exp[i][1] = Integer.parseInt(st.nextToken());
        }

        int maxTime = 10000;
        int[] dp = new int[maxTime + 1];
        Arrays.fill(dp, -1); // 도달 불가능한 상태
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int e = exp[i][0];
            int time = exp[i][1];

            // 시간을 뒤에서부터 앞으로 순회 (중복 사용 방지)
            for (int t = maxTime; t >= time; t--) {
                if (dp[t - time] != -1) {
                    dp[t] = Math.max(dp[t], dp[t - time] + e);
                }
            }
        }

        // M 이상의 경험치를 얻을 수 있는 최소 시간 찾기
        int minTime = -1;
        for (int t = 0; t <= maxTime; t++) {
            if (dp[t] >= m) { // m은 목표 경험치
                minTime = t;
                break;
            }
        }
        System.out.println(minTime);
    }
}