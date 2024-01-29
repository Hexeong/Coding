#include <iostream>

using namespace std;

int T, M, N, K, cnt;

bool arr[50][50];

int xm[4] = { 1, 0, 0, -1 };
int ym[4] = { 0, 1, -1, 0 };

void DFS(int y, int x) {
	arr[y][x] = false;

	for (int i = 0; i < 4; i++) {
		if (y + ym[i] < 0 || y + ym[i] >= N) continue;
		if (x + xm[i] < 0 || x + xm[i] >= M) continue;

		if (arr[y + ym[i]][x + xm[i]]) {
			DFS(y + ym[i], x + xm[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	int x, y;
	while (T--) {
		cin >> M >> N >> K;

		cnt = 0;

		while (K--) {
			cin >> x >> y;
			arr[y][x] = true;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!arr[i][j]) continue;

				DFS(i, j);
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
}