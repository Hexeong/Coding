#include <iostream>

using namespace std;

int arr[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	arr[1] = 1; arr[2] = 2; arr[3] = 4;
	for (int i = 4; i <= 12; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	while (T--) {
		int n; cin >> n;

		cout << arr[n] << "\n";
	}


	return 0;
}