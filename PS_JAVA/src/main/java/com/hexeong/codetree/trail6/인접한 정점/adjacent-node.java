import java.util.*;

public class Main {

    static int[] values;
    static int[][] dp;
    static int n;
    static List<Integer>[] edges;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        dp = new int[n + 1][2];

        values = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            values[i] = sc.nextInt();
        }

        edges = new List[n + 1];
        for (int i = 0; i <= n; i++)
            edges[i] = new ArrayList<>();
        
        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();

            edges[u].add(v);
            edges[v].add(u);
        }
        // Please write your code here.

        dfs(1, -1);

        System.out.println(Math.max(dp[1][0], dp[1][1]));
    }

    static void dfs(int cur, int parent) {
        int cntA = 0; // 현재 것을 선택하지 않았을 때, 현재를 서브트리로 할떄의 합의 최댓값
        int cntB = 0; // 현재 것을 선택했을 때 ...

        for (int next : edges[cur]) {
            if (next == parent) continue;

            dfs(next, cur);
            cntA += Math.max(dp[next][0], dp[next][1]);
            cntB += dp[next][0];
        }

        dp[cur][0] = cntA;
        dp[cur][1] = values[cur] + cntB;
    }
}