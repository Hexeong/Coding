package com.hexeong.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class SWEA_홈방범서비스 {

    static class Pos {
        public int y;
        public int x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static int result = 0;

    public static void solve(List<Pos> homeList, int baseY, int baseX, int k, int M) {
        int cnt = 0;
        for (int i = 0; i < homeList.size(); i++) {
            int targetDist = Math.abs(baseY - homeList.get(i).y) + Math.abs(baseX - homeList.get(i).x);
            if (targetDist < k) { // 영역 내부인 경우
                cnt++;
            }
        }

        int price = k * k + (k - 1) * (k - 1);
        if (price <= cnt * M) {
            result = Math.max(result, cnt);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int t = 1; t <= T; t++) {
            // 초기화
            result = 0;

            // N * N * K = 400 * 25 = 10000
            // 여기에 해당 케이스에 대해서 존재하는 집 개수를 파악하는 비용은
            // 집들을 순회하며 맨해튼 거리로 k 보다 기준 점에서 거리가 작거나 같으면
            // 집들의 개수 파악이 가능

            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()); // 도시 크기 <= 20
            int M = Integer.parseInt(st.nextToken()); // 각 집이 지불 가능한 비용 <= 10

            List<Pos> homeList = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    boolean tmp = "1".equals(st.nextToken());
                    if (tmp)
                        homeList.add(new Pos(i, j));
                }
            }

            for (int k = 21; k > 0; k--) { // 21이면 20 * 20 크기의 맵 전체 커버가 가능
                // 여기서 해당 조건에서 찾기 시작
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        solve(homeList, i, j, k, M);
                    }
                }
            }

            System.out.println("#" + t + " " + result);
        }
    }
}
