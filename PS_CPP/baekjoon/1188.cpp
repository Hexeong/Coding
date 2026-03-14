#include <iostream>

using namespace std;

int rec(int N, int M) {
	if (M > N) {
		if (M % N == 0) {
			return (M / N - 1) * N;
		}
		else {
			return (M / N) * N + rec(N, M % N);
		}
	}
	else {
		if (N % M == 0) {
			return 0;
		}
		else {
			return rec(N % M, M);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	cout << rec(N, M) << "\n";
}