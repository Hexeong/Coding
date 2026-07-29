import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int in = sc.nextInt();
            map.put(in, map.getOrDefault(in, 0) + 1);
        }

        int cnt = 0;
        Set<Integer> done = new HashSet<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (done.contains(entry.getKey())) {
                continue;
            }
            // System.out.println(entry.getKey() + " " + (k - entry.getKey()));
            int opponentCnt = map.getOrDefault(k - entry.getKey(), 0);

            if (k - entry.getKey() == entry.getKey()) {
                cnt += (opponentCnt * (opponentCnt - 1)) / 2;
            } else {
                cnt += entry.getValue() * opponentCnt;
            }

            done.add(entry.getKey());
            done.add(k - entry.getKey());
        }

        System.out.println(cnt);
    }
}