import java.util.*;
import java.io.*;

public class Main {
    static int n, Q;
    static int[] car;

    public static void main(String[] args) {
        // Please write your code here.
        n = nextInt();
        Q = nextInt();
        car = new int[n];
        Map<Integer, Integer> carIdx = new HashMap<>();
        for (int i = 0; i < n; i++) {
            car[i] = nextInt();
        }

        Arrays.sort(car);

        for (int i = 0; i < n; i++) {
            carIdx.put(car[i], i);
        }

        for (int q = 0; q < Q; q++) {
            int targetCarNum = nextInt();
            int targetCarIdx = carIdx.getOrDefault(targetCarNum, -1);

            if (targetCarIdx == -1) {
                System.out.println(0);
                continue;
            }

            System.out.println(targetCarIdx * (n - 1 - targetCarIdx));
        }
    }


    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() {
        while(st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }
}