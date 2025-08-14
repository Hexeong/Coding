//
// Created by admin on 2025-08-14.
//
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pos;
typedef pair<pos, int> path;

char map[1000][1000];
pos person;
queue<pos> fire_pos;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void spread_fire(int w, int h) {
    queue<pos> next_fire_pos;
    while (!fire_pos.empty()) {
        for (int i = 0; i < 4; i++) {
            int nx = fire_pos.front().second + dx[i];
            int ny = fire_pos.front().first + dy[i];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h || map[ny][nx] == '#' || map[ny][nx] == '*') continue;

            // 불의 마커가 person을 덮어쓸 수 있음
            map[ny][nx] = '*';
            next_fire_pos.push({ny, nx});
        }
        // 문제 : 각 불마다 한번만 번져야 함.
        fire_pos.pop();
    }

    while (!next_fire_pos.empty()) {
        fire_pos.push(next_fire_pos.front());
        next_fire_pos.pop();
    }
}

void bfs(int w, int h) {
    queue<path> road;
    road.push({person, 0});
    int move_counter = 0;

    while (!road.empty()) {
        // person 위주 bfs 진행, move를 카운트해 move값이 ++될때마다 불을 확산
        path p = road.front();
        road.pop();

        // person이 벽에 닿은 경우 move + 1을 출력
        if (p.first.first == 0 || p.first.first == h - 1 || p.first.second == 0 || p.first.second == w - 1) {
            cout << p.second + 1 << endl;
            return;
        }

        if (move_counter == p.second) { // 사람이 move를 1번할 때마다 fire를 spread하기 위한 counter 변수
            move_counter++;
            spread_fire(w, h);
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.first.second + dx[i];
            int ny = p.first.first + dy[i];

            // person은 fire와 벽을 지나갈 수 없음
            if (nx < 0 || nx >= w || ny < 0 || ny >= h
                || map[ny][nx] == '#' || map[ny][nx] == '*' || map[ny][nx] == '@') continue;

            map[ny][nx] = '@';
            road.push({{ny, nx}, p.second + 1});
        }
    }

    // while이 끝날 때까지 return이 되지 않고 while문을 탈출하면 IMPOSSIBLE
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int w, h; cin >> w >> h;
        for (int i = 0; i < h; i++) {
            string s; cin >> s;
            for (int j = 0; j < w; j++) {
                map[i][j] = s[j];
                if (map[i][j] == '@')
                    person = {i, j};
                if (map[i][j] == '*')
                    fire_pos.push({i,j});

            }
        }

        bfs(w, h);
        while (!fire_pos.empty())
            fire_pos.pop();
    }
}