#include <iostream>

using namespace std;

int N, M;

int arr[9];
bool check[9];


void func(int cnt, int cur) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	for (int i = cur; i <= N; i++) {
		if (!check[i]) {
			check[i] = true;
			arr[cnt] = i;
			func(cnt + 1, i);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	func(0, 1);
}