#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int A[100000];

void Binary(int start, int end, int goal) {
	if (start > end) {
		cout << 0 << "\n";
		return;
	}

	int index = (start + end) / 2;
	if (A[index] > goal) {
		Binary(start, index - 1, goal);
	}
	else if (A[index] < goal) {
		Binary(index + 1, end, goal);
	}
	else {
		cout << 1 << "\n";
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	sort(A, A + N);

	int tmp; cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		Binary(0, N - 1, tmp);
	}
}