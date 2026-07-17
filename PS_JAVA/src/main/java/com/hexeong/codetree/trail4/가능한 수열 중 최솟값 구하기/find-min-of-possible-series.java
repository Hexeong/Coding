import java.util.*;

public class Main {

    static int n = 0;
    static boolean flag = false;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        // 불가능한 수열 조건
        // 2개의 인접한
        // 연속 부분 수열(4, 5, 6, 45, 56, 456)

        int[] seq = new int[n];
        backt(seq, 0);
    }

    private static void backt(int[] seq, int cur_idx) {
        if (flag)
            return;

        if (cur_idx == n) {
            for (int i = 0; i < n; i++) {
                System.out.print(seq[i]);
            }
            flag = true;
            return;
        }

        for (int i = 4; i < 7; i++) {
            seq[cur_idx] = i;
            if (check(seq, cur_idx)) continue;
            backt(seq, cur_idx + 1);
        }
    }

    private static boolean check(int[] seq, int cur_idx) {
        for (int k = 1; cur_idx - 2 * k + 1 >= 0; k++) {
            boolean isSame = true;
            for (int i = 0; i < k; i++) {
                if (seq[cur_idx - i] != seq[cur_idx - i - k]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame)
                return true;
        }

        return false;
    }
}