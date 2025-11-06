//
// Created by hex on 25. 11. 6..
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(vector<vector<int>>& edges, vector<int>& in_degree, queue<int>& q, int N) {
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        cout << cur << " ";

        for (int& v : edges[cur]) {
            in_degree[v]--;

            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<vector<int>> edge(N + 1);
    vector<int> in_degree(N + 1, 0);
    queue<int> q;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        in_degree[v]++;
    }

    for (int i = 1; i <= N; i++)
        if (in_degree[i] == 0)
            q.push(i);

    solve(edge, in_degree, q, N);
}