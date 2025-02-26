#include <iostream>
#include <vector>

using namespace std;

vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int n; cin >> n;
		string inp; cin >> inp;

		bool re = false;
		bool bre = false;

		if (inp != "[]") {
			inp = inp.substr(1, inp.size() - 2);

			n--;
			size_t stt = 0;
			while (n--) {
				size_t pos = inp.find(',', stt);
				v.push_back(inp.substr(stt, pos - stt));
				stt = pos + 1;
			}
			v.push_back(inp.substr(stt));
		}

		int start = 0;
		int end = v.size() - 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R') re = !re;
			else {
				if (start > end) {
					bre = true;
					break;
				}
				else {
					if (re) end--;
					else start++;
				}
			}
		}

		if (bre) {
			cout << "error\n";
		}
		else {
			cout << "[";
			if (re) {
				for (int i = end; i > start; i--) {
					cout << v[i] << ",";
				}
				if (start <= end) cout << v[start];
			}
			else {
				for (int i = start; i < end; i++) {
					cout << v[i] << ",";
				}
				if (start <= end) cout << v[end];
			}
			cout << "]\n";
		}
		v.clear();
	}
}