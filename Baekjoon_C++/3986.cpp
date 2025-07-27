#include <iostream>
#include <stack>

using namespace std;

int T, res;
string arr[100];
stack<char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> arr[i];

		if (arr[i].size() % 2 != 0) continue;

		bool judge = false;
		for (int j = 0; j < arr[i].size(); j++) {
			if (s.empty()) s.push(arr[i][j]);
			else {
				if (s.top() == arr[i][j]) s.pop();
				else if (s.size() == arr[i].size() - j) {
					if (s.top() == arr[i][j]) s.pop();
					else judge = true;
				}
				else s.push(arr[i][j]);
			}
			if (judge) break;
		}
		while (!s.empty()) s.pop(); // s.clear();
		if (!judge) res++;
	}

	cout << res;

	return 0;
}