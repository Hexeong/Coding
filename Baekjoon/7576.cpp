#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int M, N, m, cnt, day;
int b[1001][1001];
queue<tuple<int, int, int>> q;

int y[] = { 0,1,0,-1 };
int x[] = { 1,0,-1,0 };

void BFS() {
	while (!q.empty()) {
		tuple<int, int, int> tmp = q.front();
		q.pop();
		cnt++;
		day = max(day, get<2>(tmp));

		for (int i = 0; i < 4; i++) {
			if (get<0>(tmp) + y[i] < 1 || get<0>(tmp) + y[i] > N) continue;
			if (get<1>(tmp) + x[i] < 1 || get<1>(tmp) + x[i] > M) continue;
			if (b[get<0>(tmp) + y[i]][get<1>(tmp) + x[i]] == 0) {
				b[get<0>(tmp) + y[i]][get<1>(tmp) + x[i]] = 1;
				q.push(make_tuple(get<0>(tmp) + y[i], get<1>(tmp) + x[i], get<2>(tmp) + 1));
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
		cin >> b[i][j];
		if (b[i][j] == -1) m++;
		if (b[i][j] == 1) q.push(make_tuple(i, j, 0));
	}

	BFS();

	cout << (M * N - m == cnt ? day : -1) << "\n";
}



//int M, N, mx, cnt, ncnt;
//
//class Node {
//public:
//	int y;
//	int x;
//	int c;
//	Node(int y, int x, int c) {
//		this->y = y;
//		this->x = x;
//		this->c = c;
//	}
//};
//
//int arr[1000][1000];
//queue<Node> q;
//
//int xm[4] = { 1,0,0,-1 };
//int ym[4] = { 0,1,-1,0 };
//
//void BFS() {
//	while (!q.empty()) {
//		Node tmp = q.front();
//		mx = max(mx, tmp.c);
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			if (tmp.x + xm[i] < 0 || tmp.x + xm[i] >= M) continue;
//			if (tmp.y + ym[i] < 0 || tmp.y + ym[i] >= N) continue;
//
//			if (arr[tmp.y + ym[i]][tmp.x + xm[i]] == 0) {
//				arr[tmp.y + ym[i]][tmp.x + xm[i]] = 1;
//				cnt++;
//				q.push(Node(tmp.y + ym[i], tmp.x + xm[i], tmp.c + 1));
//			}
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> M >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> arr[i][j];
//			if (arr[i][j] == 1) {
//				q.push(Node(i, j, 0));
//				cnt++;
//			}
//			else if (arr[i][j] == -1) {
//				ncnt++;
//			}
//		}
//	}
//
//	BFS();
//
//	if (cnt == M * N - ncnt) cout << mx << "\n";
//	else cout << -1 << "\n";
//}