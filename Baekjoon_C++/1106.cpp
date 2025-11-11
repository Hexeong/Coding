//
// Created by hex on 25. 11. 11..
//
#include <iostream>
#include <vector>

#define MAX_INT 2147483647

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int C, N; cin >> C >> N;
    vector<pii> info(N);
    int max_customer_cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> info[i].first >> info[i].second; // cost, customer_cnt
        max_customer_cnt = max(max_customer_cnt, info[i].second);
    }

    vector<long long> dp(C + max_customer_cnt + 1, MAX_INT);
    dp[0] = 0;
    // 초과되는 경우에 대한 예외처리가 필요
    long long min_result = MAX_INT;
    for (int c = 1; c < dp.size(); c++) {
        for (auto i : info) {
            if (c - i.second < 0) continue;

            dp[c] = min(dp[c], dp[c - i.second] + i.first);
        }
        if (c >= C)
            min_result = min(min_result, dp[c]);
    }

    cout << min_result << '\n';
}