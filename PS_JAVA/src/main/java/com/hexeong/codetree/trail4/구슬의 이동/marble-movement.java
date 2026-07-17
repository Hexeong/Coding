import java.util.*;
import java.io.*;

public class Main {

    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        // Please write your code here.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Item[] bead = new Item[M + 1];

        for (int m = 1; m <= M; m++) {
            st = new StringTokenizer(br.readLine());

            int r = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken()) - 1;
            char d = st.nextToken().charAt(0);
            int v = Integer.parseInt(st.nextToken());

            int dir = -1;
            if (d == 'U') dir = 0;
            if (d == 'D') dir = 1;
            if (d == 'R') dir = 2;
            if (d == 'L') dir = 3;

            bead[m] = new Item(m, r, c, dir, v);
        }

        for (int t = 0; t < T; t++) {

            List<Item>[][] grid = new List[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    grid[i][j] = new ArrayList<>();

            for (int m = 1; m <= M; m++) {
                if (bead[m].v == 0) continue;

                move(bead, m, n);

                grid[bead[m].r][bead[m].c].add(bead[m]);
            }

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (grid[i][j].size() <= K) continue;

                    grid[i][j].sort((a, b) -> {
                        if (a.v == b.v) return b.num - a.num;
                        return b.v - a.v; 
                    });

                    for (int k = K; k < grid[i][j].size(); k++)
                        bead[grid[i][j].get(k).num].v = 0;
                }
        }

        int cnt = 0;
        for (int i = 1; i <= M; i++)
            if (bead[i].v != 0)
                cnt++;

        System.out.println(cnt);
    }

    // 13, n = 5, 

    private static void move(Item[] bead, int num, int n) {
        int ny = bead[num].r + dy[bead[num].dir] * bead[num].v;
        int nx = bead[num].c + dx[bead[num].dir] * bead[num].v;

        // 1. ny(행)가 격자 범위를 벗어나는 경우 (상하 이동)
        while (ny < 0 || ny >= n) {
            if (ny < 0) {
                ny = -ny; // 0번 벽에 부딪히고 튕겨 나온 위치
                bead[num].dir = reverseDir(bead[num].dir);
            } else if (ny >= n) {
                ny = 2 * n - 2 - ny; // n-1번 벽에 부딪히고 튕겨 나온 위치
                bead[num].dir = reverseDir(bead[num].dir);
            }
        }

        // 2. nx(열)가 격자 범위를 벗어나는 경우 (좌우 이동)
        while (nx < 0 || nx >= n) {
            if (nx < 0) {
                nx = -nx;
                bead[num].dir = reverseDir(bead[num].dir);
            } else if (nx >= n) {
                nx = 2 * n - 2 - nx;
                bead[num].dir = reverseDir(bead[num].dir);
            }
        }
        
        // 3. 최종 계산된 위치로 구슬 정보 갱신
        bead[num].r = ny;
        bead[num].c = nx;
    }

    private static int reverseDir(int dir) {
        if (dir == 0) return 1; // U -> D
        if (dir == 1) return 0; // D -> U
        if (dir == 2) return 3; // R -> L
        if (dir == 3) return 2; // L -> R
        return dir;
    }

    static class Item {
        int num;
        int r;
        int c;
        int dir;
        int v;
        public Item(int num, int r, int c, int dir, int v) {
            this.num = num;
            this.r = r;
            this.c = c;
            this.dir = dir;
            this.v = v;
        }
    }
}