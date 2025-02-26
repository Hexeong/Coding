#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int N, M;

bool arr[101][101];

class Node {
public:
	int x;
	int y;
	int cnt;
	Node(int y, int x, int cnt) {
		this->x = x;
		this->y = y;
		this->cnt = cnt;
	}
};

void BFS(int x, int y) {
	queue<Node> q;
	q.push(Node(y, x, 1));
	arr[1][1] = false;

	while (!q.empty()) {
		Node tmp = q.front();
		if (tmp.x == M && tmp.y == N) {
			cout << tmp.cnt << "\n";
			return;
		}

		q.pop();

		if (tmp.x + 1 <= M && arr[tmp.y][tmp.x + 1]) {
			q.push(Node(tmp.y, tmp.x + 1, tmp.cnt + 1));
			arr[tmp.y][tmp.x + 1] = false;
		}
		if (tmp.y + 1 <= N && arr[tmp.y + 1][tmp.x]) {
			q.push(Node(tmp.y + 1, tmp.x, tmp.cnt + 1));
			arr[tmp.y + 1][tmp.x] = false;
		}
		if (tmp.y - 1 >= 1 && arr[tmp.y - 1][tmp.x]) {
			q.push(Node(tmp.y - 1, tmp.x, tmp.cnt + 1));
			arr[tmp.y - 1][tmp.x] = false;
		}
		if (tmp.x - 1 >= 1 && arr[tmp.y][tmp.x - 1]) {
			q.push(Node(tmp.y, tmp.x - 1, tmp.cnt + 1));
			arr[tmp.y][tmp.x - 1] = false;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < M; j++) {
			arr[i][j + 1] = s[j] - '0';
		}
	}

	BFS(1, 1);
}

//bool visit[100001];
//
//class Node {
//public:
//	int value;
//	int cnt;
//	Node(int value, int cnt) {
//		this->value = value;
//		this->cnt = cnt;
//	}
//};
//
//void BFS(int start) {
//	queue<Node> q;
//	q.push(Node(start, 0));
//
//	while (!q.empty()) {
//		Node tmp = q.front();
//		if (tmp.value == K) {
//			cout << tmp.cnt << "\n";
//			return;
//		}
//
//		visit[tmp.value] = true;
//		q.pop();
//
//		if (tmp.value - 1 >= 0 && !visit[tmp.value - 1]) q.push(Node(tmp.value - 1, tmp.cnt + 1));
//		if (tmp.value + 1 <= 100000 && !visit[tmp.value + 1]) q.push(Node(tmp.value + 1, tmp.cnt + 1));
//		if (tmp.value * 2 <= 100000 && !visit[tmp.value * 2]) q.push(Node(tmp.value * 2, tmp.cnt + 1));
//	}
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int N, M;
//
//int arr[100][100];
//
//vector<int> v[10000];
//bool visit[100][100];
//
//int cnt;
//
//void bfs(int start) {
//	queue <int> q;
//	q.push(start);
//
//	while (!q.empty()) {
//		cnt++;
//		int tmp = q.front();
//
//		int i_c = tmp / 100;
//		int j_c = tmp % 100;
//
//		if (i_c + 1 == N && j_c + 1 == M) {
//			cout << cnt << "\n";
//			return;
//		}
//		
//		q.pop();
//
//		for (auto e : v[tmp]) {
//			i_c = e / 100;
//			j_c = e % 100;
//
//			if (!visit[i_c][j_c]) {
//				q.push(e);
//				visit[i_c][j_c] = true;
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
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < M; j++) {
//			arr[i][j] = s[j] - '0';
//		}
//	}
//	
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (arr[i][j] == 0) continue;
//
//			if (i + 1 < N) {
//				if (arr[i + 1][j] == 1) v[i * 100 + j].push_back((i + 1) * 100 + j);
//			}
//
//			if (j + 1 < M) {
//				if (arr[i][j + 1] == 1) v[i * 100 + j].push_back(i * 100 + j + 1);
//			}
//
//			if (i - 1 > -1) {
//				if (arr[i + 1][j] == 1) v[i * 100 + j].push_back((i - 1) * 100 + j);
//			}
//
//			if (j - 1 > -1) {
//				if (arr[i][j - 1] == 1) v[i * 100 + j].push_back(i * 100 + j - 1);
//			}
//		}
//	}
//
//	bfs(0);
//}