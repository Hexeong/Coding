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

    static int n, m;
    static int[][] edges;
    static int[] uf;

    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();
        edges = new int[m][3];
        uf = new int[n + 1];
        for (int i = 1; i <= n; i++)
            uf[i] = i;
        
        for (int i = 0; i < m; i++) {
            edges[i][0] = nextInt();
            edges[i][1] = nextInt();
            edges[i][2] = nextInt();
        }
        // Please write your code here.

        Arrays.sort(edges, (a, b) -> {
            return a[2] - b[2];
        });

        int res = 0;

        for (int i = 0; i < m; i++) {
            int rootU = find(edges[i][0]);
            int rootV = find(edges[i][1]);

            if (rootU != rootV) {
                uf[rootU] = rootV;
                res += edges[i][2];
            }
        }

        System.out.println(res);
    }

    static int find(int x) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x]);
        return uf[x];
    }
}