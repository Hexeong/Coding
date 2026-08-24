import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        double[][] jewel = new double[n][2];
        for (int i = 0; i < n; i++) {
            int w = sc.nextInt();
            int v = sc.nextInt();
            jewel[i][0] = (double)w;
            jewel[i][1] = (double)v;
        }
        // Please write your code here.

        Arrays.sort(jewel, (a, b) -> {
            return Double.compare((b[1] / b[0]), (a[1] / a[0]));
        });

        int cur_w = 0;
        double cur_v = 0;
        for (int i = 0; i < n; i++) {
            if (cur_w + jewel[i][0] <= m) {
                cur_v += jewel[i][1];
                cur_w += jewel[i][0];
            } else {
                cur_v += ((double) jewel[i][1] / jewel[i][0] * (m - cur_w));
                break;
            }
        }

        System.out.printf("%.3f", cur_v);
    }
}