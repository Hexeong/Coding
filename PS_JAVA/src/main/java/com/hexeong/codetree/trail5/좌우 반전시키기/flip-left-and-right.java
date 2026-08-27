import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        // Please write your code here.

        int res = 0;
        for (int i = 1; i < N; i++) {
            if (arr[i - 1] == 0) {
                arr[i - 1] = 1;
                arr[i] = (arr[i] == 1 ? 0 : 1);
                if (i + 1 < N) arr[i + 1] = (arr[i + 1] == 1 ? 0 : 1);
                res++;
            }
        }

        if (arr[N - 1] == 0)
            System.out.println(-1);
        else
            System.out.println(res);
    }
}