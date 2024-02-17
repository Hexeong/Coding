#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, p, l, cnt;
int arr[100];
vector<int> re;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> p >> l;

		for (int i = 0; i < p; i++) cin >> arr[i];
		sort(arr, arr + p);
		if (p >= l) re.push_back(arr[p - l]);
		else { // ���� ��û �ο��� �� ���� ���� ���
			if (m > 0) {
				m--;
				cnt++;
			}
			else {
				cout << cnt << "\n";
				return 0;
			}
		}
	}
	if (cnt != n) { // ��� ������ ������û �ο��� �� ���� �ʾ��� ��쿡 ���� ���� ó��
		sort(re.begin(), re.end());

		for (int i = 0; i < re.size(); i++) {
			if (re[i] <= m) {
				cnt++;
				m -= re[i];
			}
			else break;
		}
	}

	cout << cnt << "\n";
}