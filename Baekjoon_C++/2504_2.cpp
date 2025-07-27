#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    stack<int> stk;
    bool isValid = true;

    for (char ch : str) {
        if (ch == '(') {
            stk.push(-1); // '('을 -1로 표현
        } else if (ch == '[') {
            stk.push(-2); // '['을 -2로 표현
        } else if (ch == ')') {
            if (stk.empty()) {
                isValid = false;
                break;
            }
            int sum = 0;
            while (!stk.empty() && stk.top() != -1) {
                if (stk.top() < 0) {
                    isValid = false;
                    break;
                }
                sum += stk.top();
                stk.pop();
            }
            if (!isValid || stk.empty() || stk.top() != -1) {
                isValid = false;
                break;
            }
            stk.pop(); // '(' 제거
            stk.push(sum == 0 ? 2 : sum * 2); // () → 2, (x) → x*2
        } else if (ch == ']') {
            if (stk.empty()) {
                isValid = false;
                break;
            }
            int sum = 0;
            while (!stk.empty() && stk.top() != -2) {
                if (stk.top() < 0) {
                    isValid = false;
                    break;
                }
                sum += stk.top();
                stk.pop();
            }
            if (!isValid || stk.empty() || stk.top() != -2) {
                isValid = false;
                break;
            }
            stk.pop(); // '[' 제거
            stk.push(sum == 0 ? 3 : sum * 3); // [] → 3, [x] → x*3
        }
    }

    if (!isValid) {
        cout << 0 << '\n';
    } else {
        int result = 0;
        while (!stk.empty()) {
            if (stk.top() < 0) {
                isValid = false;
                break;
            }
            result += stk.top();
            stk.pop();
        }
        cout << (isValid ? result : 0) << '\n';
    }
    return 0;
}