import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = sc.nextInt();
        }
        // Please write your code here.

        Map<Integer, Integer> m = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            if (m.containsKey(numbers[i])) continue;
            m.put(numbers[i], i + 1);
        }

        Iterator<Map.Entry<Integer, Integer>> it = m.entrySet().iterator();

        while (it.hasNext()) {
            Map.Entry<Integer, Integer> e = it.next();
            System.out.println(e.getKey() + " " + e.getValue());
        }
    }
}