#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R, cnt{1};

class Node{
public:
  int v;
  vector<int> l;
  Node() { this->v = 0; };
};

Node Nodes[100001];
// bool Nodes[100001][100001];
// int visited_s[100001];
bool visited[100001];

void dfs(int node) {
  Nodes[node].v = cnt++;
  visited[node] = true;
  // for (int i = 1; i <= a; i++) {
  //   if (!visited[i] && Nodes[node][i])
  //     dfs(i); // 방문하지 않고, 간선일 때 실행
  // }
  for(auto e : Nodes[node].l) {
    if(!visited[e]) dfs(e);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> R;

  for (int i = 0; i < M; i++) {
    int d, e;
    cin >> d >> e;
    // Nodes[d][e] = true;
    Nodes[d].l.push_back(e);
    Nodes[e].l.push_back(d);
  }
  // 오름차순 정렬
  for (int i = 1; i<=N; i++) sort(Nodes[i].l.begin(), Nodes[i].l.end());

  dfs(R);

  for (int i = 1; i <= N; i++)
    cout << Nodes[i].v << '\n';

  return 0;
}