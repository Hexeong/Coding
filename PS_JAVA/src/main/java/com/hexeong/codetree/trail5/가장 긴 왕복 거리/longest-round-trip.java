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

    public static void main(String[] args) {

        Map<Integer, List<int[]>> adj = new HashMap<>();
        Map<Integer, List<int[]>> reverseAdj = new HashMap<>();

        n = nextInt();
        m = nextInt();
        x = nextInt();
        for (int i = 0; i < m; i++) {
            int u = nextInt();
            int v = nextInt();
            int w = nextInt();

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, w});
            reverseAdj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[]{u, w});
        }
        // Please write your code here.

        int[] dist = new int[n + 1];
        int[] revDist = new int[n + 1];

        dijkstra(adj, dist);
        dijkstra(reverseAdj, revDist);

        int res = 0;
        for (int i = 1; i <= n; i++) {
            // System.out.println(dist[i] + " " + revDist[i]);
            res = Math.max(res, dist[i] + revDist[i]);
        }

        System.out.println(res);
    }

    static void dijkstra(Map<Integer, List<int[]>> adj, int[] dist) {
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[x] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[1] - b[1];
        });

        pq.add(new int[]{x, 0});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();

            if (dist[cur[0]] < cur[1]) continue;

            for (int[] edge : adj.getOrDefault(cur[0], new ArrayList<>())) {
                int nn = edge[0];
                int nw = edge[1];

                if (dist[nn] > cur[1] + nw) {
                    dist[nn] = cur[1] + nw;
                    pq.add(new int[]{nn, dist[nn]});
                }
            }
        }
    }
}