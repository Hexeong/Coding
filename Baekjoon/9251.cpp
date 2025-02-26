#include <iostream>

using namespace std;

int len[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string x, y;
	cin >> x >> y;
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			if (x[i] == y[j]) len[i + 1][j + 1] = len[i][j] + 1;
			else len[i + 1][j + 1] = max(len[i + 1][j], len[i][j + 1]);
		}
	}
	cout << len[x.size()][y.size()];
}