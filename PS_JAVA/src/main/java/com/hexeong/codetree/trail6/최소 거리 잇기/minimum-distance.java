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
    static int[][] points;
    static int[][] edges;

    static int[] uf;

    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();
        points = new int[n][2];
        for (int i = 0; i < n; i++) {
            points[i][0] = nextInt(); // x
            points[i][1] = nextInt(); // y
        }
        edges = new int[m][2];
        for (int i = 0; i < m; i++) {
            edges[i][0] = nextInt() - 1;
            edges[i][1] = nextInt() - 1;
        }

        uf = new int[n];
        for (int i = 0; i < n; i++)
            uf[i] = i;

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int uP = find(u);
            int vP = find(v);

            if (uP == vP) continue;

            uf[uP] = vP;
        }

        // 거리와 가중치를 실수(double)로 다루도록 PriorityQueue 타입 변경
        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> {
            return Double.compare(a.dist, b.dist);
        });

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int uP = find(i);
                int vP = find(j);

                if (uP == vP) continue;

                // 유클리드 거리 (피타고라스 방식) 계산
                double dx = points[i][0] - points[j][0];
                double dy = points[i][1] - points[j][1];
                double dist = Math.sqrt(dx * dx + dy * dy);

                pq.add(new Edge(dist, i, j));
            }

        double sum = 0;
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();

            int uP = find(cur.u);
            int vP = find(cur.v);

            if (uP == vP) continue;

            uf[uP] = vP;
            sum += cur.dist;
        }

        // 소수점 둘째 자리까지 출력
        System.out.printf("%.2f\n", sum);
    }

    static int find(int x) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x]);
        return uf[x];
    }

    static class Edge {
        double dist;
        int u, v;

        public Edge(double dist, int u, int v) {
            this.dist = dist;
            this.u = u;
            this.v = v;
        }
    }
}