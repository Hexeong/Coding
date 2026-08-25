import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] bombs = new int[n][2];
        for (int i = 0; i < n; i++) {
            bombs[i][0] = sc.nextInt(); // score
            bombs[i][1] = sc.nextInt(); // timeLimit
        }
        
        // 1. 시간 제한(timeLimit)을 기준으로 오름차순 정렬
        Arrays.sort(bombs, (a, b) -> a[1] - b[1]);

        // 2. 가장 점수가 낮은 것을 뺄 수 있도록 Min-Heap 사용
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            // 일단 해체한다고 가정하고 큐에 점수를 넣음
            pq.add(bombs[i][0]);

            // 3. 큐의 크기(지금까지 해체한 폭탄 수 = 소요 시간)가
            // 현재 폭탄의 시간 제한을 초과한다면,
            // 지금까지 고른 것 중 가장 점수가 낮은 폭탄을 포기(제거)
            if (pq.size() > bombs[i][1]) {
                pq.poll();
            }
        }

        // 4. 큐에 최종적으로 살아남은(선택된) 폭탄들의 점수 합산
        int score = 0;
        while (!pq.isEmpty()) {
            score += pq.poll();
        }
        
        System.out.println(score);
    }
}