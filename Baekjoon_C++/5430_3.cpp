//
// Created by admin on 2025-08-19.
//
#include <iostream>
#include <queue>

using namespace std;

deque<int> dq;
bool flag = false;
bool err = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        dq.clear();
        flag = false;
        err = false;

        string command; cin >> command;
        int n; cin >> n;

        string elem; cin >> elem;
        elem = elem.substr(1, elem.size() - 2);

        if (!elem.empty()) {
            size_t start = 0; size_t end;
            while ((end = elem.find(',', start)) != string::npos) {
                dq.push_back(stoi(elem.substr(start, end - start)));
                start = end + 1;
            }
            dq.push_back(stoi(elem.substr(start)));
        }

        for (auto c : command) {
            if (c == 'R') {
                flag = !flag;
            } else {
                if (dq.empty()) {
                    err = true;
                    break;
                }

                if (flag)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (err) {
            cout << "error\n";
            continue;
        }

        cout << "[";
        if (!dq.empty()) {
            cout << (flag ? dq.back() : dq.front());
            if (flag)
                for (int i = (int)dq.size() - 2; i > -1; i--)
                    cout << "," << dq[i];
            else
                for (int i = 1; i < dq.size(); i++)
                    cout << "," << dq[i];
        }
        cout << "]\n";
    }
}