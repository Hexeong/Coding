//
// Created by admin on 2025-07-10.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<char> left;
    stack<char> right;

    int T; cin >> T;
    while(T--) {
      string s; cin >> s;
      for (char c : s) {
        if (c == '<') {
          if (!left.empty()) {
            right.push(left.top());
            left.pop();
          }
        } else if (c == '>') {
          if (!right.empty()) {
            left.push(right.top());
            right.pop();
          }
        } else if (c == '-') {
          if (!left.empty()) {
            left.pop();
          }
        } else
          left.push(c);
      }

      while(!left.empty()) {
        right.push(left.top());
        left.pop();
      }

      while(!right.empty()) {
        cout << right.top();
        right.pop();
      }
      cout << endl;
    }
}