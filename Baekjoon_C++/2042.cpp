//
// Created by hex on 25. 10. 23..
//
#include <iostream>

using namespace std;

using PLL = pair<long long, long long>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;
    vector<long long> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<long long> prefix(N); // first = prefix, second = suffix
    long long cur_prefix = 0;
    for (int i = 0; i < N; i++) {
        prefix[i] = cur_prefix;
        cur_prefix += nums[i];
    }

    vector<long long> change(N, NULL);
    vector<int> idx;
    for (int i = 0; i < M + K; i++) {
        long long a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            // b를 c로 변경, 변경된 숫자에 맞춰 양 옆의 prefix, suffix 정보를 수정

            if (change[b - 1] == NULL) idx.push_back(b);
            change[b - 1] = c - nums[b - 1];
        } else {
            // b부터 c까지 합을 출력
            long long result = prefix[c - 1] - prefix[b - 1] + nums[c - 1];
            for (const auto& id : idx) {
                if (id < b || id > c) continue;
                result += change[id - 1];
            }
            cout << result << '\n';
        }
    }
}