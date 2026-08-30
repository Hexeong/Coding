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

    static int n, m, x;

    static long[] dist;

    static long res = Long.MAX_VALUE;

    static Map<Integer, List<int[]>> adj = new HashMap<>();

    public static void main(String[] args) {

        n = nextInt();
        m = nextInt();
        x = nextInt();

        int[] cList = new int[m];

        for (int i = 0; i < m; i++) {
            int I = nextInt();
            int J = nextInt();
            int L = nextInt();
            int C = nextInt();

            cList[i] = C;

            adj.computeIfAbsent(I, k -> new ArrayList<>()).add(new int[]{J, L, C});
            adj.computeIfAbsent(J, k -> new ArrayList<>()).add(new int[]{I, L, C});
        }
        // Please write your code here.

        Arrays.sort(cList);

        dist = new long[n + 1];

        for (int i = 0; i < m; i++) {
            dijkstra(cList[i]);
        }

        System.out.println(res);
    }

    static void dijkstra(int c) {
        Arrays.fill(dist, Long.MAX_VALUE);

        dist[1] = 0;
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> {
            return Long.compare(a[1], b[1]);
        });

        pq.add(new long[]{1, 0, 0, c});

        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            int cn = (int) cur[0];

            if (dist[cn] < cur[1]) continue;
            if ((long) c < cur[3]) continue;

            for (int[] edge : adj.getOrDefault(cn, new ArrayList<>())) {
                long nl = cur[2] + (long) edge[1];
                long nc = Math.min(cur[3], (long) edge[2]);

                if (dist[edge[0]] > nl + (long) x / nc) {
                    dist[edge[0]] = nl + x / nc;
                    pq.add(new long[]{(long) edge[0], dist[edge[0]], nl, nc});
                }
            }
        }

        res = Math.min(res, dist[n]);
    }
}