import java.util.Scanner;
import java.util.*;

public class Main {

    static int[] dy = {1, 1, 1, 0, 0, -1, -1, -1};
    static int[] dx = {1, 0, -1, 1, -1, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Stack<Integer>[][] grid = new Stack[n][n];
        int[] num_idx = new int[n * n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = new Stack<>();
                grid[i][j].add(sc.nextInt());
                num_idx[grid[i][j].peek()] = i * n + j;
            }
        }
        int[] moves = new int[m];
        for (int i = 0; i < m; i++) {
            moves[i] = sc.nextInt();
        }
        // Please write your code here.

        for (int mv : moves) {
            int y = (num_idx[mv]) / n;
            int x = (num_idx[mv]) % n;

            int max_val = 0;
            int max_ny = -1;
            int max_nx = -1;
            for (int i = 0; i < 8; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n || grid[ny][nx].isEmpty()) continue;
                if (grid[ny][nx].isEmpty()) continue;

                int currentCellMax = 0;
                for (int num : grid[ny][nx]) {
                    currentCellMax = Math.max(currentCellMax, num);
                }

                // 여태까지 찾은 최댓값보다 더 큰 숫자가 있다면 위치 갱신
                if (currentCellMax > max_val) {
                    max_val = currentCellMax;
                    max_ny = ny;
                    max_nx = nx;
                }
            }

            // 주변에 숫자가 하나도 없으면 그냥 지나치기
            if ((max_ny == -1 && max_nx == -1) || grid[max_ny][max_nx].isEmpty()) {
                continue;
            }

            Stack<Integer> st = new Stack<>();
            while (!grid[y][x].isEmpty() && grid[y][x].peek() != mv) {
                st.add(grid[y][x].pop());
            }
            // mv 값까지 이동 완료
            st.add(grid[y][x].pop());

            while(!st.isEmpty()) {
                int movingNum = st.pop();
                grid[max_ny][max_nx].add(movingNum);
                num_idx[movingNum] = max_ny * n + max_nx;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j].isEmpty())
                    System.out.println("None");
                else {
                    while(!grid[i][j].isEmpty()) {
                        System.out.print(grid[i][j].pop() + " ");
                    }
                    System.out.println();
                }
            }
        }
    }   
}