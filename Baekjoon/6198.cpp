#include <iostream>
#include <stack>

using namespace std;

int N; // N이 1억일 때 C++ 에서 1초걸림
long long res = 0; // res의 최대 값이 79999 + 79998 + ... + 1 = 32억 정도이므로 int의 범위를 넘어감
// int의 범위 : 21억 정도

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