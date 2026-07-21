import java.util.*;

public class Main {

    static int n, m;
    static int[] num;
    static int[][] sum;
    static int[][] mem;

    static int minV = -1000000000;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        num = new int[n];
        for (int i = 0; i < n; i++)
            num[i] = sc.nextInt();

        sum = new int[n][n];
        for (int i = 0; i < n; i++) {
            sum[i][i] = num[i];
            for (int j = i + 1; j < n; j++) {
                sum[i][j] = sum[i][j - 1] + num[j];
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         System.out.print(sum[i][j] + " ");
        //     System.out.println();
        // }

        mem = new int[n][m];
        for (int i = 0; i < n; i++)
            Arrays.fill(mem[i], minV);

        int v = minV;
        for (int i = 0; i < n; i++) {
            v = Math.max(v, dfs(i, 0));
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         System.out.print(mem[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        System.out.println(v);
    }

    static int dfs(int cidx, int cnt) {

        int remainSections = m - cnt;
        int remainElements = n - cidx;

        if (remainSections > 0 && remainElements < 2 * remainSections - 1)
            return minV;

        // cidx는 현재부터 구간 시작 idx, cnt는 구간 개수
        // 그럼 mem[][]은 해당 i까지 진행했고, 구간이 j개 일 때 mem[i][j]는 최대 합
        if (cnt == m) {
            return 0;
        }

        if (cidx >= n) { // 구간이 m개가 되기도 전에 cidx가 n을 넘기면 -1 반환
            return minV;
        }

        if (mem[cidx][cnt] != minV) 
            return mem[cidx][cnt];

        int max = minV;
        // 1. 현재 원소를 구간에 포함시키지 않고 그냥 건너뛰는 경우 (여백을 2칸 이상 줄 수 있게 됨!)
        int skipRes = dfs(cidx + 1, cnt);
        if (skipRes != minV) {
            max = Math.max(max, skipRes);
        }

        // 2. 현재 원소(cidx)를 새로운 구간의 '시작점'으로 선택하는 경우 (기존 작성하신 코드 그대로!)
        for (int ed = cidx; ed < n; ed++) {
            int res = dfs(ed + 2, cnt + 1); 
            if (res != minV) {
                max = Math.max(max, res + sum[cidx][ed]);
            }
        }

        return mem[cidx][cnt] = max;
    }
}