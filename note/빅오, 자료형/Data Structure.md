## 배열

- **Python - list()** : 요소에 대한 포인터 목록을 갖고 있는 구조체로 선언되어 있음
	- 연속된 메모리에 각 데이터가 저장된 주소(Pointer) 값이 저장되어 있다. 데이터가 저장된 곳은 연속된 곳에 있지 않다.
	- 배열에는 각자 다른 타입을 저장할 수 있다. (e.g. `a = [1, 'T', True]`)
- **C++ - vector** : 동적 배열로 구현된 STL 컨테이너
	- 메모리에서 효율적으로 크기를 변경할 수 있게 설계되어 있다.
	- 내부적으로 연속된 메모리 블록에 데이터를 저장하며, 크기가 변경될 때 재할당을 통해 메모리를 확장하거나 축소합니다.

## 해쉬 테이블

- **Python - dict()** : 문자를 포함해 다양한 타입을 키로 사용할 수 있는 구조체임
	- 해시할 수만 있다면 숫자 뿐만 아니라, 문자, 집합까지 불변 객체를 모두 키로 사용할 수 있다.
	- 최악의 경우 `O(n)`이 될 수 있지만, 대부분의 경우 훨씬 더 빨리 실행되며, **분할 상환 분석**에 따른 시간 복잡도는 `O(1)`이다.
	- **주요 연산 시간 복잡도** : 
		- `len(a) : O(1)`
		- `a[key] : O(1)`
		- `a[key] = value : O(1)`
		- `key in a : O(1)`

- **C++ - unordered_map** : 키-값 쌍을 저장하며 해시 테이블 기반 컨테이너
	- 내부적으로 **해시 함수**를 사용해 데이터를 저장하므로, 정렬된 순서를 보장하지 않지만 **상수 시간**에 가까운 성능을 제공하는 것이 특징이다.
	- 특정 크기의 **버킷(bucket) 배열**로 메모리에 저장되어 있다. 각각의 버킷은 연결 리스트나 트리 형태로 `여러 개의 요소를 저장할 수 있는 슬롯`입니다. 키 값이 삽입될 때, 해시 함수에 의해 버킷 배열에서 어느 슬롯에 저장할지 결정합니다.
	- Collision에 대해서는 `체이닝 방식`을 사용해 해결합니다.
	- 데이터가 많이 저장되면 충돌이 많아져 성능이 저하될 수 있으므로, unordered_map은 일정 수준 이상 데이터가 저장되면 `리해싱(rehashing)`을 통해 버킷 배열의 크기를 증가시키고,  **모든 데이터를 다시 해시**하여 새로운 버킷 배열에 재분배한다.

>[!important]
>미리 버킷 슬롯 수를 지정해 리해싱 빈도를 지정할 수 있다.
```c++
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> umap;

    // 리해싱 방지를 위해 버킷 수를 미리 설정
    umap.reserve(10000);

    for (int i = 0; i < 10000; ++i) {
        umap[i] = i;
    }

    std::cout << "Size: " << umap.size() << std::endl;

    return 0;
}

```

## Priority Queue

1. C++ - 

## Graph

1. C++ - 인접리스트, 희소  그래프일 때 사용
```c++
const int N = 1000; // 최대 정점 수
vector<int> adj[N]; // 인접 리스트

void addEdge(int u, int v) {
    adj[u].push_back(v); // 유향 그래프일 경우
    adj[v].push_back(u); // 무향 그래프일 경우
}

// **시간 복잡도**: 노드 `u`에 인접한 노드들을 탐색하는데 `O(k)` (k는 인접한 노드의 개수).
// **메모리**: `O(V + E)` (V는 정점의 개수, E는 간선의 개수).
```

2. C++ - 인접 행렬, dense 그래프일 때 사용
```c++
const int N = 1000; // 최대 정점 수
int adjMatrix[N][N]; // 인접 행렬

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // 무향 그래프일 경우
}

// **시간 복잡도**: 두 노드가 연결되었는지 확인하는 데 `O(1)`.
// **메모리**: `O(V^2)` (V는 정점의 개수).
```

```c++
void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// 단일 출발점에서 모든 노드에 대한 최단 경로
const int INF = 1e9;
const int N = 1000;
vector<pair<int, int>> adj[N]; // 인접 리스트, {가중치, 정점}

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (dist[u] < d) continue;

        for (auto edge : adj[u]) {
            int v = edge.second;
            int w = edge.first;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
```