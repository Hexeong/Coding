import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] grid = new String[n];
        for (int i = 0; i < n; i++) {
            grid[i] = sc.next();
        }
        // Please write your code here.

        int[] flipColumnCnt = new int[n];

        int res = 0;
        for (int i = n - 1; i > -1; i--) {
            int flipRowCnt = 0;
            for (int j = n - 1; j > -1; j--) {
                char cur = (flipColumnCnt[j] + flipRowCnt) % 2 == 0 
                    ? grid[i].charAt(j)
                    : flip(grid[i].charAt(j));
                if (cur != '0') {
                    flipRowCnt++;
                }
                flipColumnCnt[j] += flipRowCnt;
            }
            res += flipRowCnt;
        }

        System.out.println(res);
    }

    public static char flip(char a) {
        if (a == '1')
            return '0';
        return '1';
    }
}