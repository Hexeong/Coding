import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String a = sc.next();
        String b = sc.next();
        boolean[] rev = new boolean[n];
        // Please write your code here.

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (a.charAt(i) == b.charAt(i)) {
                if (i > 0 && rev[i - 1])
                    res++;
            } else {
                rev[i] = true;
            }
        }

        if (rev[n - 1])
            res++;
        
        System.out.println(res);
    }
}