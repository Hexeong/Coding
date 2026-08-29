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

    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};

    static int a, b, n;

    static int res = 0;

    static int[][] dist;
    static char[][] brackets;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();
        brackets = new char[n][n];
        dist = new int[n][n];

        for (int i = 0; i < n; i++) {
            String row = sc.next();
            for (int j = 0; j < n; j++) {
                brackets[i][j] = row.charAt(j);
            }
        }
        // Please write your code here.

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dijkstra(i, j);
            }
        }

        System.out.println(res);
    }

    static void dijkstra(int sty, int stx) {
        for (int i = 0; i < n; i++)
            Arrays.fill(dist[i], Integer.MAX_VALUE);

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[2] - b[2];
        });

        pq.add(new int[]{sty, stx, 0});
        dist[sty][stx] = 0;

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();

            if (dist[cur[0]][cur[1]] < cur[2]) continue;

            for (int i = 0; i < 4; i++) {
                int ny = cur[0] + dy[i];
                int nx = cur[1] + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

                int nw = cur[2] + (brackets[cur[0]][cur[1]] == brackets[ny][nx] ? a : b);
                if (dist[ny][nx] > nw) {
                    dist[ny][nx] = nw;
                    pq.add(new int[]{ny, nx, nw});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = Math.max(res, dist[i][j]);
            }
        }
    }
}