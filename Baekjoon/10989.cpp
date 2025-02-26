// 2021-07-19 counting Sort 시작
// 2021-07-21 실패 누적합을 뺴고 cin cout의 시간을 줄여도 안됨
#include <iostream>

using namespace std;

int counts[10001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		counts[tmp]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < counts[i]; j++) {
			cout << i << "\n";
		}
	}
}