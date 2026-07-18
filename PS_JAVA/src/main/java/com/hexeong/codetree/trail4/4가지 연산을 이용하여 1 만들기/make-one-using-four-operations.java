import java.util.*;

public class Main {

    static int n;
    static int[] arr = new int[2000001];
    static int minV = Integer.MAX_VALUE;

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        Arrays.fill(arr, Integer.MAX_VALUE);

        solve(n);

        System.out.println(minV);
    }

    private static void solve(int cur) {
        Queue<Item> q = new LinkedList<>();
        q.add(new Item(cur, 0));
        arr[cur] = 0;

        while (!q.isEmpty()) {
            Item c = q.poll();

            if (c.cnt > minV)
                continue;

            if (c.val == 1) {
                minV = Math.min(minV, c.cnt);
                continue;
            }

            if (c.val + 1 < 2000001 && arr[c.val + 1] > c.cnt + 1) {
                arr[c.val + 1] = c.cnt + 1;
                q.add(new Item(c.val + 1, c.cnt + 1));
            }

            if (c.val - 1 > -1 && arr[c.val - 1] > c.cnt + 1) {
                arr[c.val - 1] = c.cnt + 1;
                q.add(new Item(c.val - 1, c.cnt + 1));
            }

            if (c.val > -1 && c.val % 2 == 0 && arr[c.val / 2] > c.cnt + 1) {
                arr[c.val / 2] = c.cnt + 1;
                q.add(new Item(c.val / 2, c.cnt + 1));
            }

            if (c.val > -1 && c.val % 3 == 0 && arr[c.val / 3] > c.cnt + 1) {
                arr[c.val / 3] = c.cnt + 1;
                q.add(new Item(c.val / 3, c.cnt + 1));
            }
        }
    }

    static class Item {
        int val;
        int cnt;
        public Item(int val, int cnt) {
            this.val = val;
            this.cnt = cnt;
        }
    }
}