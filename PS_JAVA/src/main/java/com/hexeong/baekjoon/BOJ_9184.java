package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_9184 {
    public static int[][][] mem = new int[101][101][101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        Arrays.stream(mem).forEach(x -> Arrays.stream(x).forEach(y -> Arrays.fill(y, -1)));

        while (a != -1 || b != -1 || c != -1) {

            System.out.println("w(" + a + ", " + b + ", " + c + ") = " + solve(a, b, c));
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
        }
    }

    public static int solve(int a, int b, int c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            mem[a + 50][b + 50][c + 50] = 1;
            return 1;
        }

        if (a > 20 || b > 20 || c > 20) {
            if (mem[70][70][70] != -1)
                return mem[70][70][70];
            int m = solve(20, 20, 20);
            mem[70][70][70] = m;
            return m;
        }

        if (a < b && b < c) {
            if (mem[a + 50][b + 50][c - 1 + 50] != -1 &&  mem[a + 50][b - 1 + 50][c - 1 + 50] != -1 && mem[a + 50][b - 1 + 50][c + 50] != -1)
                return mem[a + 50][b + 50][c - 1 + 50] + mem[a + 50][b - 1 + 50][c - 1 + 50] - mem[a + 50][b - 1 + 50][c + 50];
            int m1 = solve(a, b, c - 1);
            int m2 = solve(a, b - 1, c - 1);
            int m3 = solve(a, b - 1, c);
            mem[a + 50][b + 50][c - 1 + 50] = m1;
            mem[a + 50][b - 1 + 50][c - 1 + 50] = m2;
            mem[a + 50][b - 1+ 50][c + 50] = m3;
            return m1 + m2 - m3;
        }


        if (mem[a - 1 + 50][b + 50][c + 50] != -1
                && mem[a - 1 + 50][b - 1 + 50][c + 50] != -1
                && mem[a - 1 + 50][b + 50][c - 1 + 50] != -1
                && mem[a - 1 + 50][b - 1 + 50][c - 1 + 50] != -1) {

            return mem[a - 1 + 50][b + 50][c + 50]
                    + mem[a - 1 + 50][b - 1 + 50][c + 50]
                    + mem[a - 1 + 50][b + 50][c - 1 + 50]
                    - mem[a - 1 + 50][b - 1 + 50][c - 1 + 50];
        }
        int m1 = solve(a-1, b, c);
        int m2 = solve(a-1, b-1, c);
        int m3 = solve(a-1, b, c-1);
        int m4 = solve(a-1, b-1, c-1);
        mem[a - 1 + 50][b + 50][c + 50] = m1;
        mem[a - 1 + 50][b - 1 + 50][c + 50] = m2;
        mem[a - 1 + 50][b + 50][c - 1 + 50] = m3;
        mem[a - 1 + 50][b - 1 + 50][c - 1 + 50] = m4;
        return m1 + m2 + m3 - m4;
    }
}
