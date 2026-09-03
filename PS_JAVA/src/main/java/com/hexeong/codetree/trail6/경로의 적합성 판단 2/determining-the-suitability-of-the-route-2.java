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

    static int n, m, k;
    static List<Integer>[] edges;
    static int[] uf;

    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();
        k = nextInt();

        edges = new List[n + 1];
        for (int i = 0; i <= n; i++)
            edges[i] = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            int a = nextInt();
            int b = nextInt();

            edges[a].add(b);
            edges[b].add(a);
        }

        uf = new int[n + 1];
        
        for (int i = 1; i <= n; i++) {
            if (uf[i] != 0) continue;
            setRoots(i, i, i);
        }

        int[] path = new int[k];
        for (int i = 0; i < k; i++) {
            path[i] = nextInt();
        }
        // Please write your code here.

        int root = uf[path[0]];
        for (int i = 1; i < k; i++) {
            if (root != uf[path[i]]) {
                System.out.println(0);
                return;
            }
        }

        System.out.println(1);
    }

    static void setRoots(int cur, int prev, int root) {
        if (uf[cur] == root)
            return;

        uf[cur] = root;

        for (int next : edges[cur]) {
            if (prev == next) continue;

            setRoots(next, cur, root);
        }
    }
}