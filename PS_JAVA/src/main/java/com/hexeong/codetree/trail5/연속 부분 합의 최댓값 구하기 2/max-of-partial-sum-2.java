import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        // Please write your code here.

        int sum = 0;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < a.length; i++) {
            sum += a[i];
            max = Math.max(max, sum);
            if (sum < 0) {
                sum = 0;
            }
        }

        System.out.println(max);
    }
}