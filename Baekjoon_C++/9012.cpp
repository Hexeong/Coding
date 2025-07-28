//
// Created by admin on 2025-07-28.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;

    while (T--) {
        string s; cin >> s;

        stack<char> stk;
        bool isValid = true;

        for (char c : s) {
            if (c == '(')
                stk.push(c);
            else if (c == ')' && !stk.empty() && stk.top() == '(') {
                stk.pop();
            }
            else {
                cout << "NO" << endl;
                isValid = false;
                break;
            }
        }

        if (!isValid)
            continue;

        if (stk.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}