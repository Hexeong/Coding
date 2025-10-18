//
// Created by hex on 25. 10. 18..
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<bool> A(N + 1, false);

        for (int i = 0; i < M; i++) {
            int cur; cin >> cur;

            int temp = cur;
            while (temp > 0 && !A[temp])
                temp /= 2;
            if (temp == 0) {
                cout << "Success\n";
                A[cur] = true;
            } else
                cout << "Fail\n";
        }
    }
}