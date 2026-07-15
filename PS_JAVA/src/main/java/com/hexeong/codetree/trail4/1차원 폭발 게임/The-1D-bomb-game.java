import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Please write your code here.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Deque<Integer> cur = new ArrayDeque<>();
        for (int i = 0; i < n; i++)
            cur.offerLast(Integer.parseInt(br.readLine()));

        boolean flag = true;
        while (flag) {
            flag = false;

            Deque<int[]> round = new ArrayDeque<>();
            while (!cur.isEmpty()) {
                int t = cur.pollFirst();

                if (!round.isEmpty() && round.peekLast()[0] == t) {
                    round.offerLast(new int[]{t, round.peekLast()[1] + 1});
                } else {
                    if (!round.isEmpty() && round.peekLast()[1] >= m) {
                        int cnt = round.peekLast()[1];
                        while (cnt > 0) {
                            round.pollLast();
                            cnt--;
                        }
                        flag = true;
                    }
                    round.offerLast(new int[]{t, 1});
                }
            }

            if (!round.isEmpty() && round.peekLast()[1] >= m) {
                int cnt = round.peekLast()[1];
                while (cnt > 0) {
                    round.pollLast();
                    cnt--;
                }
                flag = true;
            }

            while (!round.isEmpty()) {
                int t = round.pollFirst()[0];
                // System.out.print(t + " ");
                cur.offerLast(t);
            }
            // System.out.println();
        }

        System.out.println(cur.size());
        while (!cur.isEmpty())
            System.out.println(cur.pollFirst());
    }
}