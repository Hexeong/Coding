import java.util.*;
import java.io.*;

public class Main {

    static int n, m, k;
    static int[] people;
    static Map<Integer, List<Integer>> edges = new HashMap<>();
    static int[][] dist;

    public static void main(String[] args) throws IOException {
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            
            edges.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
        }

        people = new int[k];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            people[i] = Integer.parseInt(st.nextToken()) - 1;
        }

        dist = new int[k][n];
        for (int i = 0; i < k; i++)
            Arrays.fill(dist[i], Integer.MAX_VALUE);

        // 1. 전시장에 관심이 있는 사람의 수마다 각 노드에 대한 최소 거리를 다익스트라로 구한다.
        // m * logn * k < 100000 * 20 * 10 = 20,000,000 = 2천만
        for (int i = 0; i < k; i++)
            dijkstra(people[i], i);

        // 2. n * k의 시간 복잡도로 답을 구한다.
        int minOfMax = Integer.MAX_VALUE;
        for (int node = 0; node < n; node++) {
            int max = 0;
            for (int i = 0; i < k; i++) {
                if (dist[i][node] == Integer.MAX_VALUE) {
                    max = Integer.MAX_VALUE;
                    break;
                }
                max = Math.max(max, dist[i][node]);
            }

            minOfMax = Math.min(minOfMax, max);
        }

        // for (int i = 0; i < k; i++) {
        //     System.out.println(people[i] + " node :");
        //     for (int j = 0; j < n; j++)
        //         System.out.print(dist[i][j] + " ");
        //     System.out.println("\n");
        // } 

        System.out.print(minOfMax == Integer.MAX_VALUE ? -1 : minOfMax);
    }

    static void dijkstra(int start, int stIdx) {
        // 0이 노드 번호, 1이 거리
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[1] == a[1]) return a[0] - b[0];
            return a[1] - b[1];
        });
        dist[stIdx][start] = 0;
        pq.offer(new int[]{start, 0});

        while(!pq.isEmpty()) {
            int[] cur = pq.poll();

            if (dist[stIdx][cur[0]] < cur[1]) continue;

            for (Integer next : edges.getOrDefault(cur[0], new ArrayList<>())) {

                if (dist[stIdx][next] <= cur[1] + 1) continue;

                dist[stIdx][next] = cur[1] + 1;
                pq.offer(new int[]{next, cur[1] + 1});
            }
        }
    } 
}