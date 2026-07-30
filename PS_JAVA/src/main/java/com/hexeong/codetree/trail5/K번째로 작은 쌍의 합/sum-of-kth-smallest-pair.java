import java.util.*;

public class Main {
    // 합과 두 인덱스를 함께 저장할 클래스
    static class Element implements Comparable<Element> {
        long sum; // 주어지는 숫자가 10^9이므로 합은 long을 쓰는 것이 안전합니다.
        int i, j;

        public Element(long sum, int i, int j) {
            this.sum = sum;
            this.i = i;
            this.j = j;
        }

        // 우선순위 큐가 작은 합부터 뽑아내도록 오름차순 정렬 기준 설정
        @Override
        public int compareTo(Element o) {
            return Long.compare(this.sum, o.sum);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();

        long[] arr1 = new long[n];
        for (int i = 0; i < n; i++) arr1[i] = sc.nextLong();

        long[] arr2 = new long[m];
        for (int i = 0; i < m; i++) arr2[i] = sc.nextLong();

        // 1. 두 배열 오름차순 정렬
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        PriorityQueue<Element> pq = new PriorityQueue<>();

        // 2. 초기 셋팅: arr1의 원소들과 arr2의 0번째 원소를 매칭하여 넣기
        // 최적화: K번째를 구하는 것이므로, 최대 K개까지만 넣으면 됨
        for (int i = 0; i < Math.min(n, k); i++) {
            pq.add(new Element(arr1[i] + arr2[0], i, 0));
        }

        // 3. K - 1번을 뽑으면서 다음 후보를 큐에 넣기
        for (int step = 0; step < k - 1; step++) {
            Element curr = pq.poll();

            // arr2의 다음 인덱스(j+1)가 범위를 벗어나지 않는다면 추가
            if (curr.j + 1 < m) {
                pq.add(new Element(arr1[curr.i] + arr2[curr.j + 1], curr.i, curr.j + 1));
            }
        }

        // 4. K - 1번 버렸으므로, 이제 큐의 맨 위에 있는 값이 K번째로 작은 값!
        System.out.println(pq.peek().sum);
    }
}