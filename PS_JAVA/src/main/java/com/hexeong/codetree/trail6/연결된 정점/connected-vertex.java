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
    static int[] cnt;

    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();

        uf = new int[n + 1];
        cnt = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            uf[i] = i;
            cnt[i] = 1;
        }
        
        for (int i = 0; i < m; i++) {
            String qType = next();
            // Please write your code here.

            if (qType.equals("x")) {
                int a = nextInt();
                int b = nextInt();
                
                int rootA = find(a);
                int rootB = find(b);
                
                if (rootA != rootB) {
                    uf[rootA] = rootB;
                    cnt[rootB] += cnt[rootA]; // 새로운 루트(rootB)에 크기 누적
                }
            } else {
                int a = nextInt();
                System.out.println(cnt[find(a)]);
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