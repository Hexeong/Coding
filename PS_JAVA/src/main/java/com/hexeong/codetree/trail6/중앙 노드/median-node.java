import java.util.*;
import java.io.*;

public class Main {

    static int n, r;
    static Map<Integer, List<Integer>> adj = new HashMap<>();
    static int min = Integer.MAX_VALUE, max = 0;

    public static void main(String[] args) {
        // Please write your code here.
        n = nextInt();
        r = nextInt();
        for (int i = 2; i <= n; i++) {
            int a = nextInt();
            int b = nextInt();

            adj.computeIfAbsent(a, x -> new ArrayList<>()).add(b);
            adj.computeIfAbsent(b, x -> new ArrayList<>()).add(a);
        }

        int st = r;
        Set<Integer> set = new HashSet<>();
        set.add(st);
        while (true) {
            int nextCnt = 0;
            int nextTarget = -1;
            
            for (int n : adj.getOrDefault(st, Collections.emptyList())) {
                if (set.contains(n)) continue;

                nextCnt++;
                nextTarget = n;
            }

            if (nextCnt == 1) {
                st = nextTarget;
                set.add(st);
            } else
                break;
        }

        // 중앙노드 설정 완료
        set = new HashSet<>();
        set.add(st);
        for (int child : adj.get(st)) {
            int childCnt = dfs(child, set);

            max = Math.max(childCnt, max);
            min = Math.min(childCnt, min);
        }

        System.out.println(max - min);
    }

    static int dfs(int cur, Set<Integer> set) {
        if (!adj.containsKey(cur) || adj.get(cur).isEmpty())
            return 1;

        set.add(cur);
        int cnt = 1;
        for (int next : adj.getOrDefault(cur, Collections.emptyList())) {
            if (set.contains(next)) continue;

            set.add(next);
            int subCnt = dfs(next, set);
            cnt += subCnt;
        }

        return cnt;
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
