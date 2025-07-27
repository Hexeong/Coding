// https://www.acmicpc.net/problem/17142
#include <iostream>
#include <queue>

using namespace std;

struct virus {
    int x;
    int y;
    int activated_time; // 활성 상태, 활성 바이러슥 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스도 활성으로 변한다.
    virus(int _x, int _y, int _activated_time) : x(_x), y(_y), activated_time(_activated_time) {}
};

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int N, M;
int min_sec = 1000000; // INF를 나타내는 충분한 큰 값
int space[50][50]; // 빈 칸 0, 벽 1, 바이러스 2
int visited[10][50][50];
vector<pair<int, int>> v;

void find_min_sec(int depth, int cur_idx, int min_v, bool is_not_all_diffused, int prev_space[50][50]) {
    if (depth == M) {
        if (is_not_all_diffused)
            return;

        min_sec = min(min_sec, min_v);
        return;
    }

    int cur_space[50][50];
    for (int i = cur_idx; i < v.size(); i++) {
        // 현재 상태에 대한 처리; 현재 idx의 virus를 space에서 추가로 확산시켰을 때의 도합 min sec을 찾는 과정
        int cur_max_v = 0;
        bool cur_is_not_all_diffused = false;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (space[j][k] != 1 && visited[i][j][k] == -1 && prev_space[j][k] == -1) {
                    // 벽이 아닌데, 가지 않은 곳에 대해서 검사. 둘다 가지 않았으면 현재까지 모두 확산되지 않았다고 표시
                    cur_is_not_all_diffused = true;
                    cur_space[j][k] = -1;
                    continue;
                } // 벽인 곳은 모두가 bfs로 sec가 입력되지 않았기에 무시하고 넘어가도 된다.

                if (visited[i][j][k] == -1) // prev_space도 -1이면 벽이므로, 어차피 여기서 -1으로 되기에 다음 계산에 영향을 주지 않는다.
                    cur_space[j][k] = prev_space[j][k];
                else if (prev_space[j][k] == -1)
                    cur_space[j][k] = visited[i][j][k];
                else
                    cur_space[j][k] = min(prev_space[j][k], visited[i][j][k]);
                cur_max_v = max(cur_max_v, cur_space[j][k]); // 지금까지의 바이러스를 고려했을 때 모두 확산되기까지의 초를 저장
            }
        }
        // 재귀 호출
        find_min_sec(depth + 1, i + 1, cur_max_v, cur_is_not_all_diffused, cur_space);
    }
}

void diffusion_by_bfs(int idx, int x, int y) {
    queue<virus> q;
    q.push(virus(x, y, 0));
    visited[idx][y][x] = 0;

    while (!q.empty()) {
        virus p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (visited[idx][ny][nx] == -1 && space[ny][nx] != 1) { // 벽이 아니고, 방문하지 않은 경우
                visited[idx][ny][nx] = p.activated_time + 1;
                q.push(virus(nx, ny, p.activated_time + 1));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    fill(&visited[0][0][0], &visited[0][0][0] + 10 * 50 * 50, -1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];
            if (space[i][j] == 2)
                v.push_back({j, i});
        }
    }

    for (int i = 0; i < v.size(); i++) { // 각 바이러스마다 확산시켰을 때의 결과
        diffusion_by_bfs(i, v[i].first, v[i].second);
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            visited[j][v[i].second][v[i].first] = 0;
        }
    }

    int cur_space[50][50];
    fill(&cur_space[0][0], &cur_space[0][0] + 50 * 50, -1);
    find_min_sec(0, 0, 1000000, true, cur_space);

    if (min_sec == 1000000)
        cout << "-1\n";
    else
        cout << min_sec << "\n";
}