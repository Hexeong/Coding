import java.util.*;

public class Main {

    static int n, k, b;
    static int[] missing;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        b = sc.nextInt();
        missing = new int[b];
        for (int i = 0; i < b; i++) {
            missing[i] = sc.nextInt();
        }
        // Please write your code here.

        Arrays.sort(missing);
        
        // arr[i][j]를 i가 추가한 숫자 개수, j가 현재 추가한 숫자일 떄로 정의할 때
        // 이러면 10만 * 10만이라 메모리 초과임.

        // prefix sum..?
        // 이분탐색을 활용해보는 건 어떨까? 1부터 B 사이를 이분 탐색을 진행
        // 그리고 mid 개를 추가해서 최대로 연속한 숫자 개수가 k를 넘는지 검사
        // 넘는다면 mid를 낮추기
        // 넘지 않는다면 mid를 높이기
        // 이럼 최대 10만 * log10만

        int l = 0;
        int r = b;
        int m = Integer.MAX_VALUE;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (check(mid)) {
                m = Math.min(m, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        System.out.println(m);
    }

    static boolean check(int m) {
        for (int i = 0; i <= b - m; i++) {
            int left = (i > 0 ? missing[i - 1] + 1 : 1);
            int right = (i + m < b ? missing[i + m] - 1 : n);

            if (right - left + 1 >= k)
                return true;
        }
        return false;
    }
}