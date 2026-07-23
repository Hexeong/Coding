import java.util.*;

public class Main {

    static int n, m;
    static int[][][] mem; // 현재 i 위치에서, i위치의 숫자가 j이고, 현재 인접한 숫자가 다른 횟수가 k번일 때의 최대 유사도 값
    static int[] in;

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt(); m = sc.nextInt();

        in = new int[n];
        mem = new int[n][5][m + 1];

        for (int i = 0; i < n; i++)
            in[i] = sc.nextInt();

        int max = 0;
        for (int v = 1; v < 5; v++) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < 5; j++)
                    Arrays.fill(mem[i][j], -1);
            
            max = Math.max(max, dfs(0, v, 0));
        }

        System.out.println(max);
    }

    static int dfs(int ci, int cv, int cAdjDiff) {
        if (ci == n) {
            return 0;
        }

        if (mem[ci][cv][cAdjDiff] != -1) return mem[ci][cv][cAdjDiff];

        int sim = 0;
        for (int nv = 1; nv < 5; nv++) {
            if (cAdjDiff == m && cv != nv) continue;

            int nextSim = dfs(ci + 1, nv, cAdjDiff + (cv != nv ? 1 : 0)) 
                + (cv == in[ci] ? 1 : 0);
            if (nextSim > sim) {
                sim = nextSim;
            }
        }

        return mem[ci][cv][cAdjDiff] = sim;
    }
}