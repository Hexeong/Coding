import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] in = new int[n];
        for (int i = 0; i < n; i++)
            in[i] = sc.nextInt();

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        double maxAvg = 0;
        long sum = 0; 

        // 1. 초기 상태: 가장 마지막 원소를 미리 큐와 합계에 넣어둡니다.
        pq.add(in[n - 1]);
        sum += in[n - 1];

        // 2. 뒤에서부터 앞으로 이동하며 K를 탐색합니다.
        for (int k = n - 2; k >= 1; k--) {
            // K번째 위치의 원소가 추가로 남게 됩니다.
            pq.add(in[k]);
            sum += in[k];
            
            // 가장 작은 값(pq.peek())을 제외한 평균을 계산합니다.
            double avg = (double)(sum - pq.peek()) / (n - k - 1);
            maxAvg = Math.max(maxAvg, avg);
        }

        System.out.printf("%.2f\n", maxAvg);
    }
}