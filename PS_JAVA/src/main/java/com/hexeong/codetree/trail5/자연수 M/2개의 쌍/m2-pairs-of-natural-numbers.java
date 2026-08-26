import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // arr[i][0] = 개수(x), arr[i][1] = 값(y)
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
        }

        // 1. 값(y)을 기준으로 오름차순 정렬
        Arrays.sort(arr, (a, b) -> Integer.compare(a[1], b[1]));

        long res = 0;
        int left = 0;
        int right = n - 1;

        // 2. 투 포인터를 이용하여 양 끝에서부터 짝을 지어줌
        while (left <= right) {
            // 값(y)의 합이 int 범위를 넘을 수 있으므로 long으로 형변환하여 더함
            long currentSum = (long) arr[left][1] + arr[right][1];
            res = Math.max(res, currentSum);

            // 같은 위치에서 만났다면, 남은 개수끼리 짝지어지므로 종료
            if (left == right) {
                break;
            }

            // 양쪽 포인터가 가리키는 값 중 더 적은 개수를 구함
            int minCount = Math.min(arr[left][0], arr[right][0]);
            
            // 양쪽에서 짝을 지은 개수만큼 차감
            arr[left][0] -= minCount;
            arr[right][0] -= minCount;

            // 개수가 0이 된 포인터는 안쪽으로 이동
            if (arr[left][0] == 0) left++;
            if (arr[right][0] == 0) right--;
        }

        System.out.println(res);
    }
}