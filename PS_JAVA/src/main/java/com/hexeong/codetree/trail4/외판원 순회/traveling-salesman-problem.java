import java.util.*;

public class Main {

    static int n;
    static int[][] adj;
    static boolean[] visited;

    static int minV = Integer.MAX_VALUE;

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        adj = new int[n][n];
        visited = new boolean[n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = sc.nextInt();

        visited[0] = true;;
        backT(0, 1, 0);

        System.out.println(minV);
    }

    private static void backT(int sum, int cnt, int last) {
        if (cnt == n) {
            if (adj[last][0] == 0)
                return;

            minV = Math.min(minV, sum + adj[last][0]);
            return;
        }

        if (sum > minV)
            return;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            if (adj[last][i] == 0) continue;

            visited[i] = true;
            backT(sum + adj[last][i], cnt + 1, i);
            visited[i] = false;
        }
    }
}