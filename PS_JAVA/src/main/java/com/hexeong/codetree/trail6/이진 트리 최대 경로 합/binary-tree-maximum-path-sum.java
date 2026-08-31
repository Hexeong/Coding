import java.util.*;

public class Main {

    static List<Integer>[] edges;
    static int n;
    static int res = Integer.MIN_VALUE;
    static int[] values;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        edges = new List[n + 1];
        for (int i = 0; i <= n; i++)
            edges[i] = new ArrayList<>();

        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();

            edges[u].add(v);
            edges[v].add(u);
        }

        values = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            values[i] = sc.nextInt();
        }
        // Please write your code here.

        int localRes = dfs(1, -1);

        System.out.println(res);

    }

    static int dfs(int cur, int parent) {
        int cnt = values[cur]; // 현재 서브트리 내에서 발생 가능한 경로
        int max = Integer.MIN_VALUE; // 위로 올라갈 수 있는 경로

        for (int next : edges[cur]) {
            if (next == parent) continue;

            int nextRes = dfs(next, cur);
            cnt += nextRes;
            max = Math.max(max, nextRes);
        }

        res = Math.max(res, cnt);

        if (max > 0) {
            res = Math.max(res, max + values[cur]);
            return max + values[cur];
        } else if (values[cur] > 0) {
            res = Math.max(res, values[cur]);
            return values[cur];
        } else {
            return 0;
        }
    }
}