#include<iostream>  
#include <vector>
#include <queue>
#include <algorithm>

int N, M, S;

using namespace std;

vector<int> v[1001];
bool D[1001];
bool B[1001];

void DFS(int start) {
	cout << start << " ";
	D[start] = true;

	for (auto& e : v[start]) {
		if (!D[e]) {
			DFS(e);
		}
	}
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	B[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();

		for (auto& e : v[tmp]) {
			if (!B[e]) {
				q.push(e);
				B[e] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> S;
	int tmp_s, tmp_e;
	for (int i = 0; i < M; i++) {
		cin >> tmp_s >> tmp_e;
		v[tmp_s].push_back(tmp_e);
		v[tmp_e].push_back(tmp_s);
	}

	for (int i = 1; i <= N; i++) sort(v[i].begin(), v[i].end());

	DFS(S); cout << "\n";
	BFS(S); cout << "\n";
}

//vector<int> v[10001];
//bool edge1[1001];
//bool edge2[1001];
//
//void DFS(int start) {
//    cout << start << " ";
//    edge1[start] = true;
//
//    for (auto e : v[start]) {
//        if (!edge1[e]) {
//            edge1[e] = true;
//            DFS(e);
//        }
//    }
//}
//
//void BFS(int start) {
//    vector<int> queue;
//    queue.push_back(start);
//    edge2[start] = true;
//
//    while (!queue.empty()) {
//        int tmp = queue[0];
//
//        cout << tmp << " ";
//
//        queue.erase(queue.begin());
//
//        for (auto e : v[tmp]) {
//            if (!edge2[e]) {
//                edge2[e] = true;
//                queue.push_back(e);
//            }
//        }
//    }
//}
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> N >> M >> s;
//
//    int a, b;
//    for (int i = 0; i < M; i++) {
//        cin >> a >> b;
//        v[a].push_back(b);
//        v[b].push_back(a);
//    }
//
//    for (int i = 1; i <= N; i++) {
//        sort(v[i].begin(), v[i].end());
//    }
//
//    DFS(s);
//    cout << "\n";
//    BFS(s);
//    cout << "\n";
//
//    return 0;
//}