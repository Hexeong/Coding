//
// Created by admin on 2025-08-15.
//
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> oper;

void hanoi(int n, int from, int middle, int to) {
    if (n == 0)
        return;

    hanoi(n - 1, from, to, middle);
    cout << from << " " << to << '\n';
    // endl은 개행 + flush로 버퍼를 강제로 비워서 즉시 I/O를 발생 시키게 됨. 때문에
    // 성능저하의 원인이 된다. 웬만하면 '\n'으로 개행 처리 하기
    hanoi(n - 1, middle, from, to);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    cout << ((1ll << n) - 1) << '\n';
    hanoi(n, 1, 2, 3);
}