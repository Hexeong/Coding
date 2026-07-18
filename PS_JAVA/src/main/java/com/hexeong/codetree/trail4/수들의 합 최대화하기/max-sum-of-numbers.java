import java.util.*;

public class Main {

    static int n;
    static int maxV = 0;
    static int[][] grid;
    static boolean[][] color;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        grid = new int[n][n];
        color = new boolean[n][n];

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();

        backT(0, 0);

        System.out.println(maxV);
    }


    private static void backT(int cnt, int cur_j) {
        if (cur_j == n) {
            maxV = Math.max(maxV, cnt);
            return;
        }

        for (int i = 0; i < n; i++) {
            boolean flag = false;

            for (int j = 0; j < cur_j; j++)
                if (color[i][j]) {
                    flag = true;
                    break;
                }

            if (flag)
                continue;

            color[i][cur_j] = true;
            backT(cnt + grid[i][cur_j], cur_j + 1);
            color[i][cur_j] = false;
        }
    }
}