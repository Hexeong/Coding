#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, H, W, T;
// 1 ≤ N ≤ 4
// 2 ≤ W ≤ 12
// 2 ≤ H ≤ 15

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int max_v = 0;

int shoot(int j, vector<vector<pair<int, bool>>>& space) {
	int i = 0;
	while (i < H && !space[j][i].second)
		i++;

	return i;
}

int BFS(int i, int j, vector<vector<pair<int, bool>>>& space) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ i, j });
	space[j][i].second = false;
	cnt++;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < space[p.second][p.first].first; j++) {
				int ny = p.first + dy[i] * j;
				int nx = p.second + dx[i] * j;

				if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;

				if (space[nx][ny].second) {
					q.push({ ny, nx });
					space[nx][ny].second = false;
					cnt++;
				}
			}
		}
	}

	return cnt;
}


void process(int depth, int broken_bricks_cnt, vector<vector<pair<int, bool>>>& bricks) {
	if (depth == N) {
		max_v = max(max_v, broken_bricks_cnt);
		return;
	}

	vector<vector<pair<int, bool>>> space(12);
	for (int j = 0; j < W; j++) {
		// space 복제
		for (int w = 0; w < W; w++) {
			space[w].clear();
			for (int i = 0; i < H; i++) {
				space[w].push_back(bricks[w][i]);
			}
		}

		int brick_i = shoot(j, space);
		int cur_sum = broken_bricks_cnt;
		if (brick_i != H) {
			// 터지는 것들 마킹 및 counting by BFS
			cur_sum += BFS(brick_i, j, space);

			// 터지는 것들 제거
			for (int w = 0; w < W; w++) {
				int c = 0;
				for (int i = H - 1; i > -1; i--) {
					if (!space[w][i].second) {
						space[w].erase(space[w].begin() + i);
						c++;
					}
				}
				while (c--)
					space[w].insert(space[w].begin(), { 0, false }); // 제거한 만큼 추가해주기
			}
		}
		// 재귀 호출
		process(depth + 1, cur_sum, space);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("input.txt", "r", stdin);
	cin >> T;

	vector<vector<pair<int, bool>>> space(12); // i는 가로, j가 세로, int는 블록의 값, bool은 터졌는지 여부
	for (int t = 1; t <= T; t++) {
		max_v = 0;
		int all_brick_cnt = 0;
		for (int i = 0; i < 12; i++)
			space[i].clear();
		cin >> N >> W >> H;
		// N개의 별돌을 떨어뜨려, 즉 N번의 구슬을 쏘아 최대한 많은 벽돌을 제거하려고 한다.
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				int a; cin >> a;
				if (a == 0)
					space[j].push_back({ 0, false });
				else {
					space[j].push_back({ a, true });
					all_brick_cnt++;
				}
			}
		}

		process(0, 0, space);

		cout << '#' << t << " " << all_brick_cnt - max_v << "\n";
	}
}