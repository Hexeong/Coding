#include <iostream>
#include <algorithm>

using namespace std;

int n;

long long dp[10001];
long long arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	dp[1] = arr[1]; dp[2] = arr[1] + arr[2]; dp[3] = max(arr[1] + arr[3], max(arr[2] + arr[3], dp[2]));
	long long m = max(dp[1], max(dp[2], dp[3]));
	for (int i = 4; i <= n; i++) {
		// i번째 포도주를 마시면 dp[i - 1]과 dp[i - 2]를 arr[i]와 더한 것의 비교에서 max를 찾을 수 있다.
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], dp[i - 1]);
		for (int j = 2; j < i; j++) {
			dp[i] = max(dp[i], arr[i] + dp[i - j]);
		}
		m = max(m, dp[i]);
	}

	cout << m << endl;
}

//
//pair<int, int> Max(int a, int b, int c, int i) {
//	if (a >= b && a >= c) return make_pair(a, i - 2);
//	else if (b >= a && b >= c) return make_pair(b, i - 1);
//	else if (c >= a && c >= b) return make_pair(c, i);
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//		if (i % 3 == 0) {
//			dp[i - 2] = arr[i - 1] + arr[i];
//			dp[i - 1] = arr[i - 2] + arr[i - 1];
//			dp[i] = arr[i - 2] + arr[i];
//		}
//	}
//
//	// 1에서 시작해서 가는 경우 2에서 시작해서 가는 경우를 마지막에 비교
//	int N = n - (n % 3);
//	pair<int, int> m = Max(dp[1], dp[2], dp[3], 3);
//	for (int i = 6; i <= N; i+=3) {
//		if (m.second % 3 == 0) {
//
//		}
//		else if (m.second % 3 == 1) {
//
//		}
//		else {
//
//		}
//	}
//}