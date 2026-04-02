package com.hexeong.codetree;

import java.util.*;

public class CDT_겹치지않는두직사각형 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        // Please write your code here.

        int[][] area_sum = new int[n][m];
        area_sum[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            area_sum[i][0] = area_sum[i - 1][0] + grid[i][0];
        for (int i = 1; i < m; i++)
            area_sum[0][i] = area_sum[0][i - 1] + grid[0][i];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                area_sum[i][j] = grid[i][j] + area_sum[i][j - 1] + area_sum[i - 1][j] - area_sum[i - 1][j - 1];
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         System.out.print(area_sum[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        int max_v = -25000;
        // 브루트포스 시작
        for (int ay = 0; ay < n; ay++) {
            for (int ax = 0; ax < m; ax++) {
                for (int ayl = 1; ay + ayl <= n; ayl++) {
                    for (int axl = 1; ax + axl <= m; axl++) { // 직사각형 a에 대한 순회

                        for (int by = 0; by < n; by++) {
                            for (int bx = 0; bx < m; bx++) {
                                if (ay <= by && by < ay + ayl && ax <= bx && bx < ax + axl) {
                                    continue;
                                }

                                for (int byl = 1; by + byl <= n; byl++) {
                                    for (int bxl = 1; bx + bxl <= m; bxl++) { // 직사각형 b에 대한 순회
                                        if (isDuplicated(ay, ax, ayl, axl, by, bx, byl, bxl)) {
                                            continue;
                                        }

                                        int a = area_sum[ay + ayl - 1][ax + axl - 1]
                                                - (ay != 0 ? area_sum[ay - 1][ax + axl - 1] : 0)
                                                - (ax != 0 ? area_sum[ay + ayl - 1][ax - 1] : 0)
                                                + ((ay == 0 || ax == 0) ? 0 : area_sum[ay - 1][ax - 1]);

                                        int b = area_sum[by + byl - 1][bx + bxl - 1]
                                                - (by != 0 ? area_sum[by - 1][bx + bxl - 1] : 0)
                                                - (bx != 0 ? area_sum[by + byl - 1][bx - 1] : 0)
                                                + ((by == 0 || bx == 0) ? 0 : area_sum[by - 1][bx - 1]);

                                        if (max_v < a + b) {
                                            // System.out.println("---------------");
                                            // System.out.print(ay + " : " + ax + " : " + ayl + " : " + axl + " / ");
                                            // System.out.println(by + " : " + bx + " : " + byl + " : " + bxl);
                                            // System.out.println(a + " : " + b);
                                            max_v = a + b;
                                        }

                                    }
                                }
                            }
                        }

                    }
                }
            }
        }

        System.out.println(max_v);
    }

    public static boolean isDuplicated(int ay, int ax, int ayl, int axl, int by, int bx, int byl, int bxl) {
        int ay_end = ay + ayl - 1;
        int ax_end = ax + axl - 1;
        int by_end = by + byl - 1;
        int bx_end = bx + bxl - 1;

        // 겹치지 않는 조건 4가지
        // A가 B의 왼쪽에 있음: ax_end < bx
        // A가 B의 오른쪽에 있음: ax > bx_end
        // A가 B의 위쪽에 있음: ay_end < by
        // A가 B의 아래쪽에 있음: ay > by_end

        // 위 4가지 조건 중 하나라도 만족하면 겹치지 않음(false)
        if (ax_end < bx || ax > bx_end || ay_end < by || ay > by_end) {
            return false;
        }
        return true;
    }
}