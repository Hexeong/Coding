import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] points = new int[n];
        for (int i = 0; i < n; i++) {
            points[i] = sc.nextInt();
        }
        

        // Q개의 질의에 대해 최대 N개의 점을 순회하는 방식이면 Q * N = 10만^2이다.
        // 따라서 a와 가장 가까운 점의 위치를 log(n) 안에 찾아야 한다.
        // 이분 탐색을 진행하면?

        Arrays.sort(points);

        for (int i = 0; i < q; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            // N개의 점을 순회하면서 
            int aIdx = getLowerIdx(a, points);
            int bIdx = getLowerIdx(b, points);

            System.out.println(bIdx - aIdx + 1);
        }
    }

    static int getLowerIdx(int target, int[] points) {
        int l = 0;
        int r = points.length - 1;
        int min = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (target <= points[mid]) {
                min = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return min;
    }
}