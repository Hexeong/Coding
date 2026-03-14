//
// Created by admin on 2025-07-30.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct person {
    int height;
    int duplicated_cnt;
    person() : height(0), duplicated_cnt(1) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<person> people(N);
    for (int i = 0; i < N; i++)
        cin >> people[i].height;

    long long result = 0;
    stack<person> stk;

    // testcase :
    // 3 2 1 4 5
    // 3 3 1 5 5
    // 3 4 4 3 1
    // 반례 : 7 6 6 5 5 3 3 6
    stk.push(people[0]);
    for (int i = 1; i < N; i++) {
        while (!stk.empty() && stk.top().height < people[i].height) {
            result += stk.top().duplicated_cnt;
            stk.pop();
        }
        if (!stk.empty()) {
            if (stk.top().height == people[i].height) {
                result += stk.top().duplicated_cnt;
                if (stk.size() > 1)
                    result++;

                stk.top().duplicated_cnt++;
            }
            else
                result++;
        }

        if (stk.empty() || stk.top().height != people[i].height)
            stk.push(people[i]);
    }

    cout << result << endl;
}