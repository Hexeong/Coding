import java.util.*;

public class Main {
    static int n;
    static int[][] grid;
    // dp[x][y][L] : (x, y)에서 시작해 경로의 모든 값이 L 이상일 때, 도착점까지 가는 경로 중 '최댓값들의 최솟값'
    static int[][][] dp; 
    static int[] dx = {0, 1}; // 우, 하 (문제 조건)
    static int[] dy = {1, 0};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        grid = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = sc.nextInt();
            }
        }

        // 주어지는 정수가 1~100 이므로 하한선 L도 1~100
        dp = new int[n][n][101];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        int minDifference = Integer.MAX_VALUE;

        // 가능한 최솟값(L)을 1부터 100까지 고정해두고 탐색
        for (int L = 1; L <= 100; L++) {
            int maxVal = backT(0, 0, L);
            
            // 유효한 경로가 존재한다면 차이의 최솟값 갱신
            if (maxVal != Integer.MAX_VALUE) {
                minDifference = Math.min(minDifference, maxVal - L);
            }
        }

        System.out.println(minDifference);
    }

    // DFS + Memoization (Top-down DP)
    static int backT(int x, int y, int L) {
        // 현재 칸의 값이 고정한 하한선 L보다 작다면 유효하지 않은 경로
        if (grid[x][y] < L) {
            return Integer.MAX_VALUE;
        }

        // 목적지에 도달한 경우 현재 칸의 값을 반환 (이 경로의 최댓값 후보 중 하나)
        if (x == n - 1 && y == n - 1) {
            return grid[x][y];
        }

        // 이미 계산된 적이 있다면 메모이제이션된 값 반환
        if (dp[x][y][L] != -1) {
            return dp[x][y][L];
        }

        int minOfMaxes = Integer.MAX_VALUE;

        // 오른쪽, 아래로 이동
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < n && ny < n) {
                int nextMax = backT(nx, ny, L);
                if (nextMax != Integer.MAX_VALUE) {
                    minOfMaxes = Math.min(minOfMaxes, nextMax);
                }
            }
        }

        // 목적지까지 갈 수 없는 경우
        if (minOfMaxes == Integer.MAX_VALUE) {
            return dp[x][y][L] = Integer.MAX_VALUE;
        }

        // 현재 칸의 값과 이후 경로의 최댓값 중 더 큰 값이 이 경로의 최종 최댓값이 됨
        return dp[x][y][L] = Math.max(grid[x][y], minOfMaxes);
    }
}