#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool flag;
int area = 0;
bool map[50][50];
bool visit[50][50];

int dx[] = {0, 1, 0, -1}; // 북, 동, 남, 서 순서
int dy[] = {-1, 0, 1, 0};

void process(pair<int, int> cur_pos, int direction) {
    // 초기 자리 방문 처리
    visit[cur_pos.second][cur_pos.first] = true;
    area++;

    while (true) {
        bool found = false;
        for (int i = 0; i < 4; i++) {
            direction = (direction + 3) % 4;
            pair<int, int> next_pos = make_pair(cur_pos.first + dx[direction], cur_pos.second + dy[direction]);

            if (!map[next_pos.second][next_pos.first]
                && !visit[next_pos.second][next_pos.first]) {

                area++;
                visit[next_pos.second][next_pos.first] = true;
                cur_pos = next_pos;
                found = true;
                break;
            }
        }

        if (!found) {
            pair<int, int> back_pos = make_pair(cur_pos.first - dx[direction], cur_pos.second - dy[direction]);

            if (map[back_pos.second][back_pos.first])
                return;

            cur_pos = back_pos;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<int, int> init_pos;
    int direction;

    cin >> N >> M;
    cin >> init_pos.second >> init_pos.first >> direction;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }

    process(init_pos, direction);

    cout << area << "\n";

    return 0;
}