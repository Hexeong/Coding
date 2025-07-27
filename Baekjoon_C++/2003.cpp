#include <iostream>

using namespace std;

int N, M, score;
int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int i{ 0 }, j{ 0 }, total{ 0 };
	while (i < N) {
		if (total >= M || j >= N) {
			if (total == M) score++;
			total = 0;
			i++;
			j = i;
		}
		else {
			total += arr[j];
			j++;
		}
	}

	cout << score << "\n";
}