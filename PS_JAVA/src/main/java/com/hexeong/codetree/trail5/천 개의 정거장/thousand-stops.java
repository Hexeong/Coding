import java.util.*;

public class Main {
    static Map<Integer, List<int[]>> adj = new HashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            int cost = sc.nextInt();
            int stopCount = sc.nextInt();

            int lastStop = sc.nextInt();
            for (int j = 0; j < stopCount - 1; j++) {
                int stop = sc.nextInt();
                adj.computeIfAbsent(lastStop, k -> new ArrayList<>()).add(new int[]{stop, cost, i});
                lastStop = stop;
            }
        }

        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[1] == b[1]) return Long.compare(a[2], b[2]);
            return Long.compare(a[1], b[1]);
        });

        // 1. 2차원 배열로 변경 [정점 번호][노선 번호]
        // N번 인덱스는 맨 처음 '아무 버스도 타지 않은 상태'를 위해 사용합니다.
        long[][] cost = new long[1001][N + 1];
        long[][] time = new long[1001][N + 1];
        
        for (int i = 0; i <= 1000; i++) {
            Arrays.fill(cost[i], Long.MAX_VALUE);
            Arrays.fill(time[i], Long.MAX_VALUE);
        }

        cost[A][N] = 0;
        time[A][N] = 0;
        pq.add(new long[]{A, 0, 0, N}); // 초기 노선 번호를 -1 대신 N으로 설정(배열 인덱스로 쓰기 위함)

        while(!pq.isEmpty()) {
            long[] cur = pq.poll();
            int u = (int) cur[0];
            long c = cur[1];
            long t = cur[2];
            int route = (int) cur[3];

            // 2. 현재 정점과 '현재 타고 있는 버스 노선' 상태에 대해 방문 검사
            if (cost[u][route] < c) continue;
            if (cost[u][route] == c && time[u][route] < t) continue;

            for (int[] edge : adj.getOrDefault(u, new ArrayList<>())) {
                int next = edge[0];
                long routeCost = edge[1];
                int nextRoute = edge[2];

                long nextC = c;
                // 3. 타고 있는 노선과 다음 노선이 다르면 환승(비용 추가)
                if (route != nextRoute) {
                    nextC += routeCost;
                }
                long nextT = t + 1;

                // 4. 다음 정점의 '해당 노선을 탄 상태'를 갱신
                if (cost[next][nextRoute] > nextC) {
                    cost[next][nextRoute] = nextC;
                    time[next][nextRoute] = nextT;
                    pq.add(new long[]{next, nextC, nextT, nextRoute});
                } else if (cost[next][nextRoute] == nextC && time[next][nextRoute] > nextT) {
                    cost[next][nextRoute] = nextC;
                    time[next][nextRoute] = nextT;
                    pq.add(new long[]{next, nextC, nextT, nextRoute});
                }
            }
        }

        // 5. 도착점 B에서 '모든 노선 상태' 중 가장 최소 비용과 최소 시간을 찾음
        long minCost = Long.MAX_VALUE;
        long minTime = Long.MAX_VALUE;
        for (int i = 0; i <= N; i++) {
            if (cost[B][i] < minCost) {
                minCost = cost[B][i];
                minTime = time[B][i];
            } else if (cost[B][i] == minCost && time[B][i] < minTime) {
                minTime = time[B][i];
            }
        }

        if (minCost == Long.MAX_VALUE) {
            System.out.println("-1 -1");
        } else {
            System.out.println(minCost + " " + minTime);
        }
    }
}