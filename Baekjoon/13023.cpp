#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, re;
vector<int> v[2000];
vector<int> c; // 체킹 한 것들 담기

void DFS(int start, int layer) {
	if (layer == 4) {
		re = 1; return;
	}
	for (auto& e : v[start]) {
		if (re == 1) return;
		if (find(c.begin(), c.end(), e) == c.end()) { // 없으면
			c.push_back(e);
			DFS(e, layer + 1);
			c.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		if (re == 1) break;
		c.push_back(i);
		DFS(i, 0);
		c.pop_back();
	}

	cout << re << "\n";
}