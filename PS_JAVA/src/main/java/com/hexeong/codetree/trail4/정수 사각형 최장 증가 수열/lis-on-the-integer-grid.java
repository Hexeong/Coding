import java.util.*;

public class Main {

    static int n;
    static int[][] grid;
    static int[][] dp;

    static int[] dy = {0, 1, 0 , -1};
    static int[] dx = {1, 0, -1, 0};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        grid = new int[n][n];
        dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
            for (int j = 0; j < n; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        // Please write your code here.

        // 메모이제이션? 
        // dp[i][j]는 i 행, j열에서 얼마나 더 멀리 갈 수 있는지를 업데이트
        // 만약 dp[i][j] 칸이 INF가 아니라면 이전 칸을 dp[i][j] + 1로 업데이트

        int maxV = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = backT(i, j);
                maxV = Math.max(maxV, cnt);
                
                // for (int y = 0; y < n; y++) {
                //     for (int x = 0; x < n; x++)
                //         System.out.print(dp[y][x] + " ");
                //     System.out.println();
                // }
            }
        }

        System.out.println(maxV);
    }

    private static int backT(int cy, int cx) {
        int maxV = 0;
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (grid[ny][nx] <= grid[cy][cx]) continue;

            if (dp[ny][nx] == -1) {
                maxV = Math.max(maxV, backT(ny, nx));
            } else {
                maxV = Math.max(maxV, dp[ny][nx]);
            }
        }
        dp[cy][cx] = maxV + 1;

        return dp[cy][cx];
    }
}