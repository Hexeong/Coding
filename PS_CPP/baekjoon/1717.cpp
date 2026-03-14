//
// Created by hex on 25. 11. 6..
//
#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& root, int x) {
    int p = root[x];
    while (p != root[p])
        p = root[p];

    return p;
}

void unite(vector<int>& root, int a, int b) {
    int a_root = find(root, a);
    int b_root = find(root, b);

    root[b_root] = a_root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> root(n + 1);
    for (int i = 0; i <= n; i++) root[i] = i; // initial cond

    for (int i = 0; i < m; i++) {
        int choice, x, y; cin >> choice >> x >> y;
        if (choice == 0) {
            unite(root, x, y);
        } else if (choice == 1) {
            int x_root = find(root, x);
            int y_root = find(root, y);
            if (x_root == y_root)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}