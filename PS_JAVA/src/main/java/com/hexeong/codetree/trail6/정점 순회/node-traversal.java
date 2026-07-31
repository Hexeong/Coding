import java.util.*;
import java.io.*;

public class Main {

    static int n, s, d;
    static Map<Integer, List<Integer>> adj = new HashMap<>();
    static int ans = 0;

    public static void main(String[] args) {
        n = nextInt();
        s = nextInt();
        d = nextInt();

        for (int i = 0; i < n - 1; i++) {
            int a = nextInt();
            int b = nextInt();

            adj.computeIfAbsent(a, x -> new ArrayList<>()).add(b);
            adj.computeIfAbsent(b, x -> new ArrayList<>()).add(a);
        }

        dfs(s, -1);
        System.out.println(ans);
    }

    static int dfs(int cur, int parent) {
        int maxDist = 0;

        for (int next : adj.getOrDefault(cur, Collections.emptyList())) {
            if (next == parent) continue;

            int childDist = dfs(next, cur) + 1;
            maxDist = Math.max(maxDist, childDist);
        }

        if (cur != s && maxDist >= d) {
            ans += 2;
        }

        return maxDist;
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