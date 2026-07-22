import java.util.*;

public class Main {

    static String nStr;
    static long MOD = (long) Math.pow(10, 9) + 7L;
    static long[][][][] mem;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);

        nStr = sc.next();
        mem = new long[nStr.length()][2][2][3];

        for (int i = 0; i < nStr.length(); i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    Arrays.fill(mem[i][j][k], -1);
                }
            }
        }

        long answer = dfs(nStr, 0, 0, 0, 0);

        answer = (answer - 1 + MOD) % MOD;
        System.out.println(answer);
    }

    static long dfs(String cur, int idx, int isLess, int has369, int mod3) {
        if (idx == cur.length()) {
            if (has369 == 1 || mod3 % 3 == 0)
                return 1;
            else
                return 0;
        }

        if (mem[idx][isLess][has369][mod3] != -1)
            return mem[idx][isLess][has369][mod3];

        long cnt = 0;
        int limit = (isLess == 1) ? 9 : cur.charAt(idx) - '0';
        for (int i = 0; i <= limit; i++) {
            // 다음 isLess 상태: 이미 작거나, 이번에 limit보다 작은 숫자를 골랐다면 1
            int nextIsLess = (isLess == 1 || i < limit) ? 1 : 0;
            
            // 다음 has369 상태: 이미 3,6,9가 있거나, 현재 숫자가 3,6,9라면 1
            int nextHas369 = (has369 == 1 || i == 3 || i == 6 || i == 9) ? 1 : 0;
            
            // 다음 mod3 상태
            int nextMod3 = (mod3 + i) % 3;

            cnt += dfs(cur, idx + 1, nextIsLess, nextHas369, nextMod3);
            cnt %= MOD;
        }

        return mem[idx][isLess][has369][mod3] = cnt;
    }
}