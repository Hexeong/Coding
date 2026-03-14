#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string command; cin >> command;
        int n; cin >> n;
        string element; cin >> element;

        // 문자열 쪼개기
        vector<string> elements;
        size_t start = 0;
        size_t end;
        if (n != 0) {
            while ((end = element.find(',', start)) != string::npos) {
                elements.push_back(element.substr(start, end - start));
                start = end + 1;
            }
            elements.push_back(element.substr(start));

            elements[0] = elements[0].substr(1, element.size() - 1); // 첫번째 원소의 대괄호 제거
            elements[elements.size() - 1] = elements[elements.size() - 1].substr(0, elements[elements.size() - 1].size() - 1); // 두번째 원소의 대괄호 제거
        }

        vector<int> stk[2];
        int dir = 1;
        bool flag = false;

        for (int i = 0; i < n; i++) {
            stk[0].push_back(i); // 0,1,2... - 역방향 제거
            stk[1].push_back(n - i - 1); // n, n-1, n-2... - 순방향 제거
        }

        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'R') {
                dir = dir == 1 ? 0 : 1;
            } else if (command[i] == 'D') {
                if (stk[0].size() + stk[1].size() == elements.size()) {
                    cout << "error" << endl;
                    flag = true;
                    break;
                }

                stk[dir].pop_back();
            }
        }
        if (flag)
            continue;

        if (dir == 1) {
            cout << '[';
            if (!stk[0].empty() && !stk[1].empty()) {
                for (int i = stk[1].back(); i < stk[0].back(); i++)
                    cout << elements[i] << ',';
                cout << elements[stk[0].back()];
            }
            cout << ']' << endl;
        } else {
            cout << '[';
            if (!stk[0].empty() && !stk[1].empty()) {
                for (int i = stk[0].back(); i > stk[1].back(); i--)
                    cout << elements[i] << ',';
                cout << elements[stk[1].back()];
            }
            cout << ']' << endl;
        }

    }
}