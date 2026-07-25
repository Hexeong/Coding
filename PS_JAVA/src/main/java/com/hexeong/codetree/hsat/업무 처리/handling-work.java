import java.util.*;
import java.io.*;

public class Main {

    static int h, k, r; // h: 높이, k: 말단 노드 업무 수, r: 날짜 수
    static Queue<Integer>[][] employee;

    public static void main(String[] args) {
        h = nextInt(); 
        k = nextInt(); 
        r = nextInt(); 

        int totalNodes = (1 << (h + 1)) - 1;
        
        // 1. 유저님이 제안하신 2차원 Queue 배열 생성
        employee = new Queue[totalNodes + 1][2];
        for (int i = 1; i <= totalNodes; i++) {
            employee[i][0] = new LinkedList<>();
            employee[i][1] = new LinkedList<>();
        }

        // 2. 말단 노드(리프 노드) 초기 업무 큐 채우기
        // 말단 노드의 인덱스는 (1 << h) 부터 끝까지입니다.
        int startLeaf = 1 << h;
        for (int i = startLeaf; i <= totalNodes; i++) {
            for (int j = 0; j < k; j++) {
                // 말단은 0, 1 구분 없이 한 쪽에만 업무를 몰아넣고 순서대로 뺍니다.
                employee[i][0].add(nextInt()); 
            }
        }

        long ans = 0; // 정답이 int 범위를 초과할 수 있으므로 long 사용

        // 3. R일 동안 시뮬레이션
        for (int day = 1; day <= r; day++) {
            // 1번 노드(루트)부터 말단 노드까지 선형 순회 (동시성 문제 해결)
            for (int i = 1; i <= totalNodes; i++) {
                
                // 현재 노드의 depth 계산 (루트는 0, 말단은 h)
                int d = (int)(Math.log(i) / Math.log(2));
                
                int task = -1; // 이번 턴에 처리할 업무

                // 4. 말단 노드 예외 처리
                if (d == h) { 
                    if (!employee[i][0].isEmpty()) {
                        task = employee[i][0].poll();
                    }
                } else {
                    // 5. 중간 상사 노드 (루트 포함)
                    // day % 2 == 1 (홀수날) -> [1] 왼쪽 부하 직원이 올린 업무 처리
                    // day % 2 == 0 (짝수날) -> [0] 오른쪽 부하 직원이 올린 업무 처리
                    int turn = day % 2; 
                    if (!employee[i][turn].isEmpty()) {
                        task = employee[i][turn].poll();
                    }
                }

                // 6. 처리한 업무를 상사에게 결재 올리기
                if (task != -1) {
                    if (i == 1) { // 1번 부서장이라면 정답에 누적
                        ans += task;
                    } else {      // 일반 상사나 말단이라면 부모 노드(상사)에게 올림
                        int parent = i / 2;
                        if (i % 2 == 0) { // 자신이 왼쪽 자식이면 상사의 [1]번 큐에 적재
                            employee[parent][1].add(task);
                        } else {          // 자신이 오른쪽 자식이면 상사의 [0]번 큐에 적재
                            employee[parent][0].add(task);
                        }
                    }
                }
            }
        }

        System.out.println(ans);
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }
}