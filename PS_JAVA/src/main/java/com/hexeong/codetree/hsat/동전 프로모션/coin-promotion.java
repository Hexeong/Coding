import java.util.*;
public class Main {

    static int n, m;
    static List<Integer> aCoin = new ArrayList<>();
    static List<Integer> bCoin = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        m = sc.nextInt();

        for (int i = 0; i < n; i++) {
            char aOrB = sc.next().charAt(0);

            if (aOrB == 'A') aCoin.add(sc.nextInt());
            else bCoin.add(sc.nextInt());
        }

        int[] dp = new int[m + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        // 중복 사용해도 되는 코인인 A
        for (int i = 0; i < aCoin.size(); i++) {
            for (int v = aCoin.get(i); v <= m; v++) {
                if (dp[v - aCoin.get(i)] != Integer.MAX_VALUE) {
                    dp[v] = Math.min(dp[v], dp[v - aCoin.get(i)] + 1);
                }
            }
        }

        // 한 번만 사용해야 하는 코인 B
        for (int i = 0; i < bCoin.size(); i++) {
            for (int v = m; v >= bCoin.get(i); v--) {
                if (dp[v - bCoin.get(i)] != Integer.MAX_VALUE) {
                    dp[v] = Math.min(dp[v], dp[v - bCoin.get(i)] + 1);
                }
            }
        }

        if (dp[m] == Integer.MAX_VALUE)
            System.out.println(-1);
        else
            System.out.println(dp[m]);
    }
}