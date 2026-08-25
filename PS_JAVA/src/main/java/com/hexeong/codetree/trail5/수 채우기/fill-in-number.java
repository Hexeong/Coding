import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        // Please write your code here.

        int min = Integer.MAX_VALUE;
        int base_cnt = 0;
        while (n >= 0) {
            if (n % 2 == 0) {
                min = Math.min(min, base_cnt + n / 2);
            }
            n -= 5;
            base_cnt++;
        }

        System.out.println(min == Integer.MAX_VALUE ? -1 : min);
    }
}