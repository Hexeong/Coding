//
// Created by hex on 25. 10. 23..
//
#include <iostream>
#include <vector>
#include <algorithm>

#define LLONG_MAX 9223372036854775807

using namespace std;

void floyd_warshall(vector<vector<long long>> &dist, int N) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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

        vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, LLONG_MAX));
        for (int i = 1; i <= N; i++)
            dist[i][i] = 0;
        for (int i = 0; i < M; i++) {
            long long a, b, c; cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }

        floyd_warshall(dist, N);

        long long min_v = LLONG_MAX;
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                long long cur_v = 0;
                for (int k = 1; k <= N; k++) {
                    cur_v += min(dist[i][k], dist[j][k]);
                }
                min_v = min(min_v, cur_v);
            }
        }

        cout << min_v << '\n';
    }
}