- **최소 신장 트리(MST)** 를 구하는 알고리즘 중 하나입니다.
- 연결된 그래프에서 **최소 비용으로 모든 노드를 연결**하는 경우에 주로 쓰입니다.

---

```c++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000  // 무한대 값 정의

// 프림 알고리즘 함수
int prim(int start, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> minDist(n, INF);  // 각 노드로의 최소 비용
    vector<bool> visited(n, false);  // 방문 여부 확인
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    minDist[start] = 0;
    pq.push({0, start});

    int mst_cost = 0;

    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        mst_cost += current_cost;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && weight < minDist[v]) {
                minDist[v] = weight;
                pq.push({weight, v});
            }
        }
    }

    return mst_cost;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);

    // 그래프 정의 (노드, 가중치)
    graph[0].push_back({1, 10});
    graph[0].push_back({3, 30});
    graph[0].push_back({4, 100});
    graph[1].push_back({2, 50});
    graph[2].push_back({4, 10});
    graph[3].push_back({2, 20});
    graph[3].push_back({4, 60});

    int start_node = 0;
    int total_cost = prim(start_node, graph);

    cout << "Total cost of MST: " << total_cost << endl;

    return 0;
}

```