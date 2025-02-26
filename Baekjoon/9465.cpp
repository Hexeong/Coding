#include <iostream>

using namespace std;

int dp[2][100001];

int T, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> dp[i][j];
			}
		}

		dp[0][2] += dp[1][1];
		dp[1][2] += dp[0][1];

		int tmp = 0;
		for (int j = 3; j <= n; j++) {
			for (int i = 0; i < 2; i++) {
				if (tmp == 0) tmp = 1;
				else tmp = 0;

				if (dp[tmp][j - 1] > dp[tmp][j - 2]) {
					dp[i][j] += dp[tmp][j - 1];
				}
				else {
					dp[i][j] += dp[tmp][j - 2];
				}
			}
		}

		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}