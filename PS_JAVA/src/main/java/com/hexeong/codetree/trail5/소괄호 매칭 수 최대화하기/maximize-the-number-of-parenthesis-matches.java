import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.next();
        }
        // Please write your code here.

        // 매칭수가 최대화되려면 하나의 문자열 T의 앞쪽에 최대한 많은 (을 넣어야 함
        Arrays.sort(arr, (a, b) -> {
            long aOpen = 0, aClose = 0;
            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) == '(') aOpen++;
                else aClose++;
            }

            long bOpen = 0, bClose = 0;
            for (int i = 0; i < b.length(); i++) {
                if (b.charAt(i) == '(') bOpen++;
                else bClose++;
            }

            // A가 앞에 올 때의 이득과 B가 앞에 올 때의 이득 계산
            long gainAB = aOpen * bClose;
            long gainBA = bOpen * aClose;

            // 더 큰 이득을 주는 순서대로 내림차순 정렬
            return Long.compare(gainBA, gainAB);
        });

        
        long res = 0;
        long openBracket = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < arr[i].length(); j++) {
                if (arr[i].charAt(j) == '(')
                    openBracket++;
                else 
                    res += openBracket;
            }
        }

        System.out.println(res);
    }
}