#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> v(10001);
bool visit[10001];

int N, M;

void BFS(int root) {
	queue<pair<int, int>> q;
	q.push(make_pair(root, 0));
	visit[root] = true;


	bool empty_check = true;
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();

		empty_check = true;
		for (auto e : v[tmp.first]) {
			if (!visit[e.first]) {
				e.second += tmp.second;
				visit[e.first] = true;
				q.push(e);
				empty_check = false;
			}
		}
		if (empty_check) M = max(M, tmp.second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int a, b, weight;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> weight;
		v[a].push_back(make_pair(b, weight));
		v[b].push_back(make_pair(a, weight));
	}

	for (int i = 1; i <= N; i++) {
		BFS(i);
		for (int i = 1; i <= 10000; i++) visit[i] = false;
	}

	cout << M << "\n";
}