#include <iostream>

using namespace std;

// 브루트 포스의 총 연산 : (20 * 20 * 4) ^ 5 = 8000
// 필요 없는 연산 처내기
// 특성 한번에 최댓값은 * 2 밖에 안된다.
// 400 * 4byte

int N;
int max_v = 0;

int dx[] = {-1, 0, 1, 0}; // 왼쪽, 위쪽, 오른쪽, 아래쪽 순서
int dy[] = {0, -1, 0, 1};

void move(int direction, int board[20][20], int new_board[20][20]) {
    int start = 0;
    int end = N;
    int next = 1;
    if (direction == 2 || direction == 3) {
        start = N - 1;
        end = -1;
        next = -1;
    }

    for (int i = 0; i < N; i++) {
        int x = i;
        int y = 0;
        if (direction == 1 || direction == 3) {
            y = x;
        }

        int temp[20] = {0};

        int step = start;
        for (int j = start; j != end; j += next) { // 일단 전부 다 왼쪽, 오른쪽으로 이동
            if (direction == 1 || direction == 3) x = j;
            else y = j;

            if (board[x][y] != 0) {
                temp[step] = board[x][y];
                step += next;
            }
        }

        step = start;
        int j = start + next;
        for (; (j != end && j != end + next); j += next) { // 연속되는 값 합치기
            if (direction == 1 || direction == 3) x = step;
            else y = step;

            if (temp[j] == temp[j - next]) {
                new_board[x][y] = 2 * temp[j - next];
                step += next;
                j += next;
            }
            else {
                new_board[x][y] = temp[j - next];
                step += next;
            }
        }
        if (j != end + next) {
            if (direction == 1 || direction == 3) x = step;
            else y = step;

            new_board[x][y] = temp[end - next];
        }
    }
}

void max_block(int cur_board[20][20], int depth) {
    if (depth == 5) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                max_v = max(max_v, cur_board[i][j]);
        return;
    };

    for (int dir = 0; dir < 4; dir++) {
        int temp_board[20][20] = {0};
        move(dir, cur_board, temp_board);
        max_block(temp_board, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int board[20][20] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    max_block(board, 0);

    cout << max_v << "\n";

    return 0;
}