//
// Created by admin on 2025-08-19.
//
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> area;

char map[12][6];
bool visited[12][6];
vector<area> adjacent;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void findHit(int y, int x, char* target) {
    if (map[y][x] == '.') return;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || nx >= 6 || ny < 0 || ny >= 12 || visited[ny][nx] || map[ny][nx] != *target) continue;

        adjacent.push_back({ny, nx});
        visited[ny][nx] = true;
        findHit(ny, nx, target);
    }
}

void move() {
    for (int j = 0; j < 6; j++) {
        char buf[12] = {'.','.','.','.','.','.','.','.','.','.','.','.'}; // 12개
        int k = 11;
        for (int i = 11; i > -1; i--) {
            if (visited[i][j]) { // 터진 것 외에는 모두 true
                buf[k--] = map[i][j];
            }
        }

        for (int i = 11; i > -1; i--)
            map[i][j] = buf[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 12; i++) {
        string s; cin >> s;
        for (int j = 0; j < 6; j++) {
            map[i][j] = s[j];
        }
    }

    bool flag;
    int hit_cnt = 0;
    while (true) {
        memset(visited, false, sizeof(visited));
        flag = false;

        for (int i = 11; i > -1; i--) {
            for (int j = 0; j < 6; j++) {
                if (!visited[i][j]) {
                    adjacent.push_back({i, j});
                    visited[i][j] = true;
                    findHit(i, j, &map[i][j]);
                    if (adjacent.size() >= 4) {
                        flag = true;
                        while (!adjacent.empty()) { // 터진 것임을 표시
                            visited[adjacent.back().first][adjacent.back().second] = false;
                            adjacent.pop_back();
                        }
                    } else adjacent.clear();
                }
            }
        }

        if (flag) {
            hit_cnt++;
            move();
        } else {
            cout << hit_cnt << "\n";
            break;
        }
    }
}