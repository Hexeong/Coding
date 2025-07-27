#include <iostream>

using namespace std;

int N;
bool star[6562][6562];

void re(int n, int s, int e) {
	if (n == 1) {
		return;
	}
	else {
		// 嶺 還
		for (int i = 0; i < 3; i++) {
			re(n / 3, s, e + n / 3 * i);
		}
		// 陛遴等 還
		re(n / 3, s + n / 3 * 1, e);
		for (int i = s + n / 3 * 1; i < s + n / 3 * 2; i++)
			for (int j = e + n / 3 * 1; j < e + n / 3 * 2; j++) star[i][j] = true;
		re(n / 3, s + n / 3 * 1, e + n / 3 * 2);
		// 嬴概 還
		for (int i = 0; i < 3; i++) {
			re(n / 3, s + n / 3 * 2, e + n / 3 * i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	re(N, 1, 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << (star[i][j] ? ' ' : '*');
		}
		cout << "\n";
	}

	return 0;
}