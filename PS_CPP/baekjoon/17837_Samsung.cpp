// https://www.acmicpc.net/problem/17837
#include <iostream>
#include <vector>

using namespace std;

struct horse {
    int x;
    int y;
    int direction;
    horse(int _x, int _y, int _direction) : x(_x), y(_y), direction(_direction) {}
};

int N, K; // 말은 쌓을 수 있음
int color[12][12];
vector<int> board[12][12]; // 흰 빨 파로 색칠되어 있음
vector<horse> horses; // idx가 number?

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool move_marker() {
    for (int i = 0; i < K; i++) {
        // 1번 말부터 K번 말까지 이동,
        // 한 말이 이동시 위에 올려져 있는 말도 함께 이동
        int cur_x = horses[i].x;
        int cur_y = horses[i].y;
        int ny = cur_y + dy[horses[i].direction];
        int nx = cur_x + dx[horses[i].direction];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || color[ny][nx] == 2) { // 파랑색이거나 밖으로 벗어나려고 할때
            horses[i].direction = (horses[i].direction + 2) % 4;
            ny = horses[i].y + dy[horses[i].direction];
            nx = horses[i].x + dx[horses[i].direction];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if (color[ny][nx] == 0) { // 방향을 반대로 바꿔 이동하려고 하는 칸이 흰색인 경우
                // 비어 있든, 비어있지 않든 기존 칸에서의 자신의 위치를 파악한 뒤, 자신 포함 자신의 위에 쌓여있는 것들을 다음 칸으로 이동
                int j = 0;
                while (board[cur_y][cur_x][j] != i) // 기존 칸에서 자신이 몇번째에 있는지 확인
                    j++;
                for (int k = j; k < board[cur_y][cur_x].size(); k++) {
                    // 기존 칸에서 자신과 자신 위에 있는 말을 이동
                    board[ny][nx].push_back(board[cur_y][cur_x][k]);

                    horses[board[cur_y][cur_x][k]].y = ny;
                    horses[board[cur_y][cur_x][k]].x = nx;
                }
                if (board[ny][nx].size() >= 4)
                    return true;
                while (j < board[cur_y][cur_x].size()) { // 기존 칸에서 자신과 자신 위에 있는 말을 제거
                    board[cur_y][cur_x].erase(board[cur_y][cur_x].begin() + j);
                }
            } else if (color[ny][nx] == 1) { // 방향을 반대로 바꿔 이동하려고 하는 칸이 빨간색인 경우
                // 비어 있든, 비어 있지 않든 그 위에 쌓는 것임. 하지만 쌓는 순서는 반대로
                int j = 0;
                while (board[cur_y][cur_x][j] != i) // 기존 칸에서 자신이 몇번째에 있는지 확인
                    j++;
                for (int k = (int)board[cur_y][cur_x].size() - 1; k >= j; k--) {
                    // 기존 칸에서 자신과 자신 위에 있는 말을 이동, 하지만 거꾸로 쌓기
                    board[ny][nx].push_back(board[cur_y][cur_x][k]);
                    horses[board[cur_y][cur_x][k]].y = ny;
                    horses[board[cur_y][cur_x][k]].x = nx;
                }
                if (board[ny][nx].size() >= 4)
                    return true;
                while (j < board[cur_y][cur_x].size()) { // 기존 칸에서 자신과 자신 위에 있는 말을 제거
                    board[cur_y][cur_x].erase(board[cur_y][cur_x].begin() + j);
                }
            } // 파랑색이면 방향만 바꿔지고, 칸은 이동하지 않는다.
        }
        else if (color[ny][nx] == 0) { // 0 white, 1 red, 2 blue
            // 비어 있든, 비어있지 않든 기존 칸에서의 자신의 위치를 파악한 뒤, 자신 포함 자신의 위에 쌓여있는 것들을 다음 칸으로 이동
            int j = 0;
            while (board[cur_y][cur_x][j] != i) // 기존 칸에서 자신이 몇번째에 있는지 확인
                j++;
            for (int k = j; k < board[cur_y][cur_x].size(); k++) {
                // 기존 칸에서 자신과 자신 위에 있는 말을 이동
                board[ny][nx].push_back(board[cur_y][cur_x][k]);

                horses[board[cur_y][cur_x][k]].y = ny;
                horses[board[cur_y][cur_x][k]].x = nx;
            }
            if (board[ny][nx].size() >= 4)
                return true;
            while (j < board[cur_y][cur_x].size()) { // 기존 칸에서 자신과 자신 위에 있는 말을 제거
                board[cur_y][cur_x].erase(board[cur_y][cur_x].begin() + j);
            }
        }
        else if (color[ny][nx] == 1) {
            // 비어 있든, 비어 있지 않든 그 위에 쌓는 것임. 하지만 쌓는 순서는 반대로
            int j = 0;
            while (board[cur_y][cur_x][j] != i) // 기존 칸에서 자신이 몇번째에 있는지 확인
                j++;
            for (int k = (int)board[cur_y][cur_x].size() - 1; k >= j; k--) {
                // 기존 칸에서 자신과 자신 위에 있는 말을 이동, 하지만 거꾸로 쌓기
                board[ny][nx].push_back(board[cur_y][cur_x][k]);
                horses[board[cur_y][cur_x][k]].y = ny;
                horses[board[cur_y][cur_x][k]].x = nx;
            }
            if (board[ny][nx].size() >= 4)
                return true;
            while (j < board[cur_y][cur_x].size()) { // 기존 칸에서 자신과 자신 위에 있는 말을 제거
                board[cur_y][cur_x].erase(board[cur_y][cur_x].begin() + j);
            }
        }
    }
    return false;
}

void process() {
    int turn = 0;
    // 말이 4개 이상 쌓이는 순간 게임이 종료됨, move_marker()가 말이 4개 이상 쌓이면 true를 뱉어내 종료
    do {
        if (turn > 1000) {
            cout << "-1\n";
            return;
        }
        turn++;
    }
    while (!move_marker());

    cout << turn << "\n";
}

int translate_direction(int d) { // 위쪽, 오른쪽, 아래쪽, 왼쪽
    if (d == 2) return 3;
    if (d == 3) return 0;
    if (d == 4) return 2;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> color[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        horses.push_back(horse(c - 1, r - 1, translate_direction(d)));
        board[r - 1][c - 1].push_back(horses.size() - 1);
    }

    process();

    return 0;
}