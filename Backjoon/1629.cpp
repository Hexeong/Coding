#include <iostream>

using namespace std;

// N이 1억일 때 O(n)이 1초

long long a, b, c;

long long fpow(long long C, long long n) {
	if (n == 0) {
		return 1;
	}
	else {
		long long x = fpow(C, n / 2);
		x = x * x % c;
		if (n % 2 == 0) {
			return x;
		}
		else {
			return x * C % c;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	cout << fpow(a, b);

	return 0;
}

// C * C * C * C == (C * B + a)(C * B + a) == C * C * B * B + 2 * CBa + a*a 