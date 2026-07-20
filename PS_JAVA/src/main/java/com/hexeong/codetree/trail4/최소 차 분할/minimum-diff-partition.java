import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        // 결국 2개의 그룹의 합을 구하기 위해 조합의 경우의 수를 dp로 계산해야 함.

        // 생각한게 N개의 수의 모든 합에서 A그룹의 합을 빼면 B그룹의 합이 되지 않나?

        // 그럼 상한을 N개의 수의 모든 합의 절반으로 두고 그 안에서 최적화를 돌리는건?
        // B_sum / 2에 최대한 가깝게 구하면 그게 두 그룹의 합 차이를 최소화 한다!
        int n = sc.nextInt();
        int[] val = new int[n];
        int B_sum = 0;
        for (int i = 0; i < n; i++) {
            val[i] = sc.nextInt();
            B_sum += val[i];
        }

        int[] dp = new int[100001];
        for (int v = 0; v < n; v++) {
            for (int k = B_sum / 2; k >= val[v]; k--) {
                dp[k] = Math.max(dp[k], dp[k - val[v]] + val[v]);
            }
        }

        System.out.println(B_sum - (dp[B_sum / 2] * 2));
    }
}