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
    static int[] uf;


    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();
        
        uf = new int[n + 1];
        for (int i = 1; i <= n; i++ )
            uf[i] = i;

        int[][] edges = new int[m][2];
        for (int i = 0; i < m; i++) {
            edges[i][0] = nextInt();
            edges[i][1] = nextInt();
        }
        // Please write your code here.

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int rootU = find(u);
            int rootV = find(v);

            if (rootU == rootV) {
                System.out.println(i + 1);
                return;
            } else {
                uf[rootU] = rootV;
            }
        }

        System.out.println("happy");
    }

    static int find(int x) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x]);
        return uf[x];
    }
}