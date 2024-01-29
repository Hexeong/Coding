#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;

	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		if (s == "push") {
			int x; cin >> x;
			v.push_back(x);
		}
		else if (s == "pop") {
			if (!v.empty()) {
				cout << v.front() << "\n";
				v.erase(v.begin());
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (s == "size") {
			cout << v.size() << "\n";
		}
		else if (s == "empty") {
			cout << (v.empty()? 1 : 0) << "\n";
		}
		else if (s == "front") {
			cout << (!v.empty() ? v.front() : -1) << "\n";
		}
		else if (s == "back") {
			cout << (!v.empty() ? v.back() : -1) << "\n";
		}
	}
}