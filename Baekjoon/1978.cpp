#include <iostream>

using namespace std;

int arr[100];
int cnt, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	bool check;
	for (int i = 0; i < N; i++) {
		if (arr[i] <= 1) continue;
		check = true;
		for (int j = 2; j * j <= arr[i]; j++) {
			if (arr[i] % j == 0) {
				check = false;
				break;
			}
		}
		if (check) cnt++;
	}

	cout << cnt << "\n";
}