//
// Created by hex on 25. 10. 23..
//
#include <iostream>
#include <vector>
#include <queue>

#define INT_MAX 2147483647

using namespace std;

using PII = pair<int, int>;

void dijkstra(int start, int end, const vector<vector<PII>>& edges, vector<int>& dist) {
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        PII p = pq.top();
        pq.pop();

        if (dist[p.second] < p.first)
            continue;

        for (const auto& n : edges[p.second]) {
            int n_dist = p.first + n.second;

            if (n_dist < dist[n.first]) {
                dist[n.first] = n_dist;
                pq.push({n_dist, n.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        int s, t; cin >> s >> t;


        vector<vector<PII>> edge(N + 1, vector<PII>());
        vector<int> dist(N + 1, INT_MAX);
        for (int i = 0; i < M; i++) {
            int u, v, w; cin >> u >> v >> w;

            edge[u].push_back(PII(v, w));
            edge[v].push_back(PII(u, w));
        }

        dijkstra(s, t, edge, dist);

        if (dist[t] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[t] << '\n';
    }
}