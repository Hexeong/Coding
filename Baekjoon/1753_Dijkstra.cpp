// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <queue>
#include <vector>

#define INF 2147483647

using namespace std;

int V, E;

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>> &graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (const auto &e : graph[u]) {
            int v = e.first;
            int w = e.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V);

    int start; cin >> start;
    for (int i = 0; i < E; i++) {
        int start_v, adj_v, weight;
        cin >> start_v >> adj_v >> weight;
        graph[start_v - 1].push_back(make_pair(adj_v - 1, weight));
    }

    vector<int> dist = dijkstra(start - 1, graph);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
    }
}