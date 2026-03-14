//
// Created by admin on 2025-10-12.
//
#include <iostream>
#include <vector>
#include <queue>

#define ii pair<int, int>
#define INT_MAX 2147483647

using namespace std;

void solve(int start, const vector<vector<ii>>& costs, vector<int>& dist) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        ii cur = pq.top();
        pq.pop();

        if (dist[cur.second] < cur.first)
            continue;

        for (const auto& next : costs[cur.second]) {

            if (cur.first + next.first < dist[next.second]) {
                dist[next.second] = cur.first + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<ii>> costs(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        costs[u].push_back({w, v});
    }

    int start, end; cin >> start >> end;
    vector<int> dist(N + 1, INT_MAX);

    solve(start, costs, dist);
    cout << dist[end] << '\n';
}