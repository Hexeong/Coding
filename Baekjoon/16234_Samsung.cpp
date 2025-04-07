// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <queue>

using namespace std;

int N, L, R;

int people[50][50];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool flag = true;

// 2500번 이동 * 2000(인구이동) = 5,000,000
void bfs(int x, int y, bool visit[50][50]) {
    if (visit[y][x])
        return;

    queue<pair<int, int>> q;
    vector<pair<int, int>> union_ground;
    q.push({x, y});
    visit[y][x] = true;
    int sum = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        union_ground.push_back(p);
        sum += people[p.second][p.first];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            int diff_p = abs(people[ny][nx] - people[p.second][p.first]);

            if (diff_p >= L && diff_p <= R && !visit[ny][nx]) {
                // 무조건 차이는 1이상이므로 flag를 통해, 해당 날짜의 연합 유무를 판단할 수 있다.
                flag = true;
                visit[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < union_ground.size(); i++) {
        people[union_ground[i].second][union_ground[i].first] = sum / union_ground.size();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> people[i][j];

    int cnt = 0;
    while (flag) {
        flag = false;
        bool visit[50][50] = { false };

        // 국경선이 열릴 수 있는지 탐색
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                bfs(j, i, visit);
            }

        cnt++;
    }

    cout << cnt - 1 << "\n";

}