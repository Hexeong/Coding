package com.hexeong.programmers;

import java.util.*;

public class PGM_60059 {
    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = false;

        int degree = 0;
        while (degree < 360) {
            int[][] new_key = rotate(key, degree);

            boolean flag = false;
            for (int i = - new_key.length + 1; i < lock.length; i++) {
                if (answer) {
                    break;
                }

                for (int j = - new_key[0].length + 1; j < lock[0].length; j++) {
                    if (isSolved(new_key, lock, i, j)) {
                        answer = true;
                        break;
                    }
                }
            }
            if (answer) {
                break;
            }

            degree += 90;
        }

        return answer;
    }

    public boolean isSolved(int[][] key, int[][] lock, int pos_x, int pos_y) {
        boolean result = true;
        for (int i = 0; i < lock.length; i++) {
            if (!result) {
                break;
            }

            for (int j = 0; j < lock[0].length; j++) {
                if (pos_y <= i && i < pos_y + key.length
                        && pos_x <= j && j < pos_x + key[0].length) {
                    if (1 != lock[i][j] + key[i - pos_y][j - pos_x]) {
                        result = false;
                        break;
                    }
                }
                else if (1 != lock[i][j]) {
                    result = false;
                    break;
                }
            }
        }

        return result;
    }

    public int[][] rotate(int[][] key, int degree) {
        if (degree == 90) {
            int[][] new_key = new int[key[0].length][key.length];
            for (int i = 0; i < key.length; i++) {
                for (int j = 0; j < key[0].length; j++) {
                    new_key[key[0].length - j - 1][i] = key[i][j];
                }
            }
            return new_key;
        }

        if (degree == 180) {
            int[][] new_key = new int[key.length][key[0].length];
            for (int i = 0; i < key.length; i++) {
                for (int j = 0; j < key[0].length; j++) {
                    new_key[key.length - i - 1][key[0].length - j - 1] = key[i][j];
                }
            }
            return new_key;
        }

        if (degree == 270) {
            int[][] new_key = new int[key[0].length][key.length];
            for (int i = 0; i < key.length; i++) {
                for (int j = 0; j < key[0].length; j++) {
                    new_key[j][key.length - i - 1] = key[i][j];
                }
            }
            return new_key;
        }

        return key;
    }
}