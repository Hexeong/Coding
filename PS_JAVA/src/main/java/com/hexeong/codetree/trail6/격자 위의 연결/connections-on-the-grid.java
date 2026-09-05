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
        edges = new int[n * (m - 1) + (n - 1) * m][3];

        int eIdx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                edges[eIdx][0] = i * m + j + 1;
                edges[eIdx][1] = i * m + j + 2;
                edges[eIdx][2] = nextInt();

                eIdx++;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                edges[eIdx][0] = i * m + j + 1;
                edges[eIdx][1] = (i + 1) * m + j + 1;
                edges[eIdx][2] = nextInt();

                eIdx++;
            }
        }
        // Please write your code here.

        Arrays.sort(edges, (a, b) -> {
            return a[2] - b[2];
        });

        uf = new int[n * m + 1];
        for (int i = 1; i <= n * m; i++)
            uf[i] = i;

        int res = 0;
        for (int i = 0; i < n * (m - 1) + (n - 1) * m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int rootU = find(u);
            int rootV = find(v);

            if (rootU != rootV) {
                uf[rootU] = rootV;
                res += edges[i][2];
                // System.out.println("O: " + u + " " + v + " " + edges[i][2]);
            } else {
                // System.out.println("X: " + u + " " + v + " " + edges[i][2]);
            }
        }

        // for (int i = 1; i <= n * m; i++)
        //     System.out.print(uf[i] + " ");
        // System.out.println();

        System.out.println(res);
    }

    static int find(int x) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x]);
        return uf[x];
    }
}