#include <iostream>
#include <cmath>

using namespace std;

long long N, r, c, res = 0;
//bool re = false;
// 분할 느낌 N n/2 n/4

//void z(int h, int v, int n) {
//	if (!re && n != 1) {
//		z(h, v, n / 2);
//		z(h + n / 2, v, n / 2);
//		z(h, v + n / 2, n / 2);
//		z(h + n / 2, v + n / 2, n / 2);
//	} 
//	else if (h == c && v == r) {
//		re = true;
//	}
//	else if (n == 1) {
//		res++;
//	}
//	return;
//} 되긴 하지만 Worst가 전수탐색이므로 2**15 == 10억이므로 0.5초 내에 못함

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> r >> c;

	// z(0, 0, pow(2, N));
	while (N != 0) {
		N--;

		if (r < pow(2, N) && c < pow(2, N)) {
			//res += pow(2, N) * pow(2, N) * 0;
		}
		else if (r < pow(2, N) && c >= pow(2, N)) {
			res += pow(2, N) * pow(2, N) * 1;
			c -= pow(2, N);
		}
		else if (r >= pow(2, N) && c < pow(2, N)) {
			res += pow(2, N) * pow(2, N) * 2;
			r -= pow(2, N);
		}
		//else if (r >= pow(2, N) && c >= pow(2, N)) {
		else {
			res += pow(2, N) * pow(2, N) * 3;
			c -= pow(2, N);
			r -= pow(2, N);
		}
	}

	cout << res;

	return 0;
}