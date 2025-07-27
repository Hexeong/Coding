#include <iostream>
#include <cmath>

using namespace std;

int T;

bool prime(int x) {
	int r;
	r = sqrt(x);
	if (r == 1 && x != 1) return true;
	if (x % 2) {
		for (int j = 2; j <= r; j++) {
			if (!(x % j)) return false;
			if (j == r) return true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	int n;
	while (T--) {
		cin >> n;

		for (int i = n / 2; i >= 2; i--) {
			if (prime(i) && prime(n - i)) {
				cout << i << " " << n - i << "\n";
				break;
			}
		}
	}
}