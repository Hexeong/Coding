import java.util.*;

public class Main {

    static int n;
    static String inStr;
    static String ansStr;
    static int[][] mem; // 현재 i위치에서, 해당 위치에 숫자가 j일 때의 최소한의 회전 수 mem[i][j];

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        inStr = sc.next();
        ansStr = sc.next();

        mem = new int[n][10];
        for (int i = 0; i < n; i++)
            Arrays.fill(mem[i], -1);

        System.out.println(dfs(0, 0));
    }

    static int dfs(int ci, int reverseRotateCnt) {
        if (ci == n) {
            return 0;
        }

        int cv = (inStr.charAt(ci) - '0' + reverseRotateCnt) % 10;
        int ans = ansStr.charAt(ci) - '0';

        if (mem[ci][cv] != -1) return mem[ci][cv];

        int cnt = 0, neededRotateCnt = 0;
        if (ans == cv) {
            cnt = dfs(ci + 1, reverseRotateCnt);
        } else {
            // 시계 반대쪽 회전
            neededRotateCnt = (ans > cv ? ans - cv : ans + 10 - cv);
            // System.out.println(neededRotateCnt);
            int reverseRotateRes = dfs(ci + 1, reverseRotateCnt + neededRotateCnt) + neededRotateCnt;

            // 시계 회전
            neededRotateCnt = (ans < cv ? cv - ans : cv + 10 - ans);
            // System.out.println(neededRotateCnt);
            int rotateRes = dfs(ci + 1, reverseRotateCnt) + neededRotateCnt;

            // 최소한의 회전 수 계산
            cnt = Math.min(reverseRotateRes, rotateRes);
        }

        return mem[ci][cv] = cnt;
    }
}