import java.util.*;
public class Main {

    static int N, M;
    static int[] num;
    static long[][] mem;
    static int offset = 20;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        num = new int[N];
        for (int i = 0; i < N; i++) {
            num[i] = sc.nextInt();
        }
        // Please write your code here.

        mem = new long[N][41];
        for (int i = 0; i < N; i++)
            Arrays.fill(mem[i], -1);

        System.out.println(dfs(0, 0));
    }

    static long dfs(int cidx, int amnt) {
        if (cidx == N) {
            if (amnt == M)
                return 1L;
            else
                return 0L;
        }

        if (mem[cidx][offset + amnt] != -1) {
            return mem[cidx][offset + amnt];
        }

        long cnt = 0;
        if (amnt + num[cidx] <= 20) {
            cnt += dfs(cidx + 1, amnt + num[cidx]);
        }

        if (amnt - num[cidx] >= -20) {
            cnt += dfs(cidx + 1, amnt - num[cidx]);
        }

        return mem[cidx][offset + amnt] = cnt;
    }
}