#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; cin >> N;

	int kg3{ 3 }, kg5{ 5 };

	int res = 0;

	while (N >= 0) {
		if (N % 5 == 0) {
			res += N / 5;
			cout << res << "\n";
			return 0;
		}
		N -= 3;
		res++;
	}
	cout << -1 << "\n";
}