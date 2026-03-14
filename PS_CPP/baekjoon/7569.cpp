//
// Created by admin on 2025-08-13.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int x;
    int y;
    int z;
    int day;
    node(int _x, int _y, int _z, int _day) : x(_x), y(_y), z(_z), day(_day) {}
};

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

int map[100][100][100]; // -1 : X, 0 : 안익은 토마토, 1 : 익은 토마토
vector<node> ripe_tomatoes;
int not_ripe_cnt = 0;
int max_day = 0;

void bfs_tomatoes(int M, int N, int H) {
    queue<node> q;
    for (auto t : ripe_tomatoes)
        q.push(t);

    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        max_day = max(max_day, cur.day);

        for (int i = 0; i < 6; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;

            if (map[nz][ny][nx] == 0) {
                map[nz][ny][nx] = 1;
                q.push(node(nx, ny, nz, cur.day + 1));
                not_ripe_cnt--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, H; cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 0)
                    not_ripe_cnt++;
                else if (map[i][j][k] == 1)
                    ripe_tomatoes.push_back(node{k, j, i, 0});
            }

    bfs_tomatoes(M, N, H);

    cout << (not_ripe_cnt == 0 ? max_day : -1) << endl;
}
