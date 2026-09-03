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
        
        for (int i = 0; i < m; i++) {
            int qType = nextInt();

            int a = nextInt();
            int b = nextInt();
            // Please write your code here.

            if (qType == 0) {
                uf[find(uf[a])] = find(uf[b]);
            } else {
                System.out.println(find(uf[a]) == find(uf[b]) ? 1 : 0);
            }
        }
    }

    static int find(int x) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x]);
        return uf[x];
    }
}