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
    static int[] parents;
    static int[] depth;
    static List<Integer>[] edges;

    public static void main(String[] args) {
        int n = nextInt();
        parents = new int[n + 1];
        depth = new int[n + 1];
        edges = new List[n + 1];
        for (int i = 0; i <= n; i++)
            edges[i] = new ArrayList<>();
        
        for (int i = 1; i <= n - 1; i++) {
            int p = nextInt();
            int x = nextInt();

            parents[x] = p;
            edges[p].add(x);
        }
        int a = nextInt();
        int b = nextInt();
        // Please write your code here.

        int root = 0;
        for (int i = 1; i <= n; i++) {
            if (parents[i] == 0) {
                root = i;
                break;
            }
        }

        setDepth(root, 0);

        if (depth[a] > depth[b]) { // 항상 a의 depth가 작게 유지
            int tmp = a;
            a = b;
            b = tmp;
        }

        while (depth[a] != depth[b]) { // a와 b의 depth가 같아질 때까지 진행
            b = parents[b];
        }

        while (a != b) { // a와 b의 부모가 같아질 때까지
            a = parents[a];
            b = parents[b];
        }

        System.out.println(a);
    }

    static void setDepth(int cur, int prev) {
        depth[cur] = depth[prev] + 1;
        for (int next : edges[cur]) {
            setDepth(next, cur);
        }
    }
}