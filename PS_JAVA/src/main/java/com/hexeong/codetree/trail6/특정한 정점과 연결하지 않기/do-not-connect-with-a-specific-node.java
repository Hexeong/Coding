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

    static int n, m, A, B, k;
    static int[] uf;

    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();
        uf = new int[n + 1];
        for (int i = 1; i <= n; i++)
            uf[i] = i;
        
        for (int i = 0; i < m; i++) {
            int x = nextInt();
            int y = nextInt();

            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY)
                uf[rootX] = rootY;
        }

        A = nextInt();
        B = nextInt();
        k = nextInt();
        // Please write your code here.

        int rootA = find(A);
        int rootB = find(B);
        int[] nodeCnt = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int r = find(i);
            nodeCnt[r]++;
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return b - a;
        });

        for (int i = 1; i <= n; i++) {
            if (nodeCnt[i] > 0 && i != rootA && i != rootB)
                pq.add(nodeCnt[i]);
        }

        int res = nodeCnt[rootA];
        for (int i = 0; i < k; i++) {
            if (pq.isEmpty()) break;

            res += pq.poll();
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