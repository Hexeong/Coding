//
// Created by admin on 2025-08-19.
//
#include <deque>
#include <iostream>

using namespace std;

typedef pair<int, int> node; // first : value, second : idx

deque<node> dq;

int in[5000001];
int out[5000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, L; cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }

    // deq으로 최솟값이 될 수 있는 것들을 유지하기
    for (int i = 0; i < N; i++) {
        if (dq.front().second < i - L + 1) {
            dq.pop_front();
        }

        if (in[i] >= dq.front().first) {
            // 뒤에 추가
            while (!dq.empty() && in[i] <= dq.back().first)
                dq.pop_back();
            dq.push_back({in[i], i});
        } else {
            while (!dq.empty() && in[i] < dq.front().first)
                dq.pop_front();
            dq.push_front({in[i], i});
        }

        cout << dq.front().first << " ";
    }
}