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

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[0] - b[0];
        });

        for (int i = 0; i < m; i++) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            int w = nextInt();

            pq.add(new int[]{w, u, v});
        }
        // Please write your code here.

        uf = new int[n];
        for (int i = 0; i < n; i++)
            uf[i] = i;

        int cnt = 0;
        int sum = 0;
        while (!pq.isEmpty() && cnt < n - 2) {
            int[] cur = pq.poll();

            int uP = find(cur[1]);
            int vP = find(cur[2]);

            if (uP == vP) continue;

            uf[uP] = vP;
            cnt++;
            sum += cur[0];
        }

        System.out.println(sum);
    }

    static int find(int x) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x]);
        return uf[x];
    }
}