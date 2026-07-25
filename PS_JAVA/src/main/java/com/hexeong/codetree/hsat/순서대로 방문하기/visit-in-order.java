import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    // 다음 문자열(토큰)을 읽어오는 메서드
    static String next() {
        // StringTokenizer가 비어있거나, 더 이상 읽을 토큰이 없을 때만 새로운 줄을 읽어옴
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    // 다음 정수를 읽어오는 메서드
    static int nextInt() {
        return Integer.parseInt(next());
    }

    static int n, m;
    static int[][] grid;
    static boolean[][] isTarget;
    static int[][] target;
    static boolean[][] visited;

    static int[] dy = {1, 0, -1, 0};
    static int[] dx = {0, -1, 0, 1};

    static long ans = 0;

    public static void main(String[] args) {
        // Please write your code here.
        n = nextInt();
        m = nextInt();
        grid = new int[n][n];
        isTarget = new boolean[n][n];
        visited = new boolean[n][n];
        target = new int[m][2];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = nextInt();
        
        for (int i = 0; i < m; i++) {
            target[i][0] = nextInt() - 1;
            target[i][1] = nextInt() - 1;

            isTarget[target[i][0]][target[i][1]] = true;
        }

        visited[target[0][0]][target[0][1]] = true;
        dfs(target[0][0], target[0][1], 1);

        System.out.println(ans);
    }

    static void dfs(int cy, int cx, int cidx) {
        if (cidx == target.length) {
            ans++;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            // 격자를 벗어나는지
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            // 나중에 방문해야 하는 칸에 도착했는지
            if (isTarget[ny][nx] && (ny != target[cidx][0] || nx != target[cidx][1])) continue;
            // 이미 방문한 칸이나 벽에 도착하려고 하는지
            if (visited[ny][nx] || grid[ny][nx] == 1) continue;

            visited[ny][nx] = true;
            dfs(ny, nx, (ny == target[cidx][0] && nx == target[cidx][1] ? cidx + 1 : cidx));
            visited[ny][nx] = false;
        }
    }
}