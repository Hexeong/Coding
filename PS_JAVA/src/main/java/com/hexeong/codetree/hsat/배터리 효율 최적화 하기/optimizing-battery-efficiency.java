import java.util.*;

public class Main {

    static int n, m;
    static int[][] grid;
    static List<Integer> combs;

    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        grid = new int[n][m];
        combs = new ArrayList<>();

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                grid[i][j] = sc.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cComb = (1 << (i * m + j));
                getCombination(cComb); // 단일 칸을 시작점으로 주고 BFS 큐 시작
            }
        }

        int max = Integer.MIN_VALUE;
        for (int i = 0; i < combs.size(); i++) {
            for (int j = i + 1; j < combs.size(); j++) {
                if (Integer.bitCount(combs.get(i).intValue() & combs.get(j).intValue()) == 2) {
                    int[][] iPos = getPos(combs.get(i));
                    int[][] jPos = getPos(combs.get(j));

                    max = Math.max(max, calculate(iPos) + calculate(jPos));
                }
            }
        }

        System.out.println(max);
    }

    static int[] dy = {1, 0, -1, 0};
    static int[] dx = {0, -1, 0, 1};

    static void getCombination(int startComb) {
        Queue<Integer> q = new LinkedList<>();
        // BFS 탐색 중 똑같은 조합이 큐에 여러 번 들어가는 것을 막기 위한 Set
        HashSet<Integer> visitedBFS = new HashSet<>(); 

        q.add(startComb);
        visitedBFS.add(startComb);

        while (!q.isEmpty()) {
            int cComb = q.poll();

            // 현재 조합에 포함된 배터리 셀이 5칸(비트 1의 개수가 5개)이 되면 완료
            if (Integer.bitCount(cComb) == 5) {
                if (!combs.contains(cComb)) {
                    combs.add(cComb);
                }
                continue; // 5칸이 넘어가면 안 되므로 이 덩어리는 더 이상 확장하지 않음
            }

            // 현재 덩어리(cComb)에 속해있는 모든 칸을 기준으로 인접한 칸 찾기
            for (int num = 0; num < n * m; num++) {
                // num번째 칸이 현재 조합에 포함되어 있다면
                if ((cComb & (1 << num)) > 0) {
                    int cy = num / m;
                    int cx = num % m;

                    // 해당 칸의 상하좌우 탐색
                    for (int i = 0; i < 4; i++) {
                        int ny = cy + dy[i];
                        int nx = cx + dx[i];

                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

                        int nextBit = 1 << (ny * m + nx);
                        
                        // 인접한 칸이 아직 우리 조합에 포함되지 않았다면
                        if ((cComb & nextBit) == 0) {
                            int nComb = cComb | nextBit;
                            
                            // 큐에 넣은 적 없는 새로운 형태일 때만 큐에 추가 (메모리 초과 방지)
                            if (!visitedBFS.contains(nComb)) {
                                visitedBFS.add(nComb);
                                q.add(nComb);
                            }
                        }
                    }
                }
            }
        }
    }

    static int[][] getPos(int comb) {
        int[][] combPos = new int[5][2];
        int idx = 0;
        for (int num = 0; num < n * m; num++) {
            if (((1 << num) & comb) > 0) {
                combPos[idx][0] = num / m;
                combPos[idx][1] = num % m;
                idx++;
            }
        }

        return combPos;
    }

    static int calculate(int[][] pos) {
        int cnt = 0;
        for (int i = 0; i < 5; i++)
            cnt += grid[pos[i][0]][pos[i][1]];

        return cnt;
    }
}