#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> v;

void func(int cnt, int cur) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = cur; i <= N; i++) {
		v.push_back(i);
		func(cnt + 1, i);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	func(0, 1);
}