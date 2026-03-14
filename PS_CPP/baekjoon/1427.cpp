#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j) { return i > j; };

int main() {
	string s;
	cin >> s;
	vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i] - 48);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << endl;
}