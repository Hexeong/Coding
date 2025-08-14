//
// Created by admin on 2025-08-14.
//
#include <iostream>
#include <queue>

#define INT_MAX 2100000000

using namespace std;

typedef pair<int, int> pos;

int map[100][100];
int map_counter = 2;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

vector<vector<pos>> boundary_q;

void bfs_seperation(int N, pos p) {
    queue<pos> q;
    map[p.first][p.second] = map_counter;
    q.push(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        bool is_boundary = false;
        for (int i = 0; i < 4; i++) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N // 영역을 벗어나거나
                || map[ny][nx] == map_counter) continue; // 지나온 곳이면

            if (map[ny][nx] == 0) { // 다음 위치가 바다인 현재 위치에 대해서 파악
                is_boundary = true;
                continue;
            }

            map[ny][nx] = map_counter;
            q.push({ny, nx});
        }

        if (is_boundary) { // 현재 위치가 경계일 경우, vector에 저장
            boundary_q[map_counter].push_back(p);
        }
    }
}

void calculate_distance() {
    // 각 경계의 포인트마다 distance를 측정
    int min_distance = INT_MAX;
    for (int i = 2; i < map_counter; i++) {
        for (int j = i + 1; j < map_counter; j++) {

            for (int k = 0; k < boundary_q[i].size(); k++)
                for (int l = 0; l < boundary_q[j].size(); l++)
                    min_distance = min(min_distance,
                        abs(boundary_q[i][k].first - boundary_q[j][l].first)
                        + abs(boundary_q[i][k].second - boundary_q[j][l].second));

        }
    }

    cout << min_distance - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    boundary_q.resize(N * N + 3); // 최악의 경우에 대해서 얼마만큼이 생길지 제대로 생각하자
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) {
                bfs_seperation(N, {i, j});
                map_counter++;
            }
        }

    // 2부터 boundary_q에 각 섬마다의 경계가 주어짐
    calculate_distance();
}