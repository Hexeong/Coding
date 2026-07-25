import java.util.*;
import java.io.*;

public class Main {

    static int n, m;
    static String[] given;
    static boolean[] valid;
    static int[] dp;

    public static void main(String[] args) {
        n = nextInt(); // <= 15
        m = nextInt(); // <= 20
        given = new String[n];
        for (int i = 0; i < n; i++) {
            given[i] = next();
        }

        int maxMask = 1 << n; // 2^N
        valid = new boolean[maxMask];
        
        // 1. 각 부분집합(mask)이 하나의 초염기서열로 병합 가능한지 미리 판별 (전처리)
        for (int mask = 1; mask < maxMask; mask++) {
            valid[mask] = check(mask);
        }

        // 2. DP 배열 초기화
        dp = new int[maxMask];
        Arrays.fill(dp, 987654321); // 최솟값 비교를 위해 무한대(적당히 큰 수)로 초기화
        dp[0] = 0;

        // 3. 비트마스크 DP 수행 (집합 분할 트릭)
        for (int mask = 1; mask < maxMask; mask++) {
            // 이 그룹이 충돌 없이 한 번에 다 합쳐진다면 초염기서열 1개면 충분함
            if (valid[mask]) {
                dp[mask] = 1;
                continue;
            }
            
            // 한 번에 안 합쳐진다면, 이 그룹(mask)을 두 개의 부분집합으로 쪼개서 최솟값 찾기
            // 비트 연산 트릭: sub = (sub - 1) & mask (mask의 모든 진부분집합을 순회하는 마법의 코드)
            for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
                dp[mask] = Math.min(dp[mask], dp[sub] + dp[mask ^ sub]);
            }
        }

        // 정답: 모든 유전자(111...11)를 커버하기 위한 최소 개수
        System.out.println(dp[maxMask - 1]);
    }

    // 해당 부분집합(mask)의 유전자들이 충돌 없이 하나의 염기서열로 합쳐질 수 있는지 검사
    static boolean check(int mask) {
        for (int i = 0; i < m; i++) { // 각 자리(열)마다 확인
            char req = '.';
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) != 0) { // j번째 유전자가 이 그룹(mask)에 포함되어 있다면
                    char c = given[j].charAt(i);
                    if (c != '.') {
                        if (req == '.') {
                            req = c; // 첫 알파벳 등장 시 기준 세팅
                        } else if (req != c) {
                            return false; // 기존 알파벳과 다른 것이 나오면 충돌! (합칠 수 없음)
                        }
                    }
                }
            }
        }
        return true; // 끝까지 충돌이 없었다면 합병 가능
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