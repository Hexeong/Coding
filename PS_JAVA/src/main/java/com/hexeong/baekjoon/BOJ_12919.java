package com.hexeong.baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_12919 {
    // AI의 피드백 : SB를 1개로 유지하고 process가 끝난 이후 원상태로 복구하는 방식으로 최적화하자.
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String S = br.readLine();
        String T = br.readLine();

        StringBuilder sb = new StringBuilder(T);

        System.out.println(process(sb, S) ? 1 : 0);
    }

    private static boolean process(StringBuilder sb, String S) {
        if (sb.toString().equals(S)) {
            return true;
        }
        if (sb.length() <= S.length()) {
            return false;
        }

        if (sb.charAt(sb.length() - 1) == 'A' && process(removeAtoSb(sb), S)) {
            return true;
        }
        return sb.charAt(0) == 'B' && process(reverseAndDeleteBtoSb(sb), S);
    };

    private static StringBuilder removeAtoSb(StringBuilder sb) {
        return new StringBuilder(sb).deleteCharAt((sb.length() - 1));
    }

    private static StringBuilder reverseAndDeleteBtoSb(StringBuilder sb) {
        return new StringBuilder(sb).reverse().deleteCharAt((sb.length() - 1));
    }
}
