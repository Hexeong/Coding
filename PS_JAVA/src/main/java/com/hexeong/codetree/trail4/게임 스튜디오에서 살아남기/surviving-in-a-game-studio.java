import java.util.*;

public class Main {

    static int N;
    static long mod = (long) Math.pow(10, 9) + 7L;
    static int[] num;
    static long[][][] mem;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        // Please write your code here.

        mem = new long[N][3][3]; // 현재 i번째를 보면서, T가 몇개고, B가 몇개일때의 평가 문자열 개수
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 3; j++)
                Arrays.fill(mem[i][j], -1);
        
        System.out.println(dfs(0, 0, 0) % mod);
    }

    static long dfs(int cidx, int cT, int cB) {
        if (cidx == N)
            return 1L;

        if (mem[cidx][cT][cB] != -1) {
            return mem[cidx][cT][cB];
        }

        long cnt = 0;
        // G
        cnt += dfs(cidx + 1, cT, 0);

        // B
        if (cB + 1 < 3) {
            cnt += dfs(cidx + 1, cT, cB + 1);
        }

        // T
        if (cT + 1 < 3) {
            cnt += dfs(cidx + 1, cT + 1, 0);
        }

        return mem[cidx][cT][cB] = (cnt % mod);
    }
}