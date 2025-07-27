#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
int tot_second = 0;
int direction = 2;
bool board[100][100];
bool visited[100][100];
queue<pair<int, int>> snake; // 처음, back이 뱀의 머리, 끝, front가 뱀의 꼬리

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool check_wall(int next_y, int next_x) {
    if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
        return true;
    return false;
}

bool move_snake(int second, char next_dir) {
    // second동안 이동
    pair<int, int> cur_pos;
    for (int i = 0; i < second; i++) {
        cur_pos = snake.back();

        // 현재 몸통이나 벽에 부딫힌 경우
        if (visited[cur_pos.second + dy[direction]][cur_pos.first + dx[direction]]
            || check_wall(cur_pos.second + dy[direction],cur_pos.first + dx[direction])) {

            // 부딫히기까지의 초를 tot_second에 더하고 return
            tot_second += (i + 1);
            return false;
        }

        // 머리를 다음칸에 위치시키기
        snake.push(make_pair(cur_pos.first + dx[direction], cur_pos.second + dy[direction]));
        visited[snake.back().second][snake.back().first] = true;

        // 사과가 없다면
        if (!board[snake.back().second][snake.back().first]) {
            // 꼬리도 없애기
            visited[snake.front().second][snake.front().first] = false;
            snake.pop();
        }
        // 사과가 있으면, 머리 부분 위치의 사과 없애기
        else board[snake.back().second][snake.back().first] = false;
    }
    tot_second += second;

    // 방향 전환
    if (next_dir == 'L')
        direction = (direction - 1 < 0 ? 3 : direction - 1);
    else
        direction = (direction + 1) % 4;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int y, x;
        cin >> y >> x;
        board[y - 1][x - 1] = true;
    }

    // 처음 위치 삽입
    snake.push(make_pair(0, 0));

    cin >> L;
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;

        if (!move_snake(X - tot_second, C)) {
            cout << tot_second << "\n";
            return 0;
        }
    }

    // 방향 전환이 모두 끝나고도 뱀이 끝까지 이동하도록 실행
    // 이때, 어차피 N <= 100이므로, 최소 벽을 만나기에 방향전환은 상관없다.
    if (!move_snake(100, 'R'))
        cout << tot_second << "\n";

    return 0;
}