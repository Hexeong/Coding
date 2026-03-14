#include <iostream>
#include <vector>

using namespace std;

long long r;
int n, t;
vector<int> v;

int GCD(int x, int y) {
	if (y == 0) return x;
	return GCD(y, x % y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		r = 0;
		cin >> n;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				r += GCD(v[i], v[j]);
			}
		}
		cout << r << "\n";
		v.clear();
	}
}