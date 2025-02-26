#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp[500];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tmp;
			dp[i].push_back(tmp);
		}
	}

	int m = dp[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			tmp = dp[i][j];
			if (j - 1 != -1) dp[i][j] = max(dp[i][j], tmp + dp[i - 1][j - 1]);
			if (j <= i - 1) dp[i][j] = max(dp[i][j], tmp + dp[i - 1][j]);
			if (i == n - 1) m = max(m, dp[i][j]);
		}
	}

	cout << m << "\n";
}