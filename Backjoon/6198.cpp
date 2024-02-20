#include <iostream>
#include <stack>

using namespace std;

int N; // N�� 1���� �� C++ ���� 1�ʰɸ�
long long res = 0; // res�� �ִ� ���� 79999 + 79998 + ... + 1 = 32�� �����̹Ƿ� int�� ������ �Ѿ
// int�� ���� : 21�� ����

stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int h; cin >> h;

		if (s.empty()) s.push(h);
		else {
			while (1) {
				if (s.empty()) {
					s.push(h);
					break;
				}
				else if (s.top() > h) {
					res += s.size();
					s.push(h);
					break;
				}
				else {
					s.pop();
				}
			}
		}
	}

	cout << res;

	return 0;
}