#include <iostream>
#include <algorithm>

using namespace std;

int n, m, cnt, area;

bool arr[500][500];

int xm[4] = { 1, 0, 0, -1 };
int ym[4] = { 0, 1, -1, 0 };

void DFS(int y, int x) {
	arr[y][x] = false;

	for (int i = 0; i < 4; i++) {
		if (y + ym[i] < 0 || y + ym[i] >= n) continue;
		if (x + xm[i] < 0 || x + xm[i] >= m) continue;

		if (arr[y + ym[i]][x + xm[i]]) {
			area++;
			DFS(y + ym[i], x + xm[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j]) continue;

			area = 1;

			DFS(i, j);
			cnt++;
			mx = max(area, mx);
		}
	}

	cout << cnt << "\n" << mx << "\n";
}