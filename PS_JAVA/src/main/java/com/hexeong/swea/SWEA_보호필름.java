package com.hexeong.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA_보호필름 {

    static int result = -1;

    // TODO:: 보호필름 검사 메서드 필요 - O(D * W) <= 13 * 20 = 260
    // A가 true, B가 false
    static boolean isPassed(boolean[][] map, int[] medicineList, int K, int D, int W) {
        if (K == 1) return true;

        for (int w = 0; w < W; w++) {

            int cnt = 1;
            boolean passed = false;
            boolean prevType = getActualType(map, medicineList, 0, w);

            for (int d = 1; d < D; d++) {
                boolean curType = getActualType(map, medicineList, d, w);

                if (curType == prevType) {
                    cnt++;
                } else {
                    cnt = 1;
                    prevType = curType;
                }

                if (cnt >= K) {
                    passed = true;
                    break; // 이번 열 합격, 다음 열로
                }
            }

            if (!passed) return false;
        }
        return true;
    }

    // 약품 적용 여부에 따른 실제 셀의 값을 반환 (A: false, B: true)
    static boolean getActualType(boolean[][] map, int[] medicineList, int r, int c) {
        if (medicineList[r] == 1) return false; // A약품 투입
        if (medicineList[r] == 2) return true;  // B약품 투입
        return map[r][c]; // 투입 안함 (원본)
    }

    // 백트래킹으로 완전탐색 시 3^D <= 160만이 된다.
    // 검사와 함께 고려시 3^D * D*W = 억단위가 된다.
    // 여기서 가지치기를 많이 해야 안에서 잘 끊을 수 있다.
    // 백트래킹으로 완전탐색하는 재귀 메서드 필요
    static void recur(boolean[][] map, int[] medicineList, int cur_idx, int cur_cnt, int limit, int K, int D, int W) {
        if (result != -1) return; // 이미 답을 찾았다면 조기 종료

        if (cur_cnt == limit) {
            if (isPassed(map, medicineList, K, D, W)) {
                result = limit;
            }
            return;
        }

        if (cur_idx >= D) return;

        // 약품을 투약할 행을 선택하는 조합(Combination) 구조
        for (int i = cur_idx; i < D; i++) {
            // A 약품 시도 (1)
            medicineList[i] = 1;
            recur(map, medicineList, i + 1, cur_cnt + 1, limit, K, D, W);

            // B 약품 시도 (2)
            medicineList[i] = 2;
            recur(map, medicineList, i + 1, cur_cnt + 1, limit, K, D, W);

            // 원상 복구 (0: 사용 안함)
            medicineList[i] = 0;

            // 이미 답을 찾았다면 더 이상의 반복 무의미
            if (result != -1) return;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            int D = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            boolean[][] map = new boolean[D][W];
            for (int i = 0; i < D; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < W; j++) {
                    map[i][j] = "1".equals(st.nextToken()); // A가 0, B가 1
                }
            }

            result = -1;
            int[] medicineList = new int[D]; // 성능을 위해 List 대신 배열 사용

            // 약품 투여 횟수를 0부터 K까지 늘려가며 확인 (최소값을 찾기 위함)
            for (int limit = 0; limit <= K; limit++) {
                recur(map, medicineList, 0, 0, limit, K, D, W);
                if (result != -1) break;
            }

            System.out.println("#" + t + " " + result);
        }
    }
}
