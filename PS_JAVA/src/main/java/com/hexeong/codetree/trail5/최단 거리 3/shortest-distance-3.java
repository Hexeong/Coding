import java.util.*;
public class Main {

    static Map<Integer, List<int[]>> adj = new HashMap<>();
    static int[] dist;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, w});
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[]{u, w});
        }
        int a = sc.nextInt();
        int b = sc.nextInt();
        // Please write your code here.

        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> {
            return x[1] - y[1];
        });
        dist[a] = 0;
        pq.add(new int[]{a, 0});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();

            if (dist[cur[0]] < cur[1]) continue;

            for (int[] next : adj.getOrDefault(cur[0], new ArrayList<>())) {

                if (dist[next[0]] >= cur[1] + next[1]) {
                    pq.add(new int[]{next[0], cur[1] + next[1]});
                    dist[next[0]] = cur[1] + next[1];
                }
            }
        }

        System.out.println(dist[b]);
    }
}