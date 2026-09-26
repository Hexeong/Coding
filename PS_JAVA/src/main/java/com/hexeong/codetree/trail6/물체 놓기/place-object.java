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

    static int n;
    static int[] directCost;
    static int[][] costMatrix;

    public static void main(String[] args) {
        n = nextInt();
        directCost = new int[n];
        for (int i = 0; i < n; i++) {
            directCost[i] = nextInt();
        }
        costMatrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costMatrix[i][j] = nextInt();
            }
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        int[] minCost = new int[n];
        Arrays.fill(minCost, Integer.MAX_VALUE);

        // 모든 정점을 직접 놓는 비용으로 초기화하며 큐에 넣습니다.
        for (int i = 0; i < n; i++) {
            minCost[i] = directCost[i];
            pq.add(new int[]{directCost[i], i});
        }

        boolean[] inMST = new boolean[n];

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int cost = cur[0];
            int u = cur[1];

            if (inMST[u]) continue;
            if (minCost[u] < cost) continue; // 이미 더 작은 비용으로 갱신되었다면 스킵
            inMST[u] = true;

            // u번 정점이 확정되었으므로, u와 연결된 다른 정점들의 최소 비용을 갱신합니다.
            for (int i = 0; i < n; i++) {
                if (i == u || inMST[i]) continue;

                // 1. u번 정점을 거쳐서 i번으로 가는 연결 비용이 더 싼 경우
                if (minCost[i] > costMatrix[u][i]) {
                    minCost[i] = costMatrix[u][i];
                    pq.add(new int[]{minCost[i], i});
                }
            }
        }

        // minCost에 담긴 모든 최소 비용의 합이 정답
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += minCost[i];
        }

        System.out.println(sum);
    }
}