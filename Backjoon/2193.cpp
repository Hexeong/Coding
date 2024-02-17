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
		// �ڸ��� �þ �� �ڿ� ���� ���� 0 �Ǵ� 1,
		// 1�� ���� �� ���� ���������� 0�� �;� �ǹǷ� dp[i - 2]�� ��ŭ
		// 0�� ���� ��� ������ dp[i - 1] �� ��ŭ ����
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N] << "\n";
}