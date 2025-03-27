- **최소 신장 트리(MST)** 를 구하는 또 다른 알고리즘입니다.
- 프림과 달리 간선을 정렬하고, 이를 선택적으로 연결해 나가는 방식으로 동작합니다.
- 서로소 집합(Disjoint Set)을 활용해 사이클을 방지하는 것이 특징입니다.

---

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000  // 무한대 값 정의

// 간선 정보를 저장하는 구조체
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 부모 노드를 찾는 함수 (유니온-파인드)
int findParent(vector<int>& parent, int u) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent, parent[u]);
}

// 두 노드를 연결하는 함수 (유니온-파인드)
void unionNodes(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (u != v) {
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
}

// 크루스칼 알고리즘 함수
int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());  // 간선을 가중치 기준으로 정렬

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    int mst_cost = 0;
    for (const auto& edge : edges) {
        if (findParent(parent, edge.u) != findParent(parent, edge.v)) {
            unionNodes(parent, rank, edge.u, edge.v);
            mst_cost += edge.weight;
        }
    }

    return mst_cost;
}

int main() {
    int n = 5;
    vector<Edge> edges;

    // 간선 추가 (u, v, weight)
    edges.push_back({0, 1, 10});
    edges.push_back({0, 3, 30});
    edges.push_back({0, 4, 100});
    edges.push_back({1, 2, 50});
    edges.push_back({2, 4, 10});
    edges.push_back({3, 2, 20});
    edges.push_back({3, 4, 60});

    int total_cost = kruskal(n, edges);

    cout << "Total cost of MST: " << total_cost << endl;

    return 0;
}

```