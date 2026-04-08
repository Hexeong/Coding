package com.hexeong.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class SWEA_디저트카페 {

    static int[] dy = {1, 1, -1, -1};
    static int[] dx = {1, -1, -1, 1};
    static int result = -1;

    static void solve(int[][] map, int baseY, int baseX, int l1, int l2) {
        HashSet<Integer> set = new HashSet<>();

//        if (baseY == 0 && baseX == 2 && l1 == 1 && l2 == 2)
//            System.out.println();

        int curY = baseY;
        int curX = baseX;
        // 우아래 대각선
        for (int i = 0; i < 4; i++) {
            int baseL = (i % 2 == 0 ? l1 : l2);
            for (int l = 0; l < baseL; l++) {
                if (set.contains(map[curY + l * dy[i]][curX + l * dx[i]]))
                    return;
                set.add(map[curY + l * dy[i]][curX + l * dx[i]]);
            }
            curY += dy[i] * baseL;
            curX += dx[i] * baseL;
        }

        result = Math.max(result, set.size());
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int t = 1; t <= T; t++) {
            int N = Integer.parseInt(br.readLine()); // <= 20

            int[][] map = new int[N][N];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            result = -1;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int l1 = 1; i + l1 < N && j + l1 < N; l1++) {
                        for (int l2 = 1; i + l2 < N && j - l2 > -1; l2++) {
                            if (i + l1 + l2 >= N) continue;

                            solve(map, i, j, l1, l2);
                        }
                    }
                }
            }

            System.out.println("#" + t + " " + result);
        }
    }
}
