#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Entry {
public:
	int x;
	int y;
	int z;
	Entry(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}
};

int V, E, re;
Entry e[100000];
vector<pair<int, int>> v[10001];

bool compare(Entry a, Entry b) {
	return a.z < b.z;
}

void DFS(int start) {

}

int main() {
	cin >> V >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		/*v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));*/
		e[i] = Entry(a, b, c);
	}
	
	sort(e, e + E, compare);

	for (int i = 0; i < E; i++) {

	}

}

// 간선을 모두 받고, 그 다음 정렬
// 이 후, 가중치가 낮은 순대로 뽑기
// 뽑을 때, cycle이 없도록, 같은 목적지의 간선이 없도록
//