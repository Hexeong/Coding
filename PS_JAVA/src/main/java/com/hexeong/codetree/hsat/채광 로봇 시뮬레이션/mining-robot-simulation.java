import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {
        // Scanner 대신 BufferedReader 사용 (메모리 및 속도 대폭 개선)
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        // 1단계: 정상적인 이동(오른쪽, 아래)으로 각 칸까지 갈 때의 최대 점수 (dp1)
        int[][] dp1 = new int[n][n];
        dp1[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) dp1[i][0] = dp1[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++) dp1[0][j] = dp1[0][j - 1] + grid[0][j];
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                dp1[i][j] = grid[i][j] + Math.max(dp1[i - 1][j], dp1[i][j - 1]);
            }
        }
        
        // 2단계: 재귀 대신 DP를 사용하여 각 칸에서 정확히 T번 이동할 때의 최대 점수 미리 계산
        int[][] base = new int[n][n];
        // step을 1부터 t까지 늘려가며 바텀업으로 T번 이동 시의 점수(maxForward)를 계산
        for (int step = 1; step <= t; step++) {
            int[][] nextF = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    nextF[i][j] = Integer.MIN_VALUE;
                    // 아래로 이동
                    if (i + 1 < n && base[i + 1][j] != Integer.MIN_VALUE) {
                        nextF[i][j] = Math.max(nextF[i][j], base[i + 1][j] + grid[i + 1][j]);
                    }
                    // 오른쪽으로 이동
                    if (j + 1 < n && base[i][j + 1] != Integer.MIN_VALUE) {
                        nextF[i][j] = Math.max(nextF[i][j], base[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
            base = nextF; // 현재 step까지 계산된 배열을 base로 갱신
        }
        
        // 3단계: 능력 사용 시 얻을 수 있는 점수로 base 초기화 및 dp1과 병합
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (base[i][j] != Integer.MIN_VALUE) {
                    // 지금까지 온 점수 + 앞으로 T번 이동하며 얻을 점수 + 과거로 돌아와 현재 칸을 다시 캔 점수
                    base[i][j] = dp1[i][j] + base[i][j] + grid[i][j];
                }
                // 능력을 아예 안 쓰고 지나간 경우(dp1) 중 최댓값 갱신
                base[i][j] = Math.max(dp1[i][j], base[i][j]);
            }
        }
        
        // 4단계: 이후 이동하면서 누적될 최댓값 갱신 (작성하신 2번 로직과 동일)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    base[i][j] = Math.max(base[i][j], base[i - 1][j] + grid[i][j]);
                }
                if (j > 0) {
                    base[i][j] = Math.max(base[i][j], base[i][j - 1] + grid[i][j]);
                }
            }
        }
        
        // 최종 결과 출력
        System.out.println(base[n - 1][n - 1]);
    }
}