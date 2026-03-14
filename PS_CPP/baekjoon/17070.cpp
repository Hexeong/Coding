//
// Created by hex on 25. 10. 13..
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> map(N, vector<int>(N));
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(3, 0)));
    // 0 : 오른쪽, 1 : 대각선, 2 : 아래

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    // dp 초기 조건 설정
    // 오른쪽 방향만 했을 때
    for (int i = 1; i < N; i++) {
        if (map[0][i] != 1)
            dp[0][i][0] = 1;
        else
            break;
    }

    // 아래 방향만 했을 때
    if (map[0][2] != 1 && map[1][2] != 1 && map[1][1] != 1) {
        dp[1][2][1] = 1;
        // 해당 대각선이 가능할 때만 아래의 초기조건 설정이 가능하다.
        for (int i = 2; i < N; i++) {
            if (map[i][2] != 1)
                dp[i][2][2] = 1;
            else
                break;
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 3; j < N; j++) {
            if (map[i][j] == 1)
                continue;

            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
            if (map[i - 1][j] != 1 && map[i][j - 1] != 1)
                dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
        }
    }

    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2] << '\n';
}