//
// Created by admin on 2025-08-13.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> node;

int map[300][300][500];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs_with_next_turn(node cur, int N, int M, int turn) { // 다음 턴의 녹을 빙산에 대해서 계산과 함께 현재 턴의 방문 처리
    queue<node> q;
    int nearby_zero = 0;
    for (int j = 0; j < 4; j++) {
        int ny = cur.first + dy[j];
        int nx = cur.second + dx[j];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

        if (map[ny][nx][turn] == 0)
            nearby_zero++;
    }
    map[cur.first][cur.second][turn + 1] = // 다음 레벨의 빙산 크기 계산
        map[cur.first][cur.second][turn] >= nearby_zero ? map[cur.first][cur.second][turn] - nearby_zero : 0;
    map[cur.first][cur.second][turn] = -1; // 방문 처리
    q.push(cur);

    while(!q.empty()) {
        cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

            if (map[ny][nx][turn] > 0) {
                nearby_zero = 0;
                for (int j = 0; j < 4; j++) {
                    int nny = ny + dy[j];
                    int nnx = nx + dx[j];

                    if (nnx < 0 || nnx >= M || nny < 0 || nny >= N) continue;

                    if (map[nny][nnx][turn] == 0)
                        nearby_zero++;
                }
                map[ny][nx][turn + 1] = map[ny][nx][turn] >= nearby_zero ? map[ny][nx][turn] - nearby_zero : 0;
                map[ny][nx][turn] = -1; // 방문 처리
                q.push({ny, nx});
            }
        }
    }
}

int calculate(int N, int M, int turn) {
    bool flag = false;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < M; k++) {
            if (map[j][k][turn] > 0) { // bfs 검사한 곳이 아니거나 바닷물(0)이 아니거나
                if (flag)
                    // 이미 한번 bfs를 진행했는데, 또 ice가 있는 경우이므로 바로 종료
                    // 즉, 2 덩어리로 나뉜 경우이다.
                    return turn;

                // bfs 검사 시작
                bfs_with_next_turn({j, k}, N, M, turn);
                flag = true;
            }
        }
    }

    if (!flag) // 다 녹은 경우, bfs검사를 하나도 하지 않았기에 flag = false인 상태
        return -1;

    return -2; // 다 녹지 않았지만, 두 덩어리이지 않은 경우
}

int main() {
    // 1초 : 1^8 computing
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> map[i][j][0];
        }

    int result;
    int turn = 0;
    while (true) {
        // bfs하면서 녹을 양을 계산 및 녹은 뒤에 두 덩어리 이상인지 계산
        // 최악의 경우, 10000개가 붙어서 10으로 설정되어 있을 때, 10000 * 500(50 * 10)의 computing을 진행
        // 두 덩어리 이상인지 계산하는 방법은 1번의 bfs 이후 방문하지 않은 얼음이 있을 경우, 해당 턴을 출력

        result = calculate(N, M, turn);
        if (result == -1) {
            cout << 0 << endl;
            return 0;
        }
        if (result != -2) {
            cout << result << endl;
            return 0;
        }
        turn++;
    }
}