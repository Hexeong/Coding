//
// Created by hex on 25. 10. 23..
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        int K, N; cin >> K >> N;
        vector<PII> edges(N);
        for (int i = 0; i < N; i++) {
            cin >> edges[i].first >> edges[i].second; // time, exp
        }

        vector<int> dp(K + 1, 0);
        for (const auto& e : edges) {
            for (int k = K; k >= e.first; k--)
                dp[k] = max(dp[k], dp[k - e.first] + e.second);
        }

        cout << dp[K] << endl;
    }
}