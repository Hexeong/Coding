#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t, n;
string result;
bool sw;

vector<string> v;

// ¹Ý·Ê n = 3, 1 2 31

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;

		result = "YES\n";
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s; v.push_back(s);
		}
		
		sort(v.begin(), v.end());

		for (int i = 0; i < n - 1; i++) {
			if (v[i + 1].find(v[i]) == 0) {
				result = "NO\n";
				break;
			}
		}
		
		cout << result;
		v.clear();
	}
}

