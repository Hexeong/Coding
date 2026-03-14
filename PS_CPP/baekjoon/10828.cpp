#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<int> stk;

    while (N--) {
        string s; cin >> s;
        if (s == "push") {
            int x; cin >> x;
            stk.push_back(x);
        } else if (s == "pop") {
            if (stk.empty())
                cout << -1 << endl;
            else {
                cout << stk.back() << endl;
                stk.pop_back();
            }
        } else if (s == "size") {
            cout << stk.size() << endl;
        } else if (s == "empty") {
            cout << (stk.empty() ? 1 : 0) << endl;
        } else if (s == "top") {
            if (stk.empty())
                cout << -1 << endl;
            else
                cout << stk.back() << endl;
        }
    }

    return 0;
}