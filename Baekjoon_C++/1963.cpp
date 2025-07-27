#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int T;
int a, b;

bool prime[100001]; // 소수인지 판별
int visit[10001]; // 방문 횟수

void Eratos() {
	for (int i = 2; i <= 10000; i++)
		prime[i] = true;
	for (int i = 2; i <= 10000; i++) {
		for (int j = i; i * j <= 10000; j++) {
			prime[i * j] = false;
		}
	}
}

void BFS(int x, int y) {
	queue<int> q;
	visit[x] = 1;
	q.push(x);
	int tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (tmp == y) {
			cout << visit[tmp] - 1 << "\n";
			return;
		}
		for (int i = 0; i < 4; i++) { // 자리수
			for (int j = 0; j < 10; j++) { // 0 ~ 9
				if (i == 0 && j == 0) continue;
				string str = to_string(tmp);
				str[i] = j + '0';
				int tmp2 = stoi(str);
				if (visit[tmp2] || tmp2 < 1000 || !prime[tmp2]) continue; // 방문한 적이 없는 경우, 4자리가 아닌 경우, 소수가 아닌 경우 pass
				visit[tmp2] = visit[tmp] + 1;
				q.push(tmp2);
			}
		}
	}
	cout << "Impossible" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	Eratos();
	while (T--) {
		cin >> a >> b;
		memset(visit, 0, sizeof(visit));
		BFS(a, b);
	}
}