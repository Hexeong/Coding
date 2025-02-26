#include <iostream>

using namespace std;

int n;

long long dp[101][10];
long long arr[101][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	
	for (int i = 1; i <= 9; i++) {
		arr[1][i] = dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j <= 8 && j >= 1) dp[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
			else if (j == 0) dp[i][j] = arr[i - 1][j + 1];
			else if (j == 9) dp[i][j] = arr[i - 1][j - 1];


			dp[i][j] %= 1000000000;
			arr[i][j] = dp[i][j];
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
		sum %= 1000000000;
	}

	cout << sum  << "\n";
}

// 9와 0은 - 1 해줘야 된다
// dp[1] = 9
// dp[2] = dp[1] * 2 - 1;
// dp[3] = dp[2] * 2 - 2; 1 ~ 9 : 9개  0 ~ 9 : 2 * 9 - 1; 0 ~ 9 : 17 * 2 - 2;