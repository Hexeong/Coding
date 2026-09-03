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

    static int n, LOG;
    static List<Integer>[] edges;
    static int[] depth;
    static int[][] parent;

    public static void main(String[] args) {
        int n = nextInt();
        edges = new List[n + 1];
        depth = new int[n + 1];
        
        // 2^LOG >= N 이 되도록 LOG 크기 설정 (N <= 100,000 이므로 17이면 충분)
        LOG = 17;
        parent = new int[n + 1][LOG];

        for (int i = 0; i <= n; i++)
            edges[i] = new ArrayList<>();
        
        for (int i = 1; i <= n - 1; i++) {
            int u = nextInt();
            int v = nextInt();

            edges[u].add(v);
            edges[v].add(u);
        }

        dfs(1, 0, 1);

        int q = nextInt();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < q; i++) {
            int a = nextInt();
            int b = nextInt();

            int lca = getLCA(a, b);
            
            // a부터 b까지의 경로에 포함되는 노드 수 계산
            // (depth[a] + depth[b] - 2 * depth[lca] + 1)
            int cnt = depth[a] + depth[b] - 2 * depth[lca] + 1;
            sb.append(cnt).append("\n");
        }
        
        System.out.print(sb);
    }

    // DFS로 깊이 및 2^k 번째 부모 미리 계산 (이진 상승 전처리)
    static void dfs(int cur, int p, int d) {
        depth[cur] = d;
        parent[cur][0] = p;

        for (int i = 1; i < LOG; i++) {
            parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
        }

        for (int next : edges[cur]) {
            if (next == p) continue;
            dfs(next, cur, d + 1);
        }
    }

    // 이진 상승을 이용한 LCA 구하기 O(log N)
    static int getLCA(int a, int b) {
        if (depth[a] < depth[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        // 1. 깊이 맞추기
        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[a] - (1 << i) >= depth[b]) {
                a = parent[a][i];
            }
        }

        if (a == b) return a;

        // 2. 공통 조상 바로 아래까지 끌어올리기
        for (int i = LOG - 1; i >= 0; i--) {
            if (parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
        }

        return parent[a][0];
    }
}