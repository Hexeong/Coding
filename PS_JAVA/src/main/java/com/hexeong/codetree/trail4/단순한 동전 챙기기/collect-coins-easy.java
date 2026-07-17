import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int startY, startX, endY, endX;
    
    // 격자 내의 모든 동전을 저장할 리스트
    static List<Coin> coins = new ArrayList<>();
    // 백트래킹 과정에서 내가 선택한 동전들을 담을 리스트
    static List<Coin> selectedCoins = new ArrayList<>();
    
    static int minMoves = Integer.MAX_VALUE;

    // 동전의 위치와 값을 저장할 클래스 (값 기준 오름차순 정렬 기능 포함)
    static class Coin implements Comparable<Coin> {
        int y, x, val;
        public Coin(int y, int x, int val) {
            this.y = y; this.x = x; this.val = val;
        }
        @Override
        public int compareTo(Coin o) {
            return this.val - o.val; // 동전 번호가 작은 것부터 정렬
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                char c = line.charAt(j);
                if (c == 'S') {
                    startY = i; startX = j;
                } else if (c == 'E') {
                    endY = i; endX = j;
                } else if (c >= '1' && c <= '9') {
                    coins.add(new Coin(i, j, c - '0'));
                }
            }
        }
        
        // 1. 문제 조건: "반드시 번호가 증가하는 순서대로 주워야 함"
        // 입력받은 동전들을 미리 번호 순서대로 정렬해 둡니다.
        Collections.sort(coins);
        
        // 2. 동전 고르기 시작 (백트래킹)
        backt(0, 0);
        
        // 3. 결과 출력
        if (minMoves == Integer.MAX_VALUE) {
            System.out.println(-1); // 불가능한 경우
        } else {
            System.out.println(minMoves);
        }
    }

    // depth: 현재까지 고른 동전의 개수, startIdx: 중복 선택 방지를 위한 탐색 시작 인덱스
    static void backt(int depth, int startIdx) {
        // 동전을 3개 이상 골랐다면, 현재 고른 조합으로 이동 거리를 계산하여 최솟값 갱신
        if (depth >= 3) {
            int moves = calcMoves();
            minMoves = Math.min(minMoves, moves);
        }
        
        // 주어진 동전들 중에서 순서대로 고르기 (조합)
        for (int i = startIdx; i < coins.size(); i++) {
            selectedCoins.add(coins.get(i));
            
            backt(depth + 1, i + 1); // i + 1을 넘겨서 다음 번호의 동전들만 고르도록 함
            
            selectedCoins.remove(selectedCoins.size() - 1); // 상태 복구
        }
    }

    // 선택된 동전들의 경로에 따른 총 이동 횟수(최단 거리)를 계산하는 메서드
    static int calcMoves() {
        int moves = 0;
        int curY = startY;
        int curX = startX;
        
        // 시작점 -> 첫 번째 동전 -> 두 번째 동전 ... 순서로 이동 거리 누적
        for (Coin c : selectedCoins) {
            moves += Math.abs(curY - c.y) + Math.abs(curX - c.x); // 맨해튼 거리 공식
            curY = c.y;
            curX = c.x;
        }
        
        // 마지막 동전 -> 도착점(E) 이동 거리 추가
        moves += Math.abs(curY - endY) + Math.abs(curX - endX);
        
        return moves;
    }
}