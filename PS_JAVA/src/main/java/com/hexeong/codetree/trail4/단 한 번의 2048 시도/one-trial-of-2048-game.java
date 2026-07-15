import java.util.*;
import java.io.*;

public class Main {

    static int[] dy = {0, 0, -1, 1};
    static int[] dx = {-1, 1, 0, 0};

    public static void main(String[] args) throws IOException {
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int[][] grid = new int[4][4];

        for (int i = 0; i < 4; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 4; j++)
                grid[i][j] = Integer.parseInt(st.nextToken());
        }

        char m = br.readLine().charAt(0);
        if (m == 'L') {
            moveLeftOrRight(grid, true);
        }
        if (m == 'R') {
            moveLeftOrRight(grid, false);
        }
        if (m == 'U') {
            moveUpOrDown(grid, true);
        }
        if (m == 'D') {
            moveUpOrDown(grid, false);
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                System.out.print(grid[i][j] + " ");
            System.out.println();
        }
    }

    private static void moveUpOrDown(int[][] grid, boolean isUp) {
        boolean[][] isCombined = new boolean[4][4];
        int[][] res = new int[4][4];

        if (isUp) {
            for (int j = 0; j < 4; j++) {
                int cur_i = 0;
                int last = -1;
                for (int i = 0; i < 4; i++) {
                    if (grid[i][j] == 0) continue;

                    if (last == -1) {
                        last = grid[i][j];
                    } else {
                        if (last == grid[i][j]) {
                            res[cur_i][j] = last << 1;
                            cur_i++;
                            last = -1;
                        } else {
                            res[cur_i][j] = last;
                            cur_i++;
                            last = grid[i][j];
                        }
                    }
                }

                if (last != -1)
                    res[cur_i][j] = last;
            }
        } else {
            for (int j = 0; j < 4; j++) {
                int cur_i = 3;
                int last = -1;
                for (int i = 3; i > -1; i--) {
                    if (grid[i][j] == 0) continue;

                    if (last == -1) {
                        last = grid[i][j];
                    } else {
                        if (last == grid[i][j]) {
                            res[cur_i][j] = last << 1;
                            cur_i--;
                            last = -1;
                        } else {
                            res[cur_i][j] = last;
                            cur_i--;
                            last = grid[i][j];
                        }
                    }
                }

                if (last != -1)
                    res[cur_i][j] = last;
            }
        }

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                grid[i][j] = res[i][j];
    }

    private static void moveLeftOrRight(int[][] grid, boolean isLeft) {
        boolean[][] isCombined = new boolean[4][4];
        int[][] res = new int[4][4];

        if (isLeft) {
            for (int i = 0; i < 4; i++) {
                int cur_j = 0;
                int last = -1;
                for (int j = 0; j < 4; j++) {
                    if (grid[i][j] == 0) continue;

                    if (last == -1) {
                        last = grid[i][j];
                    } else {
                        if (last == grid[i][j]) {
                            res[i][cur_j] = last << 1;
                            cur_j++;
                            last = -1;
                        } else {
                            res[i][cur_j] = last;
                            cur_j++;
                            last = grid[i][j];
                        }
                    }
                }

                if (last != -1)
                    res[i][cur_j] = last;
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int cur_j = 3;
                int last = -1;
                for (int j = 3; j > -1; j--) {
                    if (grid[i][j] == 0) continue;

                    if (last == -1) {
                        last = grid[i][j];
                    } else {
                        if (last == grid[i][j]) {
                            res[i][cur_j] = last << 1;
                            cur_j--;
                            last = -1;
                        } else {
                            res[i][cur_j] = last;
                            cur_j--;
                            last = grid[i][j];
                        }
                    }
                }

                if (last != -1)
                    res[i][cur_j] = last;
            }
        }

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                grid[i][j] = res[i][j];
    }
}