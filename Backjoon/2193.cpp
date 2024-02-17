#include <iostream>
#include <algorithm>

using namespace std;

long long dp[91];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		// 자리가 늘어날 때 뒤에 오는 경우는 0 또는 1,
		// 1이 오면 그 전은 강제적으로 0이 와야 되므로 dp[i - 2]개 만큼
		// 0이 오면 상관 없으니 dp[i - 1] 개 만큼 있음
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N] << "\n";
}