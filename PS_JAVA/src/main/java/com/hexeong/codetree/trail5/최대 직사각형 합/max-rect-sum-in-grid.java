import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        // Please write your code here.
        // N^4 == 8,100,000,000

        int[][] areaSum = new int[n][n];
        areaSum[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            areaSum[i][0] = areaSum[i - 1][0] + grid[i][0];
            areaSum[0][i] = areaSum[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++) {
                areaSum[i][j] = grid[i][j] + areaSum[i - 1][j] + areaSum[i][j - 1] - areaSum[i - 1][j - 1];
            }
        
        int maxSum = Integer.MIN_VALUE;

        // 1. 시작 행(r1)과 끝 행(r2)을 고정 (O(N^2))
        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1; r2 < n; r2++) {
                
                // 이전 열들까지의 누적합 중 최소값을 추적할 변수
                // 처음에는 아무 열도 선택하지 않은 상태인 0으로 시작합니다.
                int minPrefix = 0; 
                
                // 2. 열(c)을 순회하며 1차원적으로 탐색 (O(N))
                for (int c = 0; c < n; c++) {
                    
                    // r1행부터 r2행까지, 0열부터 c열까지의 직사각형 합 구하기
                    int currentPrefix = areaSum[r2][c];
                    if (r1 > 0) {
                        currentPrefix -= areaSum[r1 - 1][c];
                    }
                    
                    // 정답 갱신: (현재 누적합 - 역대 최소 누적합)
                    maxSum = Math.max(maxSum, currentPrefix - minPrefix);
                    
                    // 다음 열을 위해 최소 누적합 갱신
                    minPrefix = Math.min(minPrefix, currentPrefix);
                }
            }
        }

        System.out.println(maxSum);
    }
}