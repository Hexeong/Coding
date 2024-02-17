#include <iostream>
#include <algorithm>

using namespace std;

long long K, N;

long long k[10001];

long long goal = 0;

void Binary(long long start, long long end) {
	if (start > end) return; // 이진 탐색 종료 조건

	long long index = (start + end) / 2;
	long long score = 0;
	for (int i = 0; i < K; i++) {
		score += (k[i] / index);
	}

	if (score >= N) {
		goal = max(goal, index);
		Binary(index + 1, end);
	}
	else {
		Binary(start, index - 1);
	}
}

int main() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) cin >> k[i];

	sort(k, k + K);

	Binary(1, k[K - 1]);

	cout << goal << "\n";
}