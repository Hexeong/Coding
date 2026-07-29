import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        Map<String, Integer> ctoi = new HashMap<>();
        Map<Integer, String> itoc = new HashMap<>();

        int num = 1;
        for (int i = 0; i < n; i++) {
            String target = sc.next();
            ctoi.put(target, num);
            itoc.put(num++, target);
        }

        for (int i = 0; i < m; i++) {
            String in = sc.next();

            if (in.charAt(0) <= '9' && in.charAt(0) >= '0') {
                System.out.println(itoc.get(Integer.parseInt(in)));
            } else {
                System.out.println(ctoi.get(in));
            }
        }
    }
}