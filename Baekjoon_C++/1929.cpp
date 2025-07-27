#include <iostream>

using namespace std;

int M, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	bool check;
	for (int i = M; i <= N; i++) {
		if (i <= 1)continue;
		check = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				check = false;
				break;
			}
		}
		if (check) cout << i << "\n";
	}
}