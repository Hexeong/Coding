import java.util.*;

public class Main {

    static int n;
    static int[] op;
    static int[] me;

    static int[][] mem;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        op = new int[n];
        me = new int[n];
        for (int i = 0; i < n; i++)
            op[i] = sc.nextInt();

        for (int i = 0; i < n; i++)
            me[i] = sc.nextInt();

        mem = new int[n][n];
        for (int i = 0; i < n; i++)
            Arrays.fill(mem[i], -1);

        System.out.println(dfs(0, 0));
    }

    static int dfs(int co_idx, int cm_idx) {
        if (co_idx == n || cm_idx == n) {
            return 0;
        }

        if (mem[co_idx][cm_idx] != -1)
            return mem[co_idx][cm_idx];

        int max = 0;
        
        // 1. 카드 대결
        if (op[co_idx] > me[cm_idx]) {
            max = Math.max(max, dfs(co_idx, cm_idx + 1) + me[cm_idx]);
        } else if (op[co_idx] < me[cm_idx]) {
            max = Math.max(max, dfs(co_idx + 1, cm_idx));
        } else {
            max = Math.max(max, dfs(co_idx + 1, cm_idx + 1));
        }

        // 2. 카드 버리기
        max = Math.max(max, dfs(co_idx + 1, cm_idx + 1));

        mem[co_idx][cm_idx] = max;
        return max;
    }
}