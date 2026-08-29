import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static Map<Integer, List<int[]>> adj = new HashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = nextInt();
        int m = nextInt();
        int a = nextInt();
        int b = nextInt();
        int c = nextInt();
        int[][] edges = new int[m][3];
        for (int i = 0; i < m; i++) {
            int u = nextInt();
            int v = nextInt();
            int w = nextInt();

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, w});
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[]{u, w});
        }
        // Please write your code here.

        long[] aDist = new long[n + 1];
        long[] bDist = new long[n + 1];
        long[] cDist = new long[n + 1];
        dijkstra(aDist, a);
        dijkstra(bDist, b);
        dijkstra(cDist, c);

        long res = 0;
        for (int i = 1; i <= n; i++) {

            long closest = Long.MAX_VALUE;
            closest = Math.min(closest, aDist[i]);
            closest = Math.min(closest, bDist[i]);
            closest = Math.min(closest, cDist[i]);

            res = Math.max(res, closest);
        }

        System.out.println(res);
    }

    static void dijkstra(long[] dist, int start) {
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> {
            return Long.compare(a[1], b[1]);
        });

        pq.add(new long[]{start, 0});
        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            int cn = (int) cur[0];

            if (dist[cn] < cur[1]) continue;

            for (int[] n : adj.getOrDefault(cn, new ArrayList<>())) {
                long nw = (long) n[1];

                if (dist[n[0]] >= cur[1] + nw) {
                    dist[n[0]] = cur[1] + nw;
                    pq.add(new long[]{n[0], dist[n[0]]});
                }
            }
        }
    }

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
}