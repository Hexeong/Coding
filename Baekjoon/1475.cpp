#include <iostream>
#include <algorithm>

using namespace std;

int result;

int s[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string v;
	cin >> v;

	for (int i = 0; i < v.size(); i++) s[v[i] - '0']++;

	int mI = 0;
	for (int i = 1; i < 10; i++) {
		if (s[i] > s[mI] && i != 6 && i != 9) mI = i;
	}

	int si = ((s[6] + s[9]) % 2 == 0 ? ((s[6] + s[9]) / 2) : ((s[6] + s[9]) / 2) + 1);
	result = max(s[mI], si);

	cout << result << "\n";
}