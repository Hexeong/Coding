//
// Created by admin on 2025-07-29.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    stack<int> s;
    vector<int> input(n);
    vector<char> output;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    int cur = 1;

    for (auto in : input) {
        while ((!s.empty() && in > s.top()) || in >= cur) {
            s.push(cur++);
            output.push_back('+');
        }

        if (s.empty() || in < s.top()) {
            cout << "NO\n";
            return 0;
        }

        // in == s.top()이 같은 경우에만 여기에 도달
        s.pop();
        output.push_back('-');
    }

    for (auto c : output)
        cout << c << '\n';
}