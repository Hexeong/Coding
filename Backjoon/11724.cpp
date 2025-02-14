#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cnt;

vector<int> v[1001];
bool visit[1001];

void DFS(int start) {
	visit[start] = true;
	for (auto e : v[start]) {
		if (!visit[e]) {
			visit[e] = true;
			DFS(e);
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

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			DFS(i);
			cnt++;
		}
	}

	cout << cnt << "\n";
}