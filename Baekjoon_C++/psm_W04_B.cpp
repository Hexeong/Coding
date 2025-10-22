//
// Created by hex on 25. 10. 22..
//
#include <iostream>
#include <algorithm>

#define INT_MAX 2147483647

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        vector<vector<int>> v(3, vector<int>(2 * N + 1, INT_MAX));
        for(int i = 0; i < 2 * N + 1; i++) cin >> v[0][i];

        sort(v[0].begin(),v[0].end());

        v[1][1] = v[0][1] - v[0][0];
        v[2][2] = v[0][2] - v[0][0];
        for (int i = 3; i < 2 * N + 1; i++) {
            if (i % 2 == 0)
                v[2][i] = min(v[1][i - 3] + v[0][i] - v[0][i - 2], v[2][i - 2] + v[0][i] - v[0][i - 1]);
            else
                v[1][i] = v[1][i - 2] + v[0][i] - v[0][i - 1];
        }

        cout << v[2][2 * N] << '\n';
    }
}