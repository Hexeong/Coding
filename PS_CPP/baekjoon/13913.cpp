#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, cnt;

int b[100001];
bool visit[100001];
vector<int> p;

void BFS() {
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));

	int curP, curC;
	while (!q.empty()) {
		curP = q.front().first;
		curC = q.front().second;
		q.pop();
		
		if (K == curP) {
			int index = curP;
			while (index != N) {
				p.push_back(index);
				index = b[index];
			}
			p.push_back(N);
			cnt = curC;
			return;
		}

		if (curP - 1 > -1 && !visit[curP - 1]) {
			b[curP - 1] = curP;
			visit[curP - 1] = true;
			q.push(make_pair(curP - 1, curC + 1));
		}
		if (curP + 1 < 100001 && !visit[curP + 1]) {
			b[curP + 1] = curP; // b[1] = 0 
			visit[curP + 1] = true;
			q.push(make_pair(curP + 1, curC + 1));
		}
		if (curP * 2 < 100001 && !visit[curP * 2]) {
			b[curP * 2] = curP; // b[0] = 0
			visit[curP * 2] = true;
			q.push(make_pair(curP * 2, curC + 1));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	if (N > K) {
		cout << N - K << "\n";
		for (int i = N; i >= K; i--) cout << i << " ";
	}
	else {
		BFS();
		cout << cnt << "\n";
		for (int i = p.size() - 1; i > -1; i--) {
			cout << p[i] << " ";
		}
	}
}

//int b[100001]; // cnt 저장
//vector<int> v; // 순서 저장, push_back과pop을 넘나들면서 진행

// DFS로 해보자, 이론적으로는 시간초과 날 듯, 2초 컷라인

// BFS는 메모리 초과가 난다
		/*b[N].first = 0;
		b[N].second.push_back(N);

		q.push(N);

		BFS(N);
		cout << b[K].first << "\n";
		for (int i = 0; i < b[K].second.size(); i++) {
			cout << b[K].second[i] << " ";
		}*/

//pair<int, vector<int>> b[100001];
//queue<int> q;
//
//void BFS(int start) {
//	if (start == K) return;
//	int tmp;
//
//	while (!q.empty()) {
//		tmp = q.front();
//		q.pop();
//
//		//벡터를 여기서 완성
//
//		if (tmp - 1 > -1 && b[tmp - 1].first == 0) {
//			b[tmp - 1].first = b[tmp].first + 1;
//			b[tmp - 1].second = { b[tmp].second.begin(), b[tmp].second.end() };
//			b[tmp - 1].second.push_back(tmp - 1);
//			if (tmp - 1 == K) return;
//			q.push(tmp - 1);
//			// b[tmp - 1].first > b[tmp].first가 될 가능성은 없으므로 하지 않는다
//		}
//		if (tmp + 1 < 100001 && b[tmp + 1].first == 0) {
//			b[tmp + 1].first = b[tmp].first + 1;
//			b[tmp + 1].second = { b[tmp].second.begin(), b[tmp].second.end() };
//			b[tmp + 1].second.push_back(tmp + 1);
//			if (tmp + 1 == K) return;
//			q.push(tmp + 1);
//		}
//		if (tmp * 2 < 100001 && b[tmp * 2].first == 0) {
//			b[tmp * 2].first = b[tmp].first + 1;
//			b[tmp * 2].second = { b[tmp].second.begin(), b[tmp].second.end() };
//			b[tmp * 2].second.push_back(tmp * 2);
//			if (tmp * 2 == K) return;
//			q.push(tmp * 2);
//		}
//		b[tmp].second.clear();
//	}
//}