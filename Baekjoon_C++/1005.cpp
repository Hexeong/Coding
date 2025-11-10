//
// Created by hex on 25. 11. 10..
//
#include <iostream>
#include <vector>
#include <queue>

#define MAX_LLONG 9223372036854775807LL

using namespace std;

using ll = long long;

using pll = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;

        vector<vector<pll>> out_edge(N + 1);
        vector<ll> cost(N + 1);
        vector<int> in_degree(N + 1, 0);

        for (int i = 1; i <= N; i++) {
            cin >> cost[i];
        }
        for (int i = 1; i <= K; i++) {
            int X, Y; cin >> X >> Y;
            out_edge[X].push_back({Y, cost[X]});
            in_degree[Y]++;
        }

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        for (int i = 1; i <= N; i++)
            if (in_degree[i] == 0)
                pq.push({0, i});

        vector<ll> dist(N + 1, 0);
        while (!pq.empty()) {
            pll p = pq.top();
            pq.pop();

            if (dist[p.second] > p.first) continue;

            for (auto& e : out_edge[p.second]) {
                int next_c = p.first + e.second;

                if (next_c > dist[e.first]) {
                    dist[e.first] = next_c;
                    pq.push({dist[e.first], e.first});
                }
            }
        }

        int W; cin >> W;

        cout << dist[W] + cost[W] << '\n';
    }
}