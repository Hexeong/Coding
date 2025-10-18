//
// Created by hex on 25. 10. 18..
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
        string s; cin >> s;
        stack<char> st;

        bool flag = false;
        for (const auto& c : s) {
            if (c == '[')
                flag = true;
            else if (c == ']') {
                flag = false;
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
            }
            else if (flag)
                st.push(c);
            else
                cout << c;
        }
        if (flag)
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }

        cout << '\n';
    }
}