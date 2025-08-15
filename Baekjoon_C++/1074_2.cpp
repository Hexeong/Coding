//
// Created by admin on 2025-08-15.
//
#include <iostream>

using namespace std;

int r, c;
int counter = 0;

void z_move(int N, int offset_y, int offset_x) {
    if (N == 0) {
        if (offset_y == r && offset_x == c)
            cout << counter << '\n';
        else
            cout << "안들어가는 경우 발생\n";
        return;
    }

    if (offset_y + (1 << (N - 1)) <= r && offset_x + (1 << (N - 1)) <= c) {
        counter += (1 << (N - 1)) * (1 << (N - 1)) * 3;
        z_move(N - 1, offset_y + (1 << (N - 1)), offset_x + (1 << (N - 1))); // 4사분면
    } else if (offset_y + (1 << (N - 1)) <= r) {
        counter += (1 << (N - 1)) * (1 << (N - 1)) * 2;
        z_move(N - 1, offset_y + (1 << (N - 1)), offset_x); // 3사분면
    } else if (offset_x + (1 << (N - 1)) <= c) {
        counter += (1 << (N - 1)) * (1 << (N - 1));
        z_move(N - 1, offset_y, offset_x + (1 << (N - 1))); // 2사분면
    } else {
        z_move(N - 1, offset_y, offset_x); // 1사분면
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N >> r >> c;
    // N <= 15, 0 <= r, c < 2^N
    // 2^N <= 1024 * 32 ~~ 33000
    z_move(N, 0, 0);
}