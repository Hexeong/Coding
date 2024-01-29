#include <iostream>

using namespace std;

int n, k;

int arr[101];
int dp[10001]; // index : 동전의 가치 합, 값은 동전의 개수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	int m = 100001;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] == k) {
			cout << 1 << "\n";
			return 0;
		}
		m = min(m, arr[i]);
	}

	if (m == 100001) {
		cout << -1 << "\n";
		return 0;
	}

	int tmp;
	for (int i = m; i <= k; i++) {
		// dp[k] = arr[i] + dp[k - arr[i]] // arr[i]만큼 하면 dp[k - arr[i]]만큼을 최소로 받아야 됨

		for (int j = 1; j <= n; j++) {
			if (i - arr[j] == 0) {
				dp[i] = 1; break;
			}
			if (i - arr[j] < 0 || dp[i - arr[j]] == 0) continue;

			tmp = 1 + dp[i - arr[j]];
			
			if (dp[i] == 0) dp[i] = tmp;
			else dp[i] = min(dp[i], tmp);
		}
	}


	cout << (dp[k] == 0 ? -1 : dp[k]) << "\n";
}

// dp[2] = 2; dp[3] = 3; dp[4] = 4; dp[5] = 5 -> 1; dp[6] = 2; dp[10] = 2;