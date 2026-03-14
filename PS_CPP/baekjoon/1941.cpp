//
// Created by admin on 2025-08-19.
//
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pos;

char map[5][5]; // 'S', 'Y'
bool visited[5][5];
vector<pos> path;
long long result = 0;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

bool is_adjacent_with_road() {
    memset(visited, false, sizeof(visited));
    for (auto& a : path)
        visited[a.first][a.second] = true;

    queue<pos> q;
    q.push(path[0]);
    visited[path[0].first][path[0].second] = false;
    int cnt = 1;

    while (!q.empty()) {
        pos p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if (ny < 0 || ny > 4 || nx < 0 || nx > 4 || !visited[ny][nx]) continue;

            visited[ny][nx] = false;
            cnt++;
            q.push({ny, nx});
        }
    }

    return (cnt == 7);
}

bool is_more_than_Y() {
    int s_cnt = 0;

    for (auto& a : path)
        if (map[a.first][a.second] == 'S')
            s_cnt++;

    return s_cnt > 3;
}

void make_road(int last) {
    if (path.size() == 7) {
        if (!is_adjacent_with_road())
            return;

        if (is_more_than_Y())
            result++;
        return;
    }

    for (int i = last + 1; i < 25; i++) {
        path.push_back({i / 5, i % 5});
        make_road(i);
        path.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        for (int j = 0; j < 5; j++) {
            map[i][j] = s[j];
        }
    }

    for (int i = 0; i < 25; i++) {
        path.push_back({i / 5, i % 5});
        make_road(i);
        path.pop_back();
    }

    cout << result << '\n';
}