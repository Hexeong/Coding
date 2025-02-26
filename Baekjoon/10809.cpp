#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	for (char i = 'a'; i <= 'z'; i++) {
		auto it = find(&s[0], &s[s.size()], i);
		if (it != &s[s.size()]) cout << it - &s[0] << " ";
		else cout << -1 << " ";
	}
	cout << "\n";
}