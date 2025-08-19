//
// Created by admin on 2025-08-19.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int input[8];
vector<int> procedure;
int N, M;

void bt(int last_idx, int repeat) {
    if (repeat == M) {
        for (auto& p : procedure)
            cout << p << " ";
        cout << "\n";
    }

    for (int i = last_idx; i < N; i++) {
        procedure.push_back(input[i]);
        bt(i + 1, repeat + 1);
        procedure.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    sort(input, input+N);

    bt(0, 0);
}