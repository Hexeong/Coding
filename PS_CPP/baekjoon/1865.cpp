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

void floyd(vector<vector<ll>>& dist, int N) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] == MAX_LLONG || dist[k][j] == MAX_LLONG) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, M, W; cin >> N >> M >> W;

        vector<vector<ll>> dist(N + 1, vector<ll>(N + 1, MAX_LLONG));
        for (int i = 0; i < M; i++) {
            ll u, v, w; cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        for (int i = 0; i < W; i++) {
            ll u, v, w; cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], -w);
        }

        // 싸이클에 대한 예외 처리를 알려주지 않았으므로, 존재한다고 생각하고 문제를 풀자.
        for (int i = 1; i <= N; i++)
            if (dist[i][i] == MAX_LLONG)
                dist[i][i] = 0;

        floyd(dist, N);

        bool isPossible = false;
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                if (dist[i][j] == MAX_LLONG || dist[j][i] == MAX_LLONG) continue;
                if (dist[i][j] + dist[j][i] < 0) {
                    isPossible = true;
                    break;
                }
            }
        }

        if (isPossible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}