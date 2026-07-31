import java.util.*;
import java.io.*;

public class Main {

    static int n;
    static Map<Integer, List<Node>> adj = new HashMap<>();

    public static void main(String[] args) {
        n = nextInt();
        for (int i = 2; i <= n; i++) {
            int t = nextInt();
            int a = nextInt();
            int p = nextInt();
            adj.computeIfAbsent(p, k -> new ArrayList<>()).add(new Node(i, (t == 0 ? -a : a)));
        }
        // Please write your code here.

        System.out.println(dfs(1));
    }

    static int dfs(int cur) {
        if (!adj.containsKey(cur))
            return 0;

        int cnt = 0;
        for (Node next : adj.getOrDefault(cur, Collections.emptyList())) {
            int v = dfs(next.n) + next.v;
            cnt += (v > 0 ? v : 0);
        }
        return cnt;
    }

    static class Node {
        int n;
        int v;
        public Node(int n, int v) {
            this.n = n;
            this.v = v;
        }
    }

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
}