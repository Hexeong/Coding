#include <iostream>
#include <utility>

using namespace std;

pair<int, int> dp[41];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	dp[0] = make_pair(1, 0); dp[1] = make_pair(0, 1);

	for (int i = 2; i < 41; i++) {
		dp[i] = make_pair(dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second);
	}

	int N;
	while (T--) {
		cin >> N;
		cout << dp[N].first << " " << dp[N].second << "\n";
	}
}