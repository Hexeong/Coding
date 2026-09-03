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
    static int[] depth;
    static int[] parents;
    
    public static void main(String[] args) {
        int n = nextInt();
        edges = new List[n + 1];
        depth = new int[n + 1];
        parents = new int[n + 1];
        for (int i = 0; i <= n; i++)
            edges[i] = new ArrayList<>();
        
        for (int i = 1; i <= n - 1; i++) {
            int u = nextInt();
            int v = nextInt();

            edges[u].add(v);
            edges[v].add(u);
        }

        setDepth(1, 0);

        int q = nextInt();
        for (int i = 0; i < q; i++) {
            int a = nextInt();
            int b = nextInt();
            int c = nextInt();

            int minV = Math.min(depth[a], Math.min(depth[b], depth[c]));
            if (minV == depth[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            } else if (minV == depth[c]) {
                int tmp = a;
                a = c;
                c = tmp;
            }

            while (depth[a] != depth[b])
                b = parents[b];
            while (depth[a] != depth[c])
                c = parents[c];

            while (a != b || a != c) {
                a = parents[a];
                b = parents[b];
                c = parents[c];
            }
            
            System.out.println(a);
        }
        // Please write your code here.
    }

    static void setDepth(int cur, int prev) {
        depth[cur] = depth[prev] + 1;
        parents[cur] = prev;
        for (int next : edges[cur]) {
            if (next == prev) continue;

            setDepth(next, cur);
        }
    }
}