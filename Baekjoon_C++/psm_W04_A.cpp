//
// Created by hex on 25. 10. 22..
//
#include <iostream>
#include <queue>

using namespace std;

using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin>>T;
    while(T--) {
        int N; cin >> N;

        queue<PII> q;
        int result = 0;
        q.push(PII(1, N));
        while(!q.empty()) {
            PII p = q.front(); q.pop();
            if (p.second - p.first == 0)
                result += p.first;
            else if (p.second - p.first >= 2) {
                q.push(PII(p.first, (p.first + p.second) / 2));
                q.push(PII((p.first + p.second) / 2 + 1, p.second));
            }
        }

        cout << result << '\n';
    }
}