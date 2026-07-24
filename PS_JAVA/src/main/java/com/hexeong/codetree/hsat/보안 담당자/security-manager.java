import java.util.*;
import java.io.*;

public class Main {

    static int n;
    static String nStr;

    public static void main(String[] args) throws IOException {
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        nStr = br.readLine();

        // if (n % 2 == 1) {
        //     System.out.println("No");
        //     return;
        // }

        // 2^5000? 이거 안된다. 
        // 가지치기 해서 2^2500 개가 되더라도 1억번 이내로 계산할 수 없음. 백트래킹 절대 안됨.
        // 근데 문제가 ?를 ( 또는 )로 적절히 해석했을 때 CCTV 기록이 정상일 수 있는지를 판별하는 것임
        
        // 그럼 DP? N * N 정도는 가능함. 2천5백만 정도임
        // 근데 걸리는게 마지막까지 확인했을 때 들어온 수와 나간 수가 같아야 함.

        // DP로 바라볼 때, i ~ N까지 한번 순회
        // 순회 과정에서 현재 (과 )로 확정된 개수의 차이를 가지고 가기
        // 이때 )가 (를 넘는 순간이 오면 이전에 있던 ?를 그 차이만큼 (로 변환하기
        // 그렇게 순회가 끝나고 남은 (와 )와 ? 개수를 비교 (와 )의 개수 차이를 메꾸고 남은 ?의 개수가
        // 짝수이면 Yes

        int diffCnt = 0;
        int qCnt = 0;
        for (int i = 0; i < n; i++) {
            if (nStr.charAt(i) == '(') {
                diffCnt++;
            } else if (nStr.charAt(i) == ')') {
                diffCnt--;
                if (diffCnt < 0) {
                    if (qCnt > 0) { // 이때 )가 (를 넘는 순간이 오면 이전에 있던 ?를 그 차이만큼 (로 변환하기
                        diffCnt++;
                        qCnt--;
                    } else {
                        System.out.println("No");
                        return;
                    }
                }
            } else {
                qCnt++;
            }
        }

        if (diffCnt > qCnt) {
            System.out.println("No");
            return;
        }
        if ((qCnt - diffCnt) % 2 == 1) {
            System.out.println("No");
            return;
        }

        diffCnt = 0;
        qCnt = 0;
        for (int i = n - 1; i > -1; i--) {
            if (nStr.charAt(i) == ')') {
                diffCnt++;
            } else if (nStr.charAt(i) == '(') {
                diffCnt--;
                if (diffCnt < 0) {
                    if (qCnt > 0) { // 이때 )가 (를 넘는 순간이 오면 이전에 있던 ?를 그 차이만큼 (로 변환하기
                        diffCnt++;
                        qCnt--;
                    } else {
                        System.out.println("No");
                        return;
                    }
                }
            } else {
                qCnt++;
            }
        }

        if (diffCnt > qCnt) {
            System.out.println("No");
            return;
        } 
        if ((qCnt - diffCnt) % 2 == 1) {
            System.out.println("No");
            return;
        }

        System.out.println("Yes");
    }
}