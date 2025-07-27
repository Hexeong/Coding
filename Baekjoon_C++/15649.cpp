#include <iostream>
using namespace std;

const int MAX = 8 + 1;

int N, M;
int arr[MAX];
bool visited[MAX];

void func(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			func(cnt + 1);
			visited[i] = false;
		}
}

int main(void)
{
	cin >> N >> M;

	func(0);
	return 0;
}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int N, M;
//vector<int> v;
//bool check[9];
//
//void DFS(int& cur) {
//	if (v.size() == M) {
//		for (auto& e : v) {
//			cout << e << " ";
//		}
//		cout << endl;
//		check[v[v.size() - 1]] = false;
//		v.pop_back();
//	}
//	else { // 여기에 중복을 해결하는 기능을 추가해야 됨
//		if (!check[cur]) {
//			check[cur] = true;
//			v.push_back(cur);
//			if (v.size() == M) {
//				for (auto& e : v) {
//					cout << e << " ";
//				}
//				cout << endl;
//				check[v[v.size() - 1]] = false;
//				v.pop_back();
//			}
//			else {
//				for (int i = 1; i <= N; i++) {
//					DFS(i);
//				}
//				check[v[v.size() - 1]] = false;
//				v.pop_back();
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
//	for (int i = 1; i <= N; i++) {
//		DFS(i);
//	}
//}