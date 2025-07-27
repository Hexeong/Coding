#include <iostream>
#include <vector>

using namespace std;

int T, N, M, stack, start, r;

bool arrN[1001];
vector<int> v[1001];

void DFS(int start) {
	if (stack == N) return;
	else {
		for (auto e : v[start]) {
			if (arrN[e] == false) {
				arrN[e] = true;
				r++;
				stack++;
				DFS(e);
			}
		}
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		int a, b;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		stack = 1;
		r = 0;
		arrN[1] = true;
		DFS(1);

		cout << r << '\n';

		for (int i = 1; i <= N; i++) {
			arrN[i] = false;
			v[i].clear();
		}
	}
}