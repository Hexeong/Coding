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

    static int n, cityCnt;
    static int[][] grid;
    static int[] uf;
    static PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
        return a[0] - b[0];
    });

    public static void main(String[] args) {
        n = nextInt();
        grid = new int[n][n];

        List<int[]> city = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = nextInt();
                if (grid[i][j] == 2 || grid[i][j] == 1) 
                    city.add(new int[]{i, j});
            }
        }
        // Please write your code here.
        uf = new int[n * n];
        for (int i = 0; i < n * n; i++)
            uf[i] = i;
        
        // 모든 정점간 거리를 bfs로 구해서 pq에 넣기
        bfs(city);

        int sum = 0;
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();

            int uP = find(cur[1]);
            int vP = find(cur[2]);

            if (uP == vP) continue;

            sum += cur[0];
            uf[uP] = vP;
        }

        int baseP = find(city.get(0)[0] * n + city.get(0)[1]);
        for (int i = 1; i < city.size(); i++) {
            int cP = find(city.get(i)[0] * n + city.get(i)[1]);

            if (baseP != cP) {
                System.out.println(-1);
                return;
            }
        }

        System.out.println(sum);
    }

    static int find(int x) {
        if (uf[x] == x)
            return x;

        uf[x] = find(uf[x]);
        return uf[x];
    }

    static int[] dy = {-1, 0 ,1, 0};
    static int[] dx = {0, 1, 0, -1};

    static void bfs(List<int[]> city) {
        boolean[][] visited = new boolean[n][n];

        for (int[] c : city) {
            for (int i = 0; i < n; i++)
                Arrays.fill(visited[i], false);

            Queue<int[]> q = new LinkedList<>();
            visited[c[0]][c[1]] = true;
            q.add(new int[]{0, c[0], c[1]});

            while (!q.isEmpty()) {
                int[] cur = q.poll();

                for (int i = 0; i < 4; i++) {
                    int ny = cur[1] + dy[i];
                    int nx = cur[2] + dx[i];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                    if (grid[ny][nx] == -1) continue;

                    if (!visited[ny][nx]) {
                        visited[ny][nx] = true;
                        q.add(new int[]{cur[0] + 1, ny, nx});
                        if (grid[ny][nx] == 1 || grid[ny][nx] == 2)
                            pq.add(new int[]{cur[0] + 1, c[0] * n + c[1], ny * n + nx});
                    }
                }
            }
        }
    }
}