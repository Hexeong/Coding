#include <iostream>
#include <queue>

using namespace std;

int N, M;
// bool visit[10][10];
char board[10][10];

int dx[] = {-1, 0, 1, 0};  // left, up, right, down
int dy[] = {0, -1, 0, 1};

struct pos {
    int red_y;
    int red_x;
    int blue_y;
    int blue_x;
    int cnt;

    pos(const int r_y, const int r_x, const int b_y, const int b_x, const int c) {
        red_y = r_y;
        red_x = r_x;
        blue_y = b_y;
        blue_x = b_x;
        cnt = c;
    }
};

int move(const int dir, pos& p) {
    const pos start = p;
    bool sink_red = false;
    bool sink_blue = false;

    if ((dir == 0 && p.red_x < p.blue_x)
        || (dir == 1 && p.red_y < p.blue_y)
        || (dir == 2 && p.red_x > p.blue_x)
        || (dir == 3 && p.red_y > p.blue_y)) {

        while (board[p.red_y + dy[dir]][p.red_x + dx[dir]] != '#') {
            p.red_x += dx[dir];
            p.red_y += dy[dir];
            // visit[p.red_y][p.red_x] = true;
            if (board[p.red_y][p.red_x] == 'O') {
                sink_red = true;
                p.red_x = -1; // 보드에서 사라짐 처리
                p.red_y = -1;
                break;
            }
        }
        while (board[p.blue_y + dy[dir]][p.blue_x + dx[dir]] != '#'
            && !(p.blue_y + dy[dir] == p.red_y && p.blue_x + dx[dir] == p.red_x)) {

            p.blue_x += dx[dir];
            p.blue_y += dy[dir];
            if (board[p.blue_y][p.blue_x] == 'O') {
                sink_blue = true;
                break;
            }
        }
    }
    else {
        while (board[p.blue_y + dy[dir]][p.blue_x + dx[dir]] != '#') {
            p.blue_x += dx[dir];
            p.blue_y += dy[dir];
            if (board[p.blue_y][p.blue_x] == 'O') {
                sink_blue = true;
                p.blue_x = -1; // 보드에서 사라짐 처리
                p.blue_y = -1;
                break;
            }
        }
        while (board[p.red_y + dy[dir]][p.red_x + dx[dir]] != '#'
            && !(p.red_y + dy[dir] == p.blue_y && p.red_x + dx[dir] == p.blue_x)) {

            p.red_x += dx[dir];
            p.red_y += dy[dir];
            // visit[p.red_y][p.red_x] = true;
            if (board[p.red_y][p.red_x] == 'O') {
                sink_red = true;
                break;
            }
        }
    }
    p.cnt++;

    if (sink_red && sink_blue) return 0;
    if (sink_blue) return 0;
    if (start.red_y == p.red_y && start.red_x == p.red_x
        && start.blue_y == p.blue_y && start.blue_x == p.blue_x) return 0;
    if (p.cnt == 11) return 0;
    if (sink_red) return 1;
    return 2;
}

pos bfs(const pos& start) {
    queue<pos> q;
    q.push(pos(start.red_y, start.red_x,
        start.blue_y, start.blue_x, 0));

    // visit[start.red_y][start.red_x] = true;

    while (!q.empty()) {
        const pos p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            // if (!visit[p.red_y + dy[i]][p.red_x + dx[i]]) {
            pos next = p;
            int result = move(i, next);
            if (result == 1) return next;
            if (result == 2) q.push(next);
            // }
        }
    }

    return pos(0,0,0,0,-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> N >> M;

    pos p = pos(0,0,0,0,0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                p.red_x = j;
                p.red_y = i;
            }
            else if (board[i][j] == 'B') {
                p.blue_x = j;
                p.blue_y = i;
            }
        }

    cout << bfs(p).cnt << endl;

    return 0;
}