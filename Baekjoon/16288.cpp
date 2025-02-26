#include <iostream>
#include <queue>

using namespace std;

int N, k;
queue<int> p[101];
int arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	bool check;
	for (int i = 0; i < N; i++) {
		check = true;
		for (int j = 1; j <= k; j++) {
			if (p[j].empty() || arr[i] > p[j].back()) {
				p[j].push(arr[i]);
				check = false;
				break;
			} // 창구가 비어 있거나 창구에 1명 이상 있을 때
		}
		if (check) {// 창구에 넣지 못했을 때
			cout << "NO\n"; return 0;
		}
	}
	cout << "YES\n";
}