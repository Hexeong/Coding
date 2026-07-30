import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] points = new int[n];
        for (int i = 0; i < n; i++) {
            points[i] = sc.nextInt();
        }
        Arrays.sort(points);

        int[] line = new int[1000001];
        int pIdx = 0;
        int cnt = 0;
        for (int i = 0; i < 1000001; i++) {
            if (pIdx < n && points[pIdx] == i) {
                cnt++;
                pIdx++;
            }
            line[i] = cnt;
        }

        for (int i = 0; i < q; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            // Please write your code here.
            System.out.println(line[b] - (a == 0 ? 0 : line[a - 1]));
        }
    }
}