import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }

    static int n, k;
    static List<Integer>[] edges;
    static int[] values;
    static int[][][] dp;

    public static void main(String[] args) {
        int n = nextInt();
        edges = new List[n + 1];
        for (int i = 0; i <= n; i++)
            edges[i] = new ArrayList<>();
        
        for (int i = 0; i < n - 1; i++) {
            int u = nextInt();
            int v = nextInt();

            edges[u].add(v);
            edges[v].add(u);
        }

        values = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            values[i] = nextInt();
        }

        k = nextInt();
        dp = new int[n + 1][k + 1][2];
        
        // 루트(1번 정점)에서 탐색 시작
        dfs(1, 0);

        int res = 0;
        // 1번 노드를 루트로 하는 전체 트리에서, 0개~K개 색칠했을 때의 최댓값 찾기
        for (int i = 0; i <= k; i++) {
            res = Math.max(res, dp[1][i][0]);
            res = Math.max(res, dp[1][i][1]);
        }

        System.out.println(res);
    }

    static void dfs(int cur, int prev) {
        // 불가능한 상태를 방지하기 위해 매우 작은 값으로 초기화 (Underflow 방지용 -1억)
        for (int i = 0; i <= k; i++) {
            dp[cur][i][0] = -100000000;
            dp[cur][i][1] = -100000000;
        }
        
        int left = 0, right = 0;
        for (int next : edges[cur]) {
            if (next == prev) continue;
            
            if (left == 0) left = next;
            else right = next;
        }
        
        // 자식이 없는 리프 노드인 경우 (Base Case)
        if (left == 0 && right == 0) {
            dp[cur][0][0] = 0;
            if (k >= 1) dp[cur][1][1] = values[cur];
            return;
        }
        
        // 자식 서브트리를 먼저 모두 탐색 (Bottom-Up)
        dfs(left, cur);
        dfs(right, cur);
        
        // 현재 노드(cur)를 색칠하지 않는 경우: 자식들은 색칠 여부 상관없음
        for (int i = 0; i <= k; i++) {
            int maxUnselected = -100000000;
            for (int j = 0; j <= i; j++) {
                int leftMax = Math.max(dp[left][j][0], dp[left][j][1]);
                int rightMax = Math.max(dp[right][i - j][0], dp[right][i - j][1]);
                maxUnselected = Math.max(maxUnselected, leftMax + rightMax);
            }
            dp[cur][i][0] = maxUnselected;
        }
        
        // 현재 노드(cur)를 색칠하는 경우: 자식들은 무조건 색칠되지 않아야 함 (dp[...][0])
        for (int i = 1; i <= k; i++) {
            int maxSelected = -100000000;
            for (int j = 0; j <= i - 1; j++) {
                int leftMax = dp[left][j][0];
                int rightMax = dp[right][i - 1 - j][0];
                maxSelected = Math.max(maxSelected, values[cur] + leftMax + rightMax);
            }
            dp[cur][i][1] = maxSelected;
        }
    }
}