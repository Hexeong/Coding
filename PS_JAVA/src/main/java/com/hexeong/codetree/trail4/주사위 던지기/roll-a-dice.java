import java.util.Scanner;
import java.util.*;

public class Main {

    // 1. 기존의 복잡한 dice 배열 대신 3개의 방향 변수만 static으로 관리합니다.
    static int up = 1;
    static int front = 2;
    static int right = 3;

    // 2. 현재 위치(r, c)와 격자 크기(n)도 move 메서드에서 접근할 수 있게 static으로 뺍니다.
    static int r, c, n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int m = sc.nextInt();
        
        // 문제의 좌표는 1-based 이므로 0-based 배열에 맞게 1씩 빼줍니다.
        r = sc.nextInt() - 1;
        c = sc.nextInt() - 1;
        
        int[][] grid = new int[n][n];
        
        // **중요**: 시작 위치에도 처음 주사위의 바닥면(6)이 기록되어야 합니다.
        grid[r][c] = 7 - up; 

        for (int i = 0; i < m; i++) {
            String dir = sc.next();
            move(grid, dir);
        }
        
        // 모든 굴리기가 끝난 후 격자판의 숫자 총합 계산
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }
        System.out.println(totalSum);
    }

    private static void move(int[][] grid, String dir) {
        int nr = r, nc = c;

        // 1. 방향에 따른 다음 이동 위치 계산
        if (dir.equals("U")) nr--;
        else if (dir.equals("D")) nr++;
        else if (dir.equals("R")) nc++;
        else if (dir.equals("L")) nc--;

        // 2. 격자 밖으로 벗어나는 경우, 굴리지 않고 해당 차례를 건너뜁니다 (무시)
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) return;

        // 3. 주사위가 구르는 방향에 따라 3면의 상태를 업데이트합니다.
        int nextUp = up, nextFront = front, nextRight = right;

        if (dir.equals("U")) {
            nextUp = front;
            nextFront = 7 - up;       // 기존 바닥면이 새로운 앞면이 됨
        } else if (dir.equals("D")) {
            nextUp = 7 - front;       // 기존 뒷면이 새로운 윗면이 됨
            nextFront = up;
        } else if (dir.equals("R")) {
            nextUp = 7 - right;       // 기존 왼쪽면이 새로운 윗면이 됨
            nextRight = up;
        } else if (dir.equals("L")) {
            nextUp = right;
            nextRight = 7 - up;       // 기존 바닥면이 새로운 오른쪽면이 됨
        }

        // 4. 계산된 상태와 위치를 실제 static 변수에 적용
        up = nextUp;
        front = nextFront;
        right = nextRight;
        r = nr;
        c = nc;

        // 5. 이동한 격자 위치에 주사위의 바닥면(7 - up) 숫자 기록
        grid[r][c] = 7 - up;
    }
}