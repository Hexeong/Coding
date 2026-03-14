#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	vector<int> arr(n);
	vector<int> dp(k + 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;	// 아무 동전도 선택하지 않은 경우
	for (int i = 0; i < n; i++) { //각 동전에 대해
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k] << "\n";
	return 0;
}