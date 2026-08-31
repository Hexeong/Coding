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

    static long nextLong() {
        return Long.parseLong(next());
    }

    static long[][] dist;
    static int n, m;

    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();
        dist = new long[n][n];
        for (int i = 0; i < n; i++)
            Arrays.fill(dist[i], Long.MAX_VALUE);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = nextLong();

        floydWarshall();
        
        for (int i = 0; i < m; i++) {
            int a = nextInt();
            int b = nextInt();

            System.out.println(dist[a - 1][b - 1]);
        }
        // Please write your code here.
    }

    static void floydWarshall() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}