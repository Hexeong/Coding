import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String a = sc.next();
        String b = sc.next();
        // Please write your code here.

        int flipCnt = 0;
        for (int i = n - 1; i > -1; i--) {
            char cur = (flipCnt % 2 == 0 ? a.charAt(i) : flip(a.charAt(i)));
            if (cur != b.charAt(i)) {
                flipCnt++;
            }
        }

        System.out.println(flipCnt);
    }

    public static char flip(char a) {
        if (a == 'G')
            return 'H';
        return 'G';
    }
}