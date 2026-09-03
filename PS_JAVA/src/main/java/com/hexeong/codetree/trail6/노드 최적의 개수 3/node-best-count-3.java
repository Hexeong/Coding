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
    static List<Integer>[] edges;

    public static void main(String[] args) {
        n = nextInt();
        edges = new List[n + 1];
        for (int i = 0; i <= n; i++)
            edges[i] = new ArrayList<>();
        
        for (int i = 0; i < n - 1; i++) {
            int a = nextInt();
            int b = nextInt();
            edges[a].add(b);
            edges[b].add(a);
        }

        int[] rootDp = dfs(1, 0);
        // 루트 노드는 부모가 없으므로 상태 2(부모에게 의존)가 될 수 없습니다.
        System.out.println(Math.min(rootDp[0], rootDp[1]));
    }

    // 반환값: {물건을 놓았을 때의 최소 비용, 물건이 없고 자식에 의해 커버될 때의 최소 비용, 물건이 없고 커버되지 않아 부모가 필요한 최소 비용}
    static int[] dfs(int cur, int prev) {
        int cost0 = 1; // 현재 노드에 물건을 놓음
        int cost1 = 0; // 현재 노드에 물건이 없고, 자식에 의해 커버됨
        int cost2 = 0; // 현재 노드에 물건이 없고, 자식에게도 커버되지 않음 (부모 필요)

        boolean hasChild = false;
        int minForceChild = Integer.MAX_VALUE / 2;

        for (int next : edges[cur]) {
            if (next == prev) continue;
            hasChild = true;
            int[] nextDp = dfs(next, cur);

            // 1. 현재 노드에 물건을 놓는 경우: 자식들은 어떤 상태든 상관없음 (가장 유리한 상태 선택)
            cost0 += Math.min(nextDp[0], Math.min(nextDp[1], nextDp[2]));

            // 2. 현재 노드에 물건이 없고 자식에 의해 커버되는 경우: 자식은 물건을 놓았거나(0) 자식에 의해 커버되어야 함(1)
            int bestChild = Math.min(nextDp[0], nextDp[1]);
            cost1 += bestChild;
            // 자식 중 최소한 한 개는 반드시 물건을 놓아야(state 0) 현재 노드가 커버되므로, 그에 대한 보정값 계산
            minForceChild = Math.min(minForceChild, nextDp[0] - bestChild);

            // 3. 현재 노드에 물건이 없고 커버도 안 되는 경우: 자식들도 모두 커버되어야 하므로 state 1 상태여야 함
            cost2 += nextDp[1];
        }

        // 리프 노드인 경우의 Base Case 처리
        if (!hasChild) {
            return new int[]{1, 1000000, 0};
        }

        // 자식들 중 단 한 명도 물건을 놓지 않았다면, 가장 비용이 적게 드는 자식 하나에게 물건을 강제로 놓게 함
        cost1 += Math.max(0, minForceChild);

        return new int[]{cost0, cost1, cost2};
    }
}