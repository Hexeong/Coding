//
// Created by admin on 2025-08-23.
//
#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s;
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '(') {
            stk.push(-1);
            i++;
        } else if (s[i] == '[') {
            stk.push(-2);
            i++;
        } else {

            int temp = 0;
            // + 관계에 대해서 생각 : 2 12 9 가 저장된 상태로 ( 12 + 9 ) * 2를 해야 함
            while (!stk.empty() && stk.top() != -1 && stk.top() != -2) {
                temp += stk.top();
                stk.pop();
            }
            if (temp == 0)
                temp = 1;

            bool flag = false;
            while (i < s.length() && (s[i] == ')' || s[i] == ']') // 닫는 괄호이고
                && !stk.empty() && (stk.top() == -1 || stk.top() == -2)) { // stk.top()이 여는 괄호인 경우

                // 닫는 괄호가 올바르지 못하게 매칭된 경우도 중단
                if ((s[i] == ')' && stk.top() != -1) || (s[i] == ']' && stk.top() != -2)) {
                    flag = true;
                    break;
                }
                temp *= (stk.top() == -1 ? 2 : 3);
                stk.pop();
                i++;
            }

            // stk가 비어있는데 닫는 대/소괄호가 남아있으면 올바르지 못한 입력
            if (flag || (stk.empty() && i < s.length() && (s[i] == ')' || s[i] == ']'))) {
                cout << "0\n";
                return 0;
            }

            stk.push(temp);
        }
    }

    int result = 0;
    while (!stk.empty()) {
        if (stk.top() < 0) { // 매칭되지 못한 애들이 남은 상황
            cout << "0\n";
            return 0;
        }

        result += stk.top();
        stk.pop();
    }

    cout << result << "\n";
}