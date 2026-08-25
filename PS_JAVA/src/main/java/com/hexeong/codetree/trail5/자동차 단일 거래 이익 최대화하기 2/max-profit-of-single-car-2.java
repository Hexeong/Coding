import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] prices = new int[n];
        for(int i = 0; i < n; i++)
            prices[i] = sc.nextInt();
        // Please write your code here.

        int st = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (st > prices[i]) {
                st = prices[i];
            } else {
                res = Math.max(res, prices[i] - st);
            }
        }

        System.out.println(res);
    }
}