#include <iostream>

using namespace std;

int n;

int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i - j * j == 0) {
				dp[i] = 1;
				break;
			}
			else if (i - j * j < 0) break;
			else if (dp[i - j * j] == 0) continue;
			else if (dp[i - j * j] == 0) continue;

			tmp = 1 + dp[i - j * j];

			if (dp[i] == 0) dp[i] = tmp;
			else dp[i] = min(dp[i], tmp);
		}
	}

	cout << dp[n] << "\n";
}