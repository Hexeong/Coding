#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T; string temp;
vector<char> s1;
vector<char> s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		s1.clear();
		s2.clear();
		cin >> temp;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == '-') {
				if (s1.size() > 0) {
					s1.pop_back();
				}
			}
			else if (temp[i] == '<') {
				if (s1.size() > 0) {
					char tp = s1.back();
					s1.pop_back();
					s2.push_back(tp);
				}
			}
			else if (temp[i] == '>') {
				if (s2.size() > 0) {
					char tp = s2.back();
					s2.pop_back();
					s1.push_back(tp);
				}
			}
			else {
				s1.push_back(temp[i]);
			}
		}

		for (int i = 0; i < s1.size(); i++) cout << s1[i];
		for (int i = s2.size() - 1; i > -1; i--) cout << s2[i];
		cout << "\n";
	}

	return 0;
}