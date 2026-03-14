package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_20055 {
    // AI의 피드백 : Wrapper 클래스 사용을 지양하자.
    // 또한, 코테에서는 클래스의 멤버 메서드 사용하지 말고 배열을 직접 조작하는 방식을 사용하자.
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Section[] belt = new Section[2 * N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 2 * N; i++) {
            belt[i] = new Section(false, Integer.parseInt(st.nextToken()));
        }

        int round = 0;
        int cntZeroSection = 0;
        int startIdx = 0;
        while (cntZeroSection < K) {
            round++;

            // 1. 로봇과 함께 회전
            startIdx = (startIdx - 1 + 2 * N) % (2 * N);
            int loweridx = (startIdx + N - 1) % (2 * N);
            belt[loweridx].setRobotExists(false);

            // 2. N-2부터 0까지 앞으로 1칸 이동
            int targetIdx = (startIdx + N - 2) % (2 * N);
            int endIdx = startIdx - 1 < 0 ? 2 * N - 1 : startIdx - 1;
            for (int curIdx = targetIdx; curIdx != endIdx; curIdx = (curIdx == 0 ? 2 * N - 1 : curIdx - 1)) {
                int nextIdx = (curIdx + 1) % (2 * N);
                if (belt[curIdx].getRobotExists()
                        && !belt[nextIdx].getRobotExists()
                        && belt[nextIdx].getDurability() > 0) {

                    belt[nextIdx].setRobotExists(true);
                    belt[nextIdx].setDurability(belt[nextIdx].getDurability() - 1);
                    belt[curIdx].setRobotExists(false);

                    // 2-1. 내구도가 0이 됐으면 cntZeroSection += 1;
                    if (belt[nextIdx].getDurability() == 0)
                        cntZeroSection++;

                    if (nextIdx == loweridx) { // N-1 위치에 로봇이 오면 즉시 내린다.
                        belt[nextIdx].setRobotExists(false);
                    }
                }
            }

            // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니라면 올리는 위치에 로봇을 올리기
            if (belt[startIdx].getDurability() > 0) {
                belt[startIdx].setRobotExists(true);
                belt[startIdx].setDurability(belt[startIdx].getDurability() - 1);
                // 3-1. 내구도가 0이 됐으면 cntZeroSection += 1;
                if (belt[startIdx].getDurability() == 0)
                    cntZeroSection++;
            }
        }

        System.out.println(round);
    }

    static class Section {
        private Boolean isRobotExists;
        private Integer durability;
        public Section(boolean isRobotExists, Integer durability) {
            this.isRobotExists = isRobotExists;
            this.durability = durability;
        }

        public Boolean getRobotExists() {
            return isRobotExists;
        }

        public Integer getDurability() {
            return durability;
        }

        public void setRobotExists(Boolean robotExists) {
            isRobotExists = robotExists;
        }

        public void setDurability(Integer durability) {
            this.durability = durability;
        }
    }
}
