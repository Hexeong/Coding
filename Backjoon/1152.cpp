#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);

	long long cnt = 0;

	while (1) {
		if (s[0] == ' ') s.erase(0, 1);
		else break;
	}

	while (1) {
		if (s[s.size() - 1] == ' ') s.erase(s.size() - 1, 1);
		else break;
	}

	for (long long i = 0; i < s.size(); i++) {
		if (s[i] == ' ') cnt++;
	}

	if (s.size() == 0) cout << cnt << "\n";
	else cout << cnt + 1 << "\n";

	return 0;
}