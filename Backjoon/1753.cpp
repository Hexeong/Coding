//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int V, E, K, mini;
//
//vector<vector<int>> m;
//
//void BFS(int End) {
//	queue<int> q;
//	for (int i = 1; i < m[K].size(); i++) {
//		if
//	}
//}
//
//int main() {
//	cin >> V >> E >> K;
//	for (int i = 0; i < V; i++) {
//		vector<int> tmp; tmp.push_back(0);
//		m.push_back(tmp);
//	}
//
//	int u, v, w;
//	for (int i = 0; i < E; i++) {
//		cin >> u >> v >> w;
//		if (u > m[v].size()) for (int i = m[v].size(); i < u; i++) m[v].push_back(0);
//		if (v > m[u].size()) for (int i = m[u].size(); i < v; i++) m[u].push_back(0);
//		m[v][u] = w; m[u][v] = w;
//	}
//
//	for (int i = 1; i <= V; i++) {
//		mini = 0;
//		BFS(i);
//	}
//}