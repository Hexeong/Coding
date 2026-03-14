//
// Created by admin on 2025-08-12.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int x;
    int y;
    int day;
    node(int x, int y, int day) : x(x), y(y), day(day) {}
};

int map[1000][1000];
vector<node> ripe_tomato_list;
int not_ripe_tomato_cnt = 0;
int max_day = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int M, int N) {
    queue<node> q;
    for (auto i : ripe_tomato_list)
        q.push(i);

    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        max_day = max(max_day, cur.day);

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

            if (map[ny][nx] == 0) {
                map[ny][nx] = 1;
                q.push(node(nx, ny, cur.day + 1));
                not_ripe_tomato_cnt--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N; cin >> M >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> map[i][j]; // 1 : 익은 토마토, 0 : 익지 않은 토마토, -1 : 토마토가 없는 곳
            if (map[i][j] == 1)
                ripe_tomato_list.push_back(node(j, i, 0));
            else if (map[i][j] == 0)
                not_ripe_tomato_cnt++;
        }


    bfs(M, N);

    cout << (not_ripe_tomato_cnt != 0 ? -1 : max_day) << endl;

}