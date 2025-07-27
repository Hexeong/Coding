#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, k;
	while (cin >> n >> k) {
		long long coupon = 0;
		long long ans = n;
		long long stamp = n;
		coupon += stamp / k;
		while (stamp >= k) {
			stamp %= k;
			ans += coupon;
			stamp += coupon;
			coupon = 0;
			coupon += stamp / k;
		}

		cout << ans << "\n";
	}
}