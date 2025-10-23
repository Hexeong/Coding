//
// Created by hex on 25. 10. 23..
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    while (N--) {
        long long n; cin >> n;

        stack<long long> s;
        while (n > 0) {
            s.push(n % (16LL * 16LL));
            n /= (16LL * 16LL);
        }

        while (s.size() < 4)
            s.push(0LL);

        n = 0;
        int e = 1;
        while (!s.empty()) {
            n += (s.top() * e);
            s.pop();
            e *= (16LL * 16LL);
        }

        cout << n << '\n';
    }
}