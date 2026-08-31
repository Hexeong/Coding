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

    static long nextLong() {
        return Long.parseLong(next());
    }

    static int n, r, q;
    static Map<Integer, List<Integer>> adj = new HashMap<>();
    static int[] nodes;

    public static void main(String[] args) {
        n = nextInt();
        r = nextInt();
        q = nextInt();
        nodes = new int[n + 1];
        for (int i = 0; i < n - 1; i++) {
            int u = nextInt();
            int v = nextInt();

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        // 후위 순회로 진행

        nodes[r] = dfs(r, -1);

        for (int i = 0; i < q; i++) {
            int query = nextInt();

            System.out.println(nodes[query]);
        }
        // Please write your code here.
    }

    static int dfs(int cur, int last) {
        if (adj.getOrDefault(cur, null) == null) {
            nodes[cur] = 1;
            return 1;
        }

        int cnt = 1;
        for (int c : adj.get(cur)) {
            if (last == c) continue;
            cnt += dfs(c, cur);
        }

        nodes[cur] = cnt;
        return cnt;
    }
}