package com.hexeong.programmers;

import java.util.*;

public class PGM_340211 {
}

class Solution {

    static class Pos {
        int y;
        int x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public int solution(int[][] points, int[][] routes) {
        int collision = 0;

        // 충돌 정보
        int[][] coll_map = new int[101][101];
        for (int i = 1; i < 101; i++)
            Arrays.fill(coll_map[i], 0);

        // 현재 목적지 정보 설정
        Pos[] cur_pos = new Pos[routes.length];
        int[] cur_dest = new int[routes.length];
        for (int i = 0; i < routes.length; i++) {
            cur_pos[i] = new Pos(points[routes[i][0] - 1][0], points[routes[i][0] - 1][1]);
            cur_dest[i] = 1;
            coll_map[cur_pos[i].y][cur_pos[i].x]++;
        }

        // 초기 상태에서의 충돌 검사
        for (int i = 0; i < cur_pos.length; i++) {
            if (coll_map[cur_pos[i].y][cur_pos[i].x] > 1)
                collision++;
            coll_map[cur_pos[i].y][cur_pos[i].x] = 0;
        }

        while (true) {
            int cnt = 0;

            // 모두의 이동 1번
            for (int i = 0; i < cur_pos.length; i++) {
                // 이동해야 하는지 검사
                if (cur_pos[i].y == points[routes[i][cur_dest[i]] - 1][0]
                        && cur_pos[i].x == points[routes[i][cur_dest[i]] - 1][1]) {

                    if (cur_dest[i] + 1 == routes[i].length) {
                        cnt++;
                        continue; // 다음 목적지가 없다면 continue;
                    }
                    else
                        cur_dest[i]++; // 다음 목적지 변경
                }

                if (cur_pos[i].y != points[routes[i][cur_dest[i]] - 1][0]) {
                    int diff = Math.abs(points[routes[i][cur_dest[i]] - 1][0] - cur_pos[i].y);
                    int decision = (points[routes[i][cur_dest[i]] - 1][0] - cur_pos[i].y) / diff;

                    cur_pos[i].y += decision;
                    coll_map[cur_pos[i].y][cur_pos[i].x]++;
                } else {
                    int diff = Math.abs(points[routes[i][cur_dest[i]] - 1][1] - cur_pos[i].x);
                    int decision = (points[routes[i][cur_dest[i]] - 1][1] - cur_pos[i].x) / diff;

                    cur_pos[i].x += decision;
                    coll_map[cur_pos[i].y][cur_pos[i].x]++;
                }
            }

            // 아무도 움직이지 않으면 탈출
            if (cur_pos.length == cnt)
                break;

            // 충돌 검사
            for (int i = 0; i < cur_pos.length; i++) {
                if (coll_map[cur_pos[i].y][cur_pos[i].x] > 1)
                    collision++;
                coll_map[cur_pos[i].y][cur_pos[i].x] = 0;
            }
        }

        return collision;
    }
}