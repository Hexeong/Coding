import java.util.*;
import java.io.*;

public class Main {

    static int maxV = 0;

    public static void main(String[] args) throws IOException {
        // Please write your code here.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        int[][] lines = new int[n][2];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());

            lines[i][0] = l;
            lines[i][1] = r;
        }

        boolean[] grid = new boolean[1001];

        for (int i = 0; i < n; i++) {
            backt(grid, lines, i, 0, n);
        }
        System.out.println(maxV);
    }

    private static void backt(boolean[] grid, int[][] lines, int cur, int cnt, int n) {
        // 놓을 수 없다면 리턴
        for (int p = lines[cur][0]; p <= lines[cur][1]; p++) {
            if (grid[p]) return;
        }

        for (int p = lines[cur][0]; p <= lines[cur][1]; p++) {
            grid[p] = true;
        }

        if (cnt + 1 > maxV)
            maxV = cnt + 1;
        
        for (int c = cur + 1; c < n; c++) {
            backt(grid, lines, c, cnt + 1, n);
        }

        for (int p = lines[cur][0]; p <= lines[cur][1]; p++) {
            grid[p] = false;
        }
    }
}