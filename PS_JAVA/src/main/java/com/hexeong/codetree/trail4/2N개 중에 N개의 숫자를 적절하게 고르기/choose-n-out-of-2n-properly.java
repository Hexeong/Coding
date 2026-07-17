import java.util.*;
import java.io.*;

public class Main {

    static int n;
    static int[] num;
    static boolean[] seq;

    static int minV = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        num = new int[2 * n];
        seq = new boolean[2 * n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 2 * n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }

        backt(0, 0, 0);

        System.out.println(minV);
    }

    private static void backt(int a_cnt, int b_cnt, int cur_idx) {
        if (cur_idx == 2 * n) {
            int a = 0, b = 0;
            for (int i = 0; i < 2 * n; i++)
                if (seq[i])
                    a += num[i];
                else 
                    b += num[i];
            
            minV = Math.min(minV, Math.abs(a - b));
            return;
        }


        if (a_cnt < n) {
            seq[cur_idx] = true;
            backt(a_cnt + 1, b_cnt, cur_idx + 1);
        }

        if (b_cnt < n) {
            seq[cur_idx] = false;
            backt(a_cnt, b_cnt + 1, cur_idx + 1);
        }
    }
}