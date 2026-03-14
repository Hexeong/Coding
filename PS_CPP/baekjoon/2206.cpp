//
// Created by admin on 2025-08-13.
//
#include <iostream>
#include <queue>

#define INT_MAX 21000000

using namespace std;

struct node {
    int id;
    int x;
    int y;
    bool is_break;
    int move;
    node(int _x, int _y, int _move, bool _is_break) : x(_x), y(_y), move(_move), is_break(_is_break) {}
    node(int _id, int _x, int _y, int _move, bool _is_break) : id(_id), x(_x), y(_y), is_break(_is_break), move(_move) {}
};

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int map[1000][1000];
int result = INT_MAX;
int id_counter = 2;


void bfs(int M, int N) {
    queue<node> q;
    map[0][0] = 2;
    q.push(node(id_counter, 0, 0, 1, false));

    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        if (cur.move >= result)
            continue;

        if (cur.x == M - 1 && cur.y == N - 1) {
            // 위의 조건 때문에 무조건 cur.move < result임
            result = cur.move;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || map[ny][nx] == cur.id) continue;

            if (map[ny][nx] == 0 || (map[ny][nx] == 3 && cur.id == 2)) {
                map[ny][nx] = cur.id;
                q.push(node(cur.id, nx, ny, cur.move + 1, cur.is_break));
            } else if (map[ny][nx] == 1 && !cur.is_break) {
                q.push(node(3, nx, ny, cur.move + 1, true));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    bfs(M, N);

    cout << (result == INT_MAX ? -1 : result) << endl;
}