#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		if (s[s.size() - 1] % 2 == 1) cout << "odd\n";
		else cout << "even\n";
	}
}