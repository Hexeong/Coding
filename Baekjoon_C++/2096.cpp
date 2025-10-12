//
// Created by admin on 2025-10-12.
//
#include <iostream>

using namespace std;

int input[100000][3];
int dp_max[2][3];
int dp_min[2][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    // 100,000 * 4 * 3 -> 1,200,000 = 1.2MB

    for (int i = 0; i < N; i++) {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }

    dp_max[0][0] = dp_min[0][0] = input[0][0];
    dp_max[0][1] = dp_min[0][1] = input[0][1];
    dp_max[0][2] = dp_min[0][2] = input[0][2];

    for (int i = 1; i < N; i++) {
        dp_max[1][0] = input[i][0] + max(dp_max[0][0], dp_max[0][1]);
        dp_max[1][1] = input[i][1] + max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]);
        dp_max[1][2] = input[i][2] + max(dp_max[0][1], dp_max[0][2]);

        dp_min[1][0] = input[i][0] + min(dp_min[0][0], dp_min[0][1]);
        dp_min[1][1] = input[i][1] + min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]);
        dp_min[1][2] = input[i][2] + min(dp_min[0][1], dp_min[0][2]);

        for (int j = 0; j < 3; j++) {
            dp_max[0][j] = dp_max[1][j];
            dp_min[0][j] = dp_min[1][j];
        }
    }

    cout << max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]) << endl;
    cout << min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]) << endl;
}