//
// Created by hex on 25. 10. 13..
//
#include <iostream>
#include <vector>

#define ii pair<int, int>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<ii> info(N, {0, 0});
    for (auto& i : info) {
        cin >> i.first >> i.second; // weight, value
    }

    vector<int> dp(K + 1, 0);
    for (const auto& i : info) {
        for (int k = K; k >= i.first; k--) {
            dp[k] = max(dp[k], dp[k - i.first] + i.second);
        }
    }

    cout << dp[K] << '\n';
}