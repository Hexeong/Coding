import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[][] in = new int[4][n];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < n; j++)
                in[i][j] = sc.nextInt();

        Map<Integer, Integer> ab = new HashMap<>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ab.put(in[0][i] + in[1][j], ab.getOrDefault(in[0][i] + in[1][j], 0) + 1);

        Map<Integer, Integer> cd = new HashMap<>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cd.put(in[2][i] + in[3][j], cd.getOrDefault(in[2][i] + in[3][j], 0) + 1);

        long cnt = 0;
        for (Map.Entry<Integer, Integer> e : ab.entrySet()) {
            if (!cd.containsKey(- e.getKey())) continue;

            cnt += (long) (e.getValue() * cd.get(- e.getKey()));
        }

        System.out.println(cnt);
    }
}