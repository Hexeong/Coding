//
// Created by hex on 25. 11. 10..
//
#include <iostream>
#include <vector>

#define MAX_INT 2147483647

using namespace std;

void floyd(vector<vector<int>>& dist, int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == MAX_INT || dist[k][j] == MAX_INT) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, MAX_INT));
    for (int i = 0; i <= n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    floyd(dist, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (dist[i][j] == MAX_INT) cout << "0 ";
            else cout << dist[i][j] << " ";
        cout << '\n';
    }
}