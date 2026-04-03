package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_6536 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] price = new int[N];
        for (int i = 0; i < N; i++) {
            price[i] = Integer.parseInt(br.readLine());
        }

        int left = 0;
        int right = 1000000000;
        int min = Integer.MAX_VALUE;
        while (left < right) {
            int mid = (left + right) / 2;

            boolean flag = false;
            int lefted = 0;
            int withdraw_cnt = 0;
            for (int i = 0; i < N; i++) {

                if (lefted == 0) {
                    if (price[i] > mid) {
                        // 한번에 인출하는 K가 해당 날에 사용해야할 금액보다 작으면 인출 금액을 키워야 함.
                        flag = true;
                        break;
                    } else {
                        withdraw_cnt++;
                        lefted = mid - price[i];
                    }
                } else {
                    if (lefted >= price[i]) {
                        lefted -= price[i];
                    }
                    else {
                        if (price[i] > mid) {
                            // 한번에 인출하는 K가 해당 날에 사용해야할 금액보다 작으면 인출 금액을 키워야 함.
                            flag = true;
                            break;
                        } else {
                            withdraw_cnt++;
                            lefted = mid - price[i];
                        }
                    }
                }

                if (withdraw_cnt > M) {
                    // 너무 많이 인출한 경우, mid값을 낮춰야 함
                    flag = true;
                    break;
                }
            }

            if (flag) { // left를 mid + 1해야 한다면
                left = mid + 1;
                continue;
            }

            if (withdraw_cnt <= M) {
                min = Math.min(min, mid);
            }
            right = mid;
        }

        System.out.println(min);
    }
}
