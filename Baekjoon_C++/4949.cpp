#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<char> v;

	string s;
	while (true) {
		getline(cin, s);
		if (s == ".") break;
		int i;
		for (i = 0; i < s.size(); i++) {
			if (s[i] == '[') {
				v.push_back('[');
			}
			else if (s[i] == '(') {
				v.push_back('(');
			}
			else if (s[i] == ']') {
				if (!v.empty() && v.back() == '[') v.pop_back();
				else break;
			}
			else if (s[i] == ')') {
				if (!v.empty() && v.back() == '(') v.pop_back();
				else break;
			}
		}
		if (i == s.size() && v.empty()) cout << "yes\n";
		else cout << "no\n";
		v.clear();
	}
}