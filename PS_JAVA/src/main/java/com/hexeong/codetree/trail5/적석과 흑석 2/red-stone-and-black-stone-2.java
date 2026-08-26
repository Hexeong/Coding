import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = sc.nextInt();
        int n = sc.nextInt();

        int[] redStones = new int[c];
        for (int i = 0; i < c; i++) {
            redStones[i] = sc.nextInt();
        }

        int[][] blackStones = new int[n][2];
        for (int i = 0; i < n; i++) {
            blackStones[i][0] = sc.nextInt(); // A
            blackStones[i][1] = sc.nextInt(); // B
        }

        // 1. 빨간 돌 오름차순 정렬
        Arrays.sort(redStones);

        // 2. 검정 돌을 시작점(A) 기준으로 오름차순 정렬
        Arrays.sort(blackStones, (a, b) -> Integer.compare(a[0], b[0]));

        // 3. 끝점(B)이 빠른 순서대로 정렬되는 우선순위 큐
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int ans = 0;
        int blackIdx = 0;

        // 작은 빨간 돌부터 하나씩 짝을 지어봄
        for (int i = 0; i < c; i++) {
            int currentRed = redStones[i];

            // 매칭 가능성이 있는 (시작점 A가 현재 빨간 돌보다 작거나 같은) 
            // 검정 돌의 끝점(B)을 큐에 모두 넣음
            while (blackIdx < n && blackStones[blackIdx][0] <= currentRed) {
                pq.add(blackStones[blackIdx][1]);
                blackIdx++;
            }

            // 큐에 있는 검정 돌 중, 끝점 B가 현재 빨간 돌보다 작아서 
            // 더 이상 매칭할 수 없는 돌들은 큐에서 제거
            while (!pq.isEmpty() && pq.peek() < currentRed) {
                pq.poll();
            }

            // 짝지을 수 있는 검정 돌이 남아있다면, 
            // 가장 끝점이 임박한(작은) 검정 돌 하나와 매칭
            if (!pq.isEmpty()) {
                pq.poll();
                ans++;
            }
        }

        System.out.println(ans);
    }
}