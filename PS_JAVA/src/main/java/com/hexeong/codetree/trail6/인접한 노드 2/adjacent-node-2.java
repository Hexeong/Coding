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

    static int n;
    static int[] values;
    static List<Integer>[] edges;
    static int[][] dp;
    static List<Integer> selectedNodes;

    public static void main(String[] args) {
        n = nextInt();
        values = new int[n + 1];
        for (int i = 1; i <= n; i++)
            values[i] = nextInt();
        
        edges = new List[n + 1];

        for (int i = 1; i <= n; i++) {
            edges[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            int u = nextInt();
            int v = nextInt();

            edges[u].add(v);
            edges[v].add(u);
        }
        // Please write your code here.

        dp = new int[n + 1][2];
        selectedNodes = new ArrayList<>();
        
        // 1. 첫 번째 DFS: DP 배열을 채워 최대합 계산 (Bottom-up)
        dfs1(1, 0);
        
        // 2. 두 번째 DFS: DP 배열을 바탕으로 선택된 노드 역추적 (Top-down)
        dfs2(1, 0, false);
        
        // 결과 출력
        Collections.sort(selectedNodes); // 번호가 낮은 것부터 출력하기 위해 정렬
        
        System.out.println(Math.max(dp[1][0], dp[1][1])); // 최댓값 출력
        for (int node : selectedNodes) {
            System.out.print(node + " "); // 선택된 노드 번호 출력
        }
    }

    // 트리 DP로 서브트리의 최적해를 구하는 함수
    static void dfs1(int cur, int prev) {
        dp[cur][0] = 0;             // 현재 노드를 선택하지 않은 경우
        dp[cur][1] = values[cur];   // 현재 노드를 선택한 경우

        for (int next : edges[cur]) {
            if (next == prev) continue;
            
            dfs1(next, cur);
            
            // 현재 노드 선택 X -> 자식 노드는 선택하든 안 하든 상관없이 최댓값 더함
            dp[cur][0] += Math.max(dp[next][0], dp[next][1]);
            
            // 현재 노드 선택 O -> 자식 노드는 무조건 선택 X
            dp[cur][1] += dp[next][0];
        }
    }

    // 선택된 노드를 역추적하는 함수
    static void dfs2(int cur, int prev, boolean isParentSelected) {
        boolean isCurrentSelected = false;

        // 부모 노드가 선택되지 않았고, 현재 노드를 선택했을 때의 값이 더 크다면 선택
        if (!isParentSelected && dp[cur][1] > dp[cur][0]) {
            isCurrentSelected = true;
            selectedNodes.add(cur);
        }

        for (int next : edges[cur]) {
            if (next == prev) continue;
            
            // 현재 노드의 선택 여부를 부모의 선택 여부로 넘겨주며 자식 탐색
            dfs2(next, cur, isCurrentSelected);
        }
    }
}