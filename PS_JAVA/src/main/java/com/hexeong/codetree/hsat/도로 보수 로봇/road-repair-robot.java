import java.util.*;

public class Main {

    static int n, k;
    static long[] holes;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();

        holes = new long[n];
        for (int i = 0; i < n; i++)
            holes[i] = sc.nextLong();

        // 사용한 패치가 K개 이하인 상황에서, 모든 구멍을 메꾸기 위해 필요한
        // 패치의 최소 길이

        // 이분 탐색으로 최소 길이를 찾기
        // NlogN = 100000 * log100000 < 100000 * 20

        // 메꾸는 과정에서 K개 초과가 된다면 길이를 추가
        // K개 이하라면 길이를 축소

        long left = 1;
        long right = 1000000000;
        long min = Long.MAX_VALUE;
        while (left <= right) {
            long cLen = (left + right) / 2;

            if (isPossible(cLen)) {
                right = cLen - 1;
                min = Math.min(min, cLen);
            } else {
                left = cLen + 1;
            }
        }

        System.out.println(min);
    }

    static boolean isPossible(long len) {
        int ck = 0;
        for (int i = 0; i < holes.length; i++) {
            if (ck > k) {
                return false;
            }

            // 현재 시점부터 len 길이의 패치를 쓸 때
            int stIdx = i;
            ck++;
            // 해당 패치로 다음 것들을 메꿀 수 있다면 i++로 넘어가기
            while (i + 1 < holes.length && holes[i + 1] < holes[stIdx] + len) {
                i++;
            }
        }

        if (ck > k) {
            return false;
        }

        return true;
    }
}