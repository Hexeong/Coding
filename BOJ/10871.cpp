#include <iostream>

using namespace std;

int N, X;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> X;

	int* A = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		if (X > A[i]) cout << A[i] << " ";
	}
	cout << "\n";
}