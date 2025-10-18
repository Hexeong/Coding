//
// Created by hex on 25. 10. 18..
//
#include <iostream>

using namespace std;

long long gcm(long long a, long long b) {
    if (b > a)
        swap(a, b);

    long long s = a % b;
    while (a > 0 && s != 0) {
        a = b;
        b = s;
        s = a % b;
    }

    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        long long a, b; cin >> a >> b;

        cout << (a / gcm(a, b)) * b << '\n';
    }
}