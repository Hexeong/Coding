//
// Created by hex on 25. 11. 11..
//
#include <iostream>

using namespace std;

long long dp[101][10][1024];

long long MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;

    for (int i = 1; i < 10; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int mask = 0; mask < (1 << 10); mask++) {
                if (dp[i][j][mask] == 0) continue;

                if (j > 0) {
                    dp[i + 1][j - 1][mask | (1 << (j - 1))] =
                        (dp[i + 1][j - 1][mask | (1 << (j - 1))] + dp[i][j][mask]) % MOD;
                }
                if (j + 1 < 10) {
                    dp[i + 1][j + 1][mask | (1 << (j + 1))] =
                        (dp[i + 1][j + 1][mask | (1 << (j + 1))] + dp[i][j][mask]) % MOD;
                }
            }
        }
    }

    long long answer = 0;
    // 모든 숫자를 사용한 마스크 (0b1111111111 = 1023)
    int final_mask = 1023;

    for (int j = 0; j <= 9; j++) {
        answer = (answer + dp[N][j][final_mask]) % MOD;
    }

    cout << answer << '\n';
}