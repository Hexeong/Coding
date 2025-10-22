//
// Created by hex on 25. 10. 22..
//
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        string X, Y; cin >> X >> Y;

        int x_cnt = 0, y_cnt = 0;
        for (int i = 0; i < X.length(); i++) {
            x_cnt += (X[i] - 'a' + 1);
            y_cnt += (Y[i] - 'a' + 1);
        }

        if ((x_cnt + y_cnt) % 2) { // 홀수면
            for (int i = 0; i < X.length(); i++)
                cout << (i % 2 ? Y[i] : X[i]);
            cout << '\n';
        } else {
            for (int i = 0; i < X.length(); i++)
                cout << (i % 2 ? X[i] : Y[i]);
            cout << '\n';
        }
    }
}