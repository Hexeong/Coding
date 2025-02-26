#include <iostream>
#include <queue>

using namespace std;

int K, W, H;

int M[200][200];

bool visit[200][200][31];

int x[4] = { 0, 0, 1, -1 };
int y[4] = { 1, -1, 0, 0 };

int hx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

struct Entry {
	int x;
	int y;
	int move;
	int ability;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> M[i][j];
		}
	}

	queue<Entry> q;
	Entry first;
	first.x = 0; first.y = 0; first.move = 0; first.ability = 0;
	q.push(first);
	visit[0][0][0] = true;

	while (!q.empty()) {
		Entry tmp = q.front();
		q.pop();

		if (tmp.x == H - 1 && tmp.y == W - 1) {
			cout << tmp.move << "\n";
			return 0;
		}
		if (tmp.ability < K) {
			for (int i = 0; i < 8; i++) {
				int mx = tmp.x + hx[i];
				int my = tmp.y + hy[i];

				if(mx >= 0 && my >= 0 && mx < H && my < W)
					if (M[mx][my] == 0 && visit[mx][my][tmp.ability + 1] == false) {
						visit[mx][my][tmp.ability + 1] = true;
						
						Entry p;
						p.x = mx; p.y = my; p.move = tmp.move + 1; p.ability = tmp.ability + 1;
						q.push(p);
					}
			}
		}
		for (int i = 0; i < 4; i++) {
			int mx = tmp.x + x[i];
			int my = tmp.y + y[i];

			if (mx >= 0 && my >= 0 && mx < H && my < W)
				if (M[mx][my] == 0 && visit[mx][my][tmp.ability] == false) {
					visit[mx][my][tmp.ability] = true;

					Entry p;
					p.x = mx; p.y = my; p.move = tmp.move + 1; p.ability = tmp.ability;
					q.push(p);
				}
		}

	}
	cout << -1 << "\n";
}