import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            pq.add(arr[i]);
        }
        // Please write your code here.

        long cost = 0;
        while (pq.size() != 1) {
            int v = pq.poll() + pq.poll();
            cost += (long) v;
            pq.add(v);
        }

        System.out.println(cost);
    }
}