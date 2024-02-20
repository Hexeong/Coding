#include <iostream>
#include <cmath>

using namespace std;

int N, r, c, res = 0;
bool re = false;
// ºÐÇÒ ´À³¦ N n/2 n/4
void z(int h, int v, int n) {
	if (h == c && v == r) {
		re = true;
		return;
	}
	else if (n == 1) {
		res++;
		return;
	}

	if (!re) z(h, v, n / 2);
	if (!re) z(h + n / 2, v, n / 2);
	if (!re) z(h, v + n / 2, n / 2);
	if (!re) z(h + n / 2, v + n / 2, n / 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> r >> c;

	z(0, 0, powf(2, N));

	cout << res;

	return 0;
}