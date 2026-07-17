import java.util.*;
import java.io.*;

public class Main {
    static int n, m;
    static int[] res;
    static List<int[]> givenLines = new ArrayList<>();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        boolean[][] ladder = new boolean[16][n];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1; // 0-based index
            int b = Integer.parseInt(st.nextToken());     // height
            
            ladder[b][a] = true;
            givenLines.add(new int[]{b, a}); // 주어진 가로줄 정보만 따로 저장
        }

        // 전체 가로줄을 놓았을 때의 정답 결과
        res = proceed(ladder, n);

        // 0개부터 m개까지 고르는 경우의 수 탐색
        for (int l = 0; l <= m; l++) {
            boolean[][] tmp = new boolean[16][n];
            if (backt(tmp, l, 0, 0)) {
                System.out.println(l);
                return;
            }
        }
    }

    private static boolean backt(boolean[][] tmp, int target_l, int depth, int start) {
        if (depth == target_l) {
            int[] tmp_result = proceed(tmp, n);
            for (int i = 0; i < n; i++) {
                if (res[i] != tmp_result[i]) return false;
            }
            return true; // 정답을 찾은 경우 true 반환
        }

        // 🌟 주어진 M개의 가로줄 중에서만 선택 (조합)
        for (int i = start; i < givenLines.size(); i++) {
            int[] line = givenLines.get(i);
            int h = line[0];
            int c = line[1];

            tmp[h][c] = true;
            if (backt(tmp, target_l, depth + 1, i + 1)) return true; // 하나라도 찾으면 즉시 종료
            tmp[h][c] = false;
        }
        
        return false;
    }

    private static int[] proceed(boolean[][] ladder, int n) {
        int[] result = new int[n];

        for (int j = 0; j < n; j++) {
            int cur_j = j;
            for (int i = 1; i <= 15; i++) {
                if (cur_j < n - 1 && ladder[i][cur_j]) {
                    cur_j++;
                }
                else if (cur_j > 0 && ladder[i][cur_j - 1]) {
                    cur_j--;
                }
            }
            result[j] = cur_j;
        }

        return result;
    }
}