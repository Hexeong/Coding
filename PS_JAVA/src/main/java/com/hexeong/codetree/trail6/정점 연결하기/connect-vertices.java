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
    static int[] uf;

    public static void main(String[] args) {
        n = nextInt();
        edges = new List[n + 1];
        for (int i = 0; i <= n; i++) {
            edges[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 2; i++) {
            int u = nextInt();
            int v = nextInt();

            edges[u].add(v);
            edges[v].add(u);
        }
        // Please write your code here.

        uf = new int[n + 1];
        for (int i = 0; i <= n; i++)
            uf[i] = i;

        // for (int i = 1; i <= n; i++)
        //     System.out.print(uf[i] + " ");
        // System.out.println();

        for (int i = 1; i <= n; i++) {
            if (uf[i] != i) continue;

            setUnionFind(i, i, i);
        }

        // for (int i = 1; i <= n; i++)
        //     System.out.print(uf[i] + " ");
        // System.out.println();

        int firstNode = 1;
        int secondNode = 0;
        for (int i = 2; i <= n; i++) {
            if (uf[i] != uf[firstNode]) {
                secondNode = i;
                break;
            }
        }

        System.out.println(firstNode + " " + secondNode);
    }

    static void setUnionFind(int cur, int prev, int root) {
        for (int next : edges[cur]) {
            if (prev == next) continue;

            uf[next] = root;
            setUnionFind(next, cur, root);
        }
    }
}