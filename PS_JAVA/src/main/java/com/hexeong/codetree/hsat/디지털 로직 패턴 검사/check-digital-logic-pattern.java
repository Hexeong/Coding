import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc = new Scanner(System.in);
        String str = sc.next();

        int k = sc.nextInt();
        int m = sc.nextInt();

        long window = 0L;

        for (int i = 0; i < k; i++) {
            window = (window << 1) | (str.charAt(i) - '0');
        }
        
        Map<Long, Integer> bucket = new HashMap<>();
        bucket.put(window, 1);

        long mask = (1L << k) - 1;

        for (int i = k; i < str.length(); i++) {
            // window의 앞을 없애기
            // window에 << 1 + str.charAt(i) - '0' 로 다음 bit 추가하기
            window = ((window << 1) & mask) | (str.charAt(i) - '0');

            // 맵에 존재하면 기존 + 1, 맵에 존재하지 않으면 1
            int count = bucket.getOrDefault(window, 0) + 1;
            bucket.put(window, count);

            // 해당 결과가 M 이상이면 print(1)하고 return;
            if (count >= m) {
                System.out.println(1);
                return; // main 함수 종료
            }
        }

        System.out.println(0);
    }
}