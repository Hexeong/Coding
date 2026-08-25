import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] bCards = new int[n];
        for (int i = 0; i < n; i++) {
            bCards[i] = sc.nextInt();
        }
        // Please write your code here.

        Arrays.sort(bCards);
        int bIdx = 0;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= 2 * n; i++) {
            if (bIdx < n && bCards[bIdx] == i) {
                bIdx++;
                continue;
            }

            q.add(i);
        }

        int score = 0;
        for (int i = 0; i < n; i++) {
            while (!q.isEmpty() && q.peek() < bCards[i])
                q.poll();
            
            if (q.isEmpty()) break;

            score++;
            q.poll();
        }

        System.out.println(score);
    }
}