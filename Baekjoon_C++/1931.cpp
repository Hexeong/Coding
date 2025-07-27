#include <iostream>
#include <algorithm>

using namespace std;

int N, cnt;
pair<int, int> arr[100000];

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else return false;
	}
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b; arr[i] = make_pair(a, b);
	}
	sort(arr, arr + N, compare);
	// b가 제일 작은 것으로 항상 선택 하지만 a가 b보다 작은 경우 건너뛰기

	//for (int i = 0; i < N; i++) cout << arr[i].second << "\n";
	cnt++;
	int stt = arr[0].second;
	for (int i = 1; i < N; i++) {
		if (arr[i].second >= stt && arr[i].first >= stt) {
			cnt++; stt = arr[i].second;
		}
	}

	cout << cnt << "\n";
}