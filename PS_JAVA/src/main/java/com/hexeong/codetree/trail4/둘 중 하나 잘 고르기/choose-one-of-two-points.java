import java.util.*;

public class Main {

    static int n = 0;
    static int[][] in;

    static int[][] mem;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        in = new int[2 * n][2];
        for (int i = 0; i < 2 * n; i++) {
            in[i][0] = sc.nextInt();
            in[i][1] = sc.nextInt();
        }

        mem = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
            Arrays.fill(mem[i], -1);

        System.out.println(dfs(0, 0, 0));
    }

    static int dfs(int red, int blue, int idx) {
        if (idx == 2 * n)
            return 0;

        if (mem[red][blue] != -1)
            return mem[red][blue];

        int max = 0;
        if (red < n)
            max = Math.max(max, dfs(red + 1, blue, idx + 1) + in[idx][0]);
        if (blue < n)
            max = Math.max(max, dfs(red, blue + 1, idx + 1) + in[idx][1]);

        return mem[red][blue] = max;
    }
}