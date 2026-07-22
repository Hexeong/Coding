import java.util.*;

public class Main {

    static int n, k;
    static String nStr;
    static int[][][] mem; // i번째 수정이 떨어지고 있고, j번 이동했고, 현재 위치가 k일 떄의 최대 수정 개수

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); k = sc.nextInt();

        nStr = sc.next();
        
        // 초기 왼쪽 샘터에 서 있다.
        
        mem = new int[n][k + 1][2];

        for (int i = 0; i < n; i++) 
            for (int j = 0; j <= k; j++)
                Arrays.fill(mem[i][j], -1);


        System.out.println(dfs(0, 0, 0));
    }

    static int dfs(int idx, int mvCnt, int cPos) {
        if (idx == n) {
            return 0;
        }

        if (mem[idx][mvCnt][cPos] != -1) return mem[idx][mvCnt][cPos];

        // 1. 가만히 있기
        int cnt = dfs(idx + 1, mvCnt, cPos) 
            + (cPos == 0 && nStr.charAt(idx) == 'L' ? 1 : 0)
            + (cPos == 1 && nStr.charAt(idx) == 'R' ? 1 : 0);
        // 2. 반대편으로 이동
        if (mvCnt < k) {
            int mvRes = dfs(idx + 1, mvCnt + 1, cPos == 0 ? 1 : 0) 
                    + (cPos == 0 && nStr.charAt(idx) == 'R' ? 1 : 0)
                    + (cPos == 1 && nStr.charAt(idx) == 'L' ? 1 : 0);
            cnt = Math.max(cnt, mvRes);
        }

        return mem[idx][mvCnt][cPos] = cnt;
    }
}