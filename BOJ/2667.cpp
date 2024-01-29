#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, result, cnt;
vector<int> v;
bool b[26][26];

int y[] = { 0,-1,0,1 };
int x[] = { 1,0,-1,0 };

void DFS(int start_i, int start_j) {
	cnt++;
	
	for (int i = 0; i < 4; i++) {
		if (start_i + y[i] < 1 || start_i + y[i] > 25) continue;
		if (start_j + x[i] < 1 || start_j + x[i] > 25) continue;
		if (b[start_i + y[i]][start_j + x[i]]) {
			b[start_i + y[i]][start_j + x[i]] = false;
			DFS(start_i + y[i], start_j + x[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) b[i][j + 1] = s[j] - '0';
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (b[i][j]) {
				b[i][j] = false;
				DFS(i, j);
				v.push_back(cnt);
				cnt = 0;
				result++;
			}
		}
	}

	sort(v.begin(), v.end());

	cout << result << "\n";
	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
}

//int N, cnt;
//
//bool arr[26][26];
//
//int xm[4] = { 1, 0, 0, -1 };
//int ym[4] = { 0, 1, -1, 0 };
//
//
//void DFS(int y, int x) {
//	arr[y][x] = false;
//
//	for (int i = 0; i < 4; i++) {
//		if (y + ym[i] < 1 || y + ym[i] > N) {
//			continue;
//		}
//		if (x + xm[i] < 1 || x + xm[i] > N) {
//			continue;
//		}
//		if (arr[y + ym[i]][x + xm[i]]) {
//			arr[y + ym[i]][x + xm[i]] = false;
//			cnt++;
//			DFS(y + ym[i], x + xm[i]);
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		string s;
//		cin >> s;
//		for (int j = 1; j <= N; j++) {
//			arr[i][j] = s[j - 1] - '0';
//		}
//	}
//
//	vector<int> counting;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			if (!arr[i][j]) continue;
//			
//			cnt = 1;
//			DFS(i, j);
//
//			counting.push_back(cnt);
//		}
//	}
//
//	sort(counting.begin(), counting.end());
//
//	cout << counting.size() << "\n";
//	for (int i = 0; i < counting.size(); i++) {
//		cout << counting[i] << "\n";
//	}
//}