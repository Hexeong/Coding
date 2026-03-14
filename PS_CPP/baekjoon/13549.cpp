//
// Created by admin on 2025-08-25.
//
#include <cstring>
#include <iostream>
#include <queue>

#define MAX_INT 210000000

using namespace std;

typedef pair<int, int> ii;

int visited[200001];

void bfs(int N, int K) {
    queue<ii> q;
    visited[N] = 0;
    q.push(make_pair(N, 0));

    while (!q.empty()) {
        ii p = q.front();
        q.pop();

        if (2 * p.first > -1 && 2 * p.first < 200001 && p.second < visited[2 * p.first]) {
            visited[2 * p.first] = p.second;
            q.push({2 * p.first, p.second});
        }
        if (p.first + 1 > -1 && p.first + 1 < 200001 && p.second + 1 < visited[p.first + 1]) {
            visited[p.first + 1] = p.second + 1;
            q.push({p.first + 1, p.second + 1});
        }
        if (p.first - 1 > -1 && p.first - 1 < 200001 && p.second + 1 < visited[p.first - 1]) {
            visited[p.first - 1] = p.second + 1;
            q.push({p.first - 1, p.second + 1});
        }
    }

    cout << visited[K] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K; cin >> N >> K;
    fill(visited, visited + 200001, MAX_INT);
    bfs(N, K);
}