import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = sc.nextInt();
        // Please write your code here.

        int res = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i - 1][j] == 0) {
                    arr[i - 1][j] = 1;
                    if (j - 1 > -1) arr[i][j - 1] = (arr[i][j - 1] == 1 ? 0 : 1);
                    if (j + 1 < n) arr[i][j + 1] = (arr[i][j + 1] == 1 ? 0 : 1);
                    arr[i][j] = (arr[i][j] == 1 ? 0 : 1);
                    if (i + 1 < n) arr[i + 1][j] = (arr[i + 1][j] == 1 ? 0 : 1);
                    res++;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (arr[n - 1][j] == 0) {
                System.out.println(-1);
                return;
            }
        }

        System.out.println(res);
    }
}