#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, R, cnt{ 1 };

vector<int> nodes[100001];
bool visited[100001];
int visited_s[100001];
queue<int> q;

void bfs(int n) {
  q.push(n);
  visited[n] = true;
  
  while(!q.empty()) {
    int temp = q.front();
    q.pop();
    visited_s[temp] = cnt++;

    for(auto e : nodes[temp]) {
      if(!visited[e]) {
        q.push(e);
        visited[e] = true;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> R;

  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
  }

  for(int i = 0; i<=N; i++) sort(nodes[i].begin(), nodes[i].end());

  bfs(R);

  for(int i = 1; i<=N; i++) cout << visited_s[i] << '\n';
  
  return 0;
}