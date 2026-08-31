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

    static int n, m;
    static Map<Integer, List<long[]>> adj = new HashMap<>();

    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();

        for (int i = 0; i < m; i++) {
            int u = nextInt();
            int v = nextInt();
            long w = nextLong();

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new long[]{v, w});
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new long[]{u, w});
        }

        // 1. 기존 최단 거리 계산 및 경로 추적
        int[] parent = new int[n + 1];
        long origDist = dijkstra(-1, -1, parent);

        long maxDist = 0;
        int curr = n;
        
        // 2. 원래 최단 경로를 구성하는 간선들을 하나씩 2배로 늘려보며 최단 거리 재계산
        while (curr != 1 && parent[curr] != 0) {
            int prev = parent[curr];
            // prev <-> curr 간선만 2배로 늘려서 다익스트라 실행
            long newDist = dijkstra(curr, prev, null);
            maxDist = Math.max(maxDist, newDist);
            
            curr = prev;
        }

        // 3. (간선 1개를 2배 늘린 최단 거리 중 최댓값) - (기존 최단 거리) 출력
        System.out.println(maxDist - origDist);
    }

    // doubleU, doubleV를 잇는 간선만 가중치를 2배로 계산하는 다익스트라
    static long dijkstra(int doubleU, int doubleV, int[] parent) {
        long[] dist = new long[n + 1];
        Arrays.fill(dist, Long.MAX_VALUE);
        
        dist[1] = 0;
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> {
            return Long.compare(a[1], b[1]);
        });
        
        pq.add(new long[]{1, 0}); 

        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            int cn = (int) cur[0];
            long cw = cur[1];

            if (dist[cn] < cw) continue;
            
            // 최단 경로 탐색만 할 경우 목적지 도착 시 조기 종료 가능
            if (cn == n && parent == null) return dist[n];

            for (long[] edge : adj.getOrDefault(cn, new ArrayList<>())) {
                int nn = (int) edge[0];
                long w = edge[1];

                // 현재 확인 중인 간선이 2배로 늘리기로 지정한 간선인지 체크
                if ((cn == doubleU && nn == doubleV) || (cn == doubleV && nn == doubleU)) {
                    w *= 2;
                }

                if (dist[nn] > cw + w) {
                    dist[nn] = cw + w;
                    // parent 배열이 주어졌을 때만 경로 기록 (최초 1회만 수행됨)
                    if (parent != null) {
                        parent[nn] = cn;
                    }
                    pq.add(new long[]{nn, dist[nn]});
                }
            }
        }
        
        return dist[n];
    }
}