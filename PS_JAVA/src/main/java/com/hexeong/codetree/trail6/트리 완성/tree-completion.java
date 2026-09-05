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
        for (int i = 1; i <= n; i++)
            uf[i] = i;

        int cntToCut = 0;
        for (int i = 0; i < m; i++) {
            int u = nextInt();
            int v = nextInt();

            int rootU = find(u);
            int rootV = find(v);
            
            if (rootU == rootV) {
                cntToCut++;
            } else {
                uf[rootU] = rootV;
            }
        }
        // Please write your code here.

        boolean[] isRoot = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            isRoot[find(i)] = true;
        }

        int cntToAdd = 0;
        for (int i = 1; i <= n; i++)
            if (isRoot[i])
                cntToAdd++;
        
        System.out.println(cntToCut + cntToAdd - 1);
    }

    static int find(int x) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x]);
        return uf[x];
    }
}