#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}

	int m{ dp[1] }, tmp;
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i] + dp[i - 1], dp[i]);
		m = max(m, dp[i]);
	}
	// dp[i] + dp[i - 1]과 dp[i]를 비교

	cout << m << "\n";
}

// 8

// 0 8 -9 3 5 6 2 -8, DP[2] = 11, DP[3] = 14, DP[4]

//int dp[100001];
//int arr[100001];
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n; cin >> n;
//
//	dp[1] = dp[2] = -1001;
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//		dp[1] = max(dp[1], arr[i]);
//	}
//
//	int idx, length{ 2 };
//	for (int i = 1; i <= n - 1; i++) {
//		if (arr[i] + arr[i + 1] > dp[2]) {
//			dp[2] = arr[i] + arr[i + 1];
//			idx = i;
//		}
//	}
//
//	int t1, t2;
//	for (int i = 3; i <= n; i++) {
//		t1 = t2 = -1001;
//		if (idx - 1 != 0) {
//			t1 = dp[i - 1] + arr[idx - 1];
//		}
//		if (idx + length <= n) {
//			t2 = dp[i - 1] + arr[idx + length];
//		}
//		
//		if (t1 > t2) {
//			dp[i] = t1;
//			idx--; length++;
//		}
//		else {
//			dp[i] = t2;
//			length++;
//		}
//	}
//
//	int m = -1001;
//	for (int i = 1; i <= n; i++) {
//		m = max(m, dp[i]);
//	}
//
//	cout << m << "\n";
//}