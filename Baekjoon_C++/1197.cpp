#include <iostream>
#include <queue>

using namespace std;

struct edge {
    int u;
    int v;
    int w;
};

struct Compartor {
    bool operator()(edge& a, edge& b) const {
        return a.w > b.w;
    }
};

int find(vector<int>& root, int x) {
    if (root[x] == x)
        return x;

    return root[x] = find(root, root[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E; cin >> V >> E;
    priority_queue<edge, vector<edge>, Compartor> pq;

    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        pq.push({u, v, w});
    }

    int cnt = 0;
    int result = 0;
    vector<int> root(V + 1);
    for (int i = 1; i <= V; i++)
        root[i] = i;

    while (!pq.empty()) {
        if (cnt == V - 1)
            break;

        edge e = pq.top();
        pq.pop();

        int u_root = find(root, e.u);
        int v_root = find(root, e.v);

        if (u_root != v_root) {
            root[u_root] = v_root;
            result += e.w;
            cnt++;
        }
    }

    cout << result << '\n';
}