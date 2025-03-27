- **특정 노드에서 다른 모든 노드까지의 최단 경로**를 구할 때 사용됩니다.
- 주로 가중치가 양수인 그래프에서 사용되며, 경로 탐색 문제에서 자주 등장합니다.

---

```c++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000  // 무한대 값 정의 (충분히 큰 값)

// 다익스트라 알고리즘 함수
vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);  // 각 노드까지의 최단 거리 저장
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;  // 시작 노드의 거리는 0
    pq.push({0, start});  // (거리, 노드) 쌍을 우선순위 큐에 넣음

    while (!pq.empty()) {
        int current_dist = pq.top().first;  // 현재 노드까지의 최단 거리
        int u = pq.top().second;  // 현재 노드
        pq.pop();

        // 이미 처리된 노드라면 넘어감
        if (current_dist > dist[u]) continue;

        // 인접한 모든 노드에 대해 최단 거리 갱신
        for (const auto& edge : graph[u]) {
            int v = edge.first;  // 인접 노드
            int weight = edge.second;  // 가중치

            // 더 짧은 경로가 있다면 갱신
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});  // 우선순위 큐에 갱신된 정보 넣음
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;  // 노드의 개수
    vector<vector<pair<int, int>>> graph(n);

    // 그래프 정의 (노드, 가중치)
    graph[0].push_back({1, 10});
    graph[0].push_back({3, 30});
    graph[0].push_back({4, 100});
    graph[1].push_back({2, 50});
    graph[2].push_back({4, 10});
    graph[3].push_back({2, 20});
    graph[3].push_back({4, 60});

    int start_node = 0;  // 시작 노드
    vector<int> distances = dijkstra(start_node, graph);

    // 결과 출력
    for (int i = 0; i < n; ++i) {
        if (distances[i] == INF) {
            cout << "Node " << i << " is unreachable from node " << start_node << endl;
        } else {
            cout << "Shortest distance from node " << start_node << " to node " << i << " is " << distances[i] << endl;
        }
    }

    return 0;
}

```