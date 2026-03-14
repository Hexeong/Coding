//
// Created by hex on 25. 10. 27..
//
#include <iostream>
#include <vector>
#include <queue>

#define MAX_LLONG 9223372036854775807

using namespace std;

using ll = long long;

using pll = pair<ll, ll>;

// 트리는 사이클을 생성하지 않으므로 BFS를 사용한 O(V)가 더 빠르게 해결 가능
void dijkstra(const vector<vector<pll>>& edges, vector<ll>& dist, int start) {
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, start});
    dist[start] = 0;

    while (!q.empty()) {
        pll p = q.top();
        q.pop();

        if (dist[p.second] < p.first)
            continue;

        for (const auto& e : edges[p.second]) {
            ll n_dist = p.first + e.second;

            if (n_dist < dist[e.first]) {
                dist[e.first] = n_dist;
                q.push({n_dist, e.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V; cin >> V;
    vector<vector<pll>> edges(V + 1, vector<pll>());
    // dijkstra : log(100,000) * 100,000 = 33,300,000
    for (int i = 0; i < V; i++) {
        int u; cin >> u;
        while (1) {
            ll v, w;
            cin >> v;
            if (v == -1) break;

            cin >> w;

            edges[u].push_back({v, w});
        }
    }

    vector<ll> dist(V + 1, MAX_LLONG);
    dijkstra(edges, dist, 1);
    // 다익스트라로 1을 시작 정점으로 해서 가장 긴 거리 2개를 찾기, 이때 2개의 거리를 더한 것이 지름
    // 논리 오류 발생 : 거리가 긴 2개의 정점으로 가기 위한 길에 겹치는 부분이 있는 경우 답이 될 수 없음.

    // 특정 점에서 최대 거리를 가진 U가 있을 떄, U에서 다시 측정한 최대 거리 P가 트리의 지름이 된다.
    pll p = {1, 0};
    for (int i = 2; i <= V; i++) {
        if (dist[i] > p.second) {
            p.first = i;
            p.second = dist[i];
        }
    }

    vector<ll> new_dist(V + 1, MAX_LLONG);
    dijkstra(edges, new_dist, p.first);

    ll max_v = 0;
    for (int i = 1; i <= V; i++)
        max_v = max(max_v, new_dist[i]);

    cout << max_v << '\n';
}