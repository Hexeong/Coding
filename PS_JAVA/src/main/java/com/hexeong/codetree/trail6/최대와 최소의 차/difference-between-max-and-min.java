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
    static int[][] edges;


    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[0] - b[0];
        });
        PriorityQueue<int[]> rpq = new PriorityQueue<>((a, b) -> {
            return b[0] - a[0];
        });
        for (int i = 0; i < m; i++) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            int w = nextInt();
            pq.add(new int[]{w, u, v});
            rpq.add(new int[]{w, u, v});
        }
        // Please write your code here.

        int aCnt = 0;
        int bCnt = 0;

        int[] uf = new int[n];
        for (int i = 0; i < n; i++)
            uf[i] = i;
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();

            int uP = find(cur[1], uf);
            int vP = find(cur[2], uf);

            if (uP == vP) continue;

            if (cur[0] == 0)
                aCnt++;
            uf[uP] = vP;
        }

        int[] ruf = new int[n];
        for (int i = 0; i < n; i++)
            ruf[i] = i;
        while (!rpq.isEmpty()) {
            int[] cur = rpq.poll();

            int uP = find(cur[1], ruf);
            int vP = find(cur[2], ruf);

            if (uP == vP) continue;

            if (cur[0] == 0)
                bCnt++;
            ruf[uP] = vP;
        }

        System.out.println(aCnt * aCnt - bCnt * bCnt);
    }

    static int find(int x, int[] uf) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x], uf);
        return uf[x];
    }
}