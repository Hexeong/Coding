#include <iostream>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B, C, D;
	long long cnt1{ 1 }, cnt2{ 1 };
	bool c1{ true }, c2{ true };

	cin >> A >> B >> C >> D;
	while (c1) {
		if (cnt1 > B && c1) {
			B += cnt1 * A;
			c1 = false;
		}
		else cnt1 *= 10;
	}
	while (c2) {
		if (cnt2 > D && c2) {
			D += cnt2 * C;
			c2 = false;
		}
		else cnt2 *= 10;
	}
	cout << B + D << endl;
}