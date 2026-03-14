#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	cin.ignore(); // 입력 이후 버퍼에 \n이 남아있음
	while (T--) {

		string s;
		getline(cin, s); // getline은 개행문자를 보고 폐기하는데 남아있는 개행문자로 인해 한번 건너뛰게 됨.
		vector<string> v;
		istringstream ss(s);
		string tmp;
		while (getline(ss, tmp, ' ')) {
			v.push_back(tmp);
		}

		for (int i = 0; i < v.size(); i++) {
			reverse(v[i].begin(), v[i].end());
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
}

//string s;
//cin >> s;
//vector<string> v(s.size());
//
//int start = 0;
//for (int i = 0; i < s.size(); i++) {
//	if (s[i] == ' ') {
//		start++;
//	}
//	else {
//		v[start].append(str(s[i]));
//	}
//}