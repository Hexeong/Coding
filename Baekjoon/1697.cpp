#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int N, K;

bool visit[100001];

class Node {
public:
	int value;
	int cnt;
	Node(int value, int cnt) {
		this->value = value;
		this->cnt = cnt;
	}
};

void BFS(int start) {
	queue<Node> q;
	q.push(Node(start, 0));

	while (!q.empty()) {
		Node tmp = q.front();
		if (tmp.value == K) {
			cout << tmp.cnt << "\n";
			return;
		}

		visit[tmp.value] = true;
		q.pop();

		if (tmp.value - 1 >= 0 && !visit[tmp.value - 1]) q.push(Node(tmp.value - 1, tmp.cnt + 1));
		if (tmp.value + 1 <= 100000 && !visit[tmp.value + 1]) q.push(Node(tmp.value + 1, tmp.cnt + 1));
		if (tmp.value * 2 <= 100000 && !visit[tmp.value * 2]) q.push(Node(tmp.value * 2, tmp.cnt + 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	BFS(N);
}

/*for (int j = i; j >= N; j--) {
					if (cnt[j] + 1 < cnt[j - 1]) {
						cnt[j - 1] = cnt[j] + 1;
						if (2 * j - 2 <= 100000) cnt[2 * j - 2] = min(cnt[2 * j - 2], cnt[j - 1] + 1);
					}
					else break;
				}*/

//int cnt[100001];
//
//void function() {
//	for (int i = N + 1; i <= 100000; i++) {
//		if (cnt[i] == 0) cnt[i] = cnt[i - 1] + 1;
//		if (i % 2 == 0 && i / 2 >= N) cnt[i] = min(cnt[i], cnt[i / 2] + 1);
//
//		for (int j = i; j >= N + 1; j--) {
//			if (cnt[j - 1] > cnt[j] + 1) {
//				cnt[j - 1] = cnt[j] + 1;
//				i = j + 1;
//			}
//			else break;
//		}
//	}
//}