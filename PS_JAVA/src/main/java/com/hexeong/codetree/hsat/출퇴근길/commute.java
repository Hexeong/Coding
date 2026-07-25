import java.util.*;
import java.io.*;

public class Main {

    static int n, m;
    static Map<Integer, List<Integer>> edges = new HashMap<>();
    static Map<Integer, List<Integer>> reverseEdges = new HashMap<>(); // 역방향 간선 추가

    public static void main(String[] args) {
        n = nextInt();
        m = nextInt();

        for (int i = 0; i < m; i++) {
            int x = nextInt();
            int y = nextInt();
            edges.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
            reverseEdges.computeIfAbsent(y, k -> new ArrayList<>()).add(x); // 역방향 간선 저장
        }

        int st = nextInt();
        int dest = nextInt();

        // 1. S -> 정방향 (S에서 갈 수 있는 곳)
        boolean[] fromS = new boolean[n + 1];
        fromS[dest] = true; // 출근길은 T에서 멈춰야 하므로 미리 벽을 세움
        dfs(st, edges, fromS);

        // 2. T -> 역방향 (T로 갈 수 있는 곳)
        boolean[] toT = new boolean[n + 1];
        dfs(dest, reverseEdges, toT);

        // 3. T -> 정방향 (T에서 갈 수 있는 곳)
        boolean[] fromT = new boolean[n + 1];
        fromT[st] = true; // 퇴근길은 S에서 멈춰야 하므로 벽을 세움
        dfs(dest, edges, fromT);

        // 4. S -> 역방향 (S로 갈 수 있는 곳)
        boolean[] toS = new boolean[n + 1];
        dfs(st, reverseEdges, toS);

        // 4개의 조건을 모두 만족하는 정점(S, T 제외) 카운트
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i == st || i == dest) continue; // 출퇴근 목적지 본인은 제외
            if (fromS[i] && toT[i] && fromT[i] && toS[i]) {
                ans++;
            }
        }

        System.out.println(ans);
    }

    static void dfs(int cur, Map<Integer, List<Integer>> graph, boolean[] visited) {
        visited[cur] = true;
        
        for (int next : graph.getOrDefault(cur, new ArrayList<>())) {
            if (!visited[next]) {
                dfs(next, graph, visited);
            }
        }
    }

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
}