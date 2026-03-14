//
// Created by hex on 25. 11. 6..
//
#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int>& root) {
    while (x != root[x])
        x = root[x];
    return x;
}

void unite(int a, int b, vector<int>& root) {
    int a_root = find(a, root);
    int b_root = find(b, root);

    root[b_root] = a_root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;

        vector<int> root(n + 1);
        for (int i = 0; i <= n; i++)
            root[i] = i;

        for (int i = 0; i < k; i++) {
            int a, b; cin >> a >> b;

            unite(a, b, root);
        }

        int m; cin >> m;
        cout << "Scenario " << t << ":\n";
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;

            if (find(a, root) == find(b, root))
                cout << "1\n";
            else
                cout << "0\n";
        }
        cout << "\n";
    }
}