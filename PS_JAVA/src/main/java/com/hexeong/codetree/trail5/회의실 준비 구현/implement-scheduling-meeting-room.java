import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        int[][] req = new int[n][2];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            req[i][0] = Integer.parseInt(st.nextToken());
            req[i][1] = Integer.parseInt(st.nextToken());
        }
        
        Arrays.sort(req, (a, b) -> {
            return a[1] - b[1];
        });

        int lastT = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (lastT <= req[i][0]) {
                lastT = req[i][1];
                cnt++;
            }
        }

        System.out.println(cnt);
    }
}