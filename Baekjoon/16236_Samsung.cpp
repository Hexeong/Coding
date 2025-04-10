// https://www.acmicpc.net/problem/16236
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int space[20][20]; // 0은 빈칸, 1 ~ 6은 물고기 크기, 9는 상어의 위치
int eaten_fish_cnt{0}, shark_size{2};
pair<int, int> shark_pos;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool compare(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

struct target_info {
    int x;
    int y;
    int dist;
    target_info(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist) {}
};

int bfs(pair<int, int> &n_f_p) {
    int dist_min = 20000000; // 임의의 INF 값
    bool visit[20][20] = {false};

    queue<target_info> q;
    q.push(target_info(shark_pos.first, shark_pos.second, 0));
    visit[shark_pos.second][shark_pos.first] = true;

    while (!q.empty()) {
        target_info p = q.front();
        q.pop();

        // dist_min이 한번 정해지면 dist_min은 바뀌지 않음. 논리적으로
        // 거리가 같은 경우도, 밑의 로직은 다른 칸들을 살펴보기 위함이므로 다른 칸들의 dist > dist_min이므로 제외해도 됨.
        if (p.dist >= dist_min) continue;

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if (!visit[ny][nx] && space[ny][nx] <= shark_size) {
                visit[ny][nx] = true;
                q.push(target_info(nx, ny, p.dist + 1));
                if (space[ny][nx] != 0 && space[ny][nx] < shark_size) {
                    pair<int, int> n_pos = {nx, ny};
                    if (p.dist + 1 < dist_min || (p.dist + 1 == dist_min && compare(n_pos, n_f_p))) {
                        dist_min = p.dist + 1;
                        n_f_p = {nx, ny};
                    }
                }
            }
        }
    }

    return dist_min;
}

int shark_eating_time() {
    int time = 0;

    while (true) {
        pair<int, int> next_fish_pos = {-1, -1};

        int dist_min = bfs(next_fish_pos);

        // 먹을 수 있는 물고기를 찾아봤지만 없는 경우, 즉 for문이 실행되지 않은 경우, 또는 먹이가 더이상 없는 경우]
        // 엄마 호출
        if (next_fish_pos.first == -1)
            break;

        // 크기가 커지는지 확인 후 처리
        eaten_fish_cnt++;
        if (eaten_fish_cnt == shark_size) {
            eaten_fish_cnt = 0;
            shark_size++;
        }

        // 상어 다음 위치로 이동, 이동하면서 다음 자리 또한 0으로 초기화
        space[shark_pos.second][shark_pos.first] = 0;
        shark_pos = next_fish_pos;



        // 시간 갱신
        time += dist_min;
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];
            // if (space[i][j] != 0 && space[i][j] != 9) {
            //     fishes[space[i][j]].push_back({j, i});
            // }
            if (space[i][j] == 9) {
                shark_pos = make_pair(j, i);
            }
        }

    cout << shark_eating_time() << "\n";
}