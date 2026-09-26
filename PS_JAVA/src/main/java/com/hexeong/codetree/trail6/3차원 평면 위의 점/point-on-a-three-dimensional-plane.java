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
    static int[][] points;
    static int[] uf;
    
    public static void main(String[] args) {
        n = nextInt();
        points = new int[n][4]; // [x, y, z, original_index]
        uf = new int[n];
        for (int i = 0; i < n; i++)
            uf[i] = i;
        
        for (int i = 0; i < n; i++) {
            points[i][0] = nextInt();
            points[i][1] = nextInt();
            points[i][2] = nextInt();
            points[i][3] = i; // 원래 인덱스 저장
        }
        
        List<int[]> edges = new ArrayList<>();

        // 1. X 기준 정렬 후 인접한 점들 간선 후보 추가
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        for (int i = 0; i < n - 1; i++) {
            int u = points[i][3];
            int v = points[i + 1][3];
            int cost = Math.min(Math.abs(points[i][0] - points[i+1][0]),
                       Math.min(Math.abs(points[i][1] - points[i+1][1]),
                                Math.abs(points[i][2] - points[i+1][2])));
            edges.add(new int[]{cost, u, v});
        }

        // 2. Y 기준 정렬 후 인접한 점들 간선 후보 추가
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        for (int i = 0; i < n - 1; i++) {
            int u = points[i][3];
            int v = points[i + 1][3];
            int cost = Math.min(Math.abs(points[i][0] - points[i+1][0]),
                       Math.min(Math.abs(points[i][1] - points[i+1][1]),
                                Math.abs(points[i][2] - points[i+1][2])));
            edges.add(new int[]{cost, u, v});
        }

        // 3. Z 기준 정렬 후 인접한 점들 간선 후보 추가
        Arrays.sort(points, (a, b) -> Integer.compare(a[2], b[2]));
        for (int i = 0; i < n - 1; i++) {
            int u = points[i][3];
            int v = points[i + 1][3];
            int cost = Math.min(Math.abs(points[i][0] - points[i+1][0]),
                       Math.min(Math.abs(points[i][1] - points[i+1][1]),
                                Math.abs(points[i][2] - points[i+1][2])));
            edges.add(new int[]{cost, u, v});
        }

        // 간선 가중치 오름차순 정렬
        edges.sort((a, b) -> Integer.compare(a[0], b[0]));

        long totalCost = 0;
        int edgeCount = 0;

        // 크루스칼 알고리즘 수행
        for (int[] edge : edges) {
            int cost = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (find(u) != find(v)) {
                union(u, v);
                totalCost += cost;
                edgeCount++;
                if (edgeCount == n - 1) break;
            }
        }

        System.out.println(totalCost);
    }

    static int find(int x) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x]);
        return uf[x];
    }

    static void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            uf[rootX] = rootY;
        }
    }
}