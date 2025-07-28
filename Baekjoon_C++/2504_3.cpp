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

    string s;
    cin >> s;

    stack<int> stk;

    for (char c : s) {
        if (c == '(' || c == '[') {
            stk.push(c == '(' ? -1 : -2);
        }
        else if (c == ')') {

            int tmp = 0;

            while (!stk.empty() && stk.top() != -1) {
                if (stk.top() == -2) {
                    cout << 0 << endl;
                    return 0;
                }

                tmp += stk.top();
                stk.pop();
            }

            if (tmp == 0)
                tmp = 2;
            else
                tmp *= 2;

            if (stk.empty()) {
                cout << 0 << endl;
                return 0;
            }

            stk.pop();
            stk.push(tmp);
        } else if (c == ']') {
            int tmp = 0;

            while (!stk.empty() && stk.top() != -2) {
                if (stk.top() == -1) {
                    cout << 0 << endl;
                    return 0;
                }

                tmp += stk.top();
                stk.pop();
            }

            if (tmp == 0)
                tmp = 3;
            else
                tmp *= 3;

            if (stk.empty()) {
                cout << 0 << endl;
                return 0;
            }

            stk.pop();
            stk.push(tmp);
        }
    }

    int result = 0;
    while (!stk.empty()) {
        if (stk.top() < 0) {
            cout << 0 << endl;
            return 0;
        }

        result += stk.top();
        stk.pop();
    }
    cout << result << endl;
}