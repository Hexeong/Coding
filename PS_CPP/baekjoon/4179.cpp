//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int r, c;
//
//char arr[1000][1000];
//
//int xm[4] = { 1, 0, 0, -1 };
//int ym[4] = { 0, 1, -1, 0 };
//
//class Entry {
//public:
//	int x;
//	int y;
//	int cnt;
//	char sym;
//	Entry(int y, int x, int cnt, char sym) {
//		this->y = y;
//		this->x = x;
//		this->cnt = cnt;
//		this->sym = sym;
//	}
//};
//
//queue<Entry> q;
//
//int check = 1;
//int x, y;
//
//void BFS() {
//	while (!q.empty()) {
//		Entry tmp = q.front();
//
//		q.pop();
//
//		if(arr[tmp.y][tmp.x] != tmp.sym) continue;
//
//		for (int i = 0; i < 4; i++) {
//			x = tmp.x + xm[i]; y = tmp.y + ym[i];
//			if (x < 0 || x >= c) {
//				if (tmp.sym == 'J') {
//					cout << tmp.cnt + 1 << "\n";
//					return;
//				}
//				else continue;
//			}
//			if (y < 0 || y >= r) {
//				if (tmp.sym == 'J') {
//					cout << tmp.cnt + 1 << "\n";
//					return;
//				}
//				else continue;
//			}
//
//			if (arr[y][x] != '#') {
//				q.push(Entry(y, x, tmp.cnt + 1, tmp.sym));
//				arr[y][x] = tmp.sym;
//			}
//		}
//	}
//	cout << "IMPOSSIBLE\n";
//}
//
//// 메모리 초과의 경우 겹치는 부분이 생길시 q에서 없애는 것
//// 
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	cin >> r >> c;
//
//	for (int i = 0; i < r; i++) {
//		string s; cin >> s;
//		for (int j = 0; j < c; j++) {
//			arr[i][j] = s[j];
//			if (arr[i][j] == 'J' || arr[i][j] == 'F') {
//				q.push(Entry(i, j, 0, arr[i][j]));
//			}
//		}
//	}
//
//	if (q.front().sym == 'F') {
//		Entry tmp = q.front();
//		q.pop();
//		q.push(tmp);
//	}
//
//	BFS();
//}