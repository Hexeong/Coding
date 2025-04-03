// https://www.acmicpc.net/problem/14888
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int number_list[11];
int height = 0;
int operation_cnt[4];
int MIN = 1000000000;
int MAX = -1000000000;

// 제한 시간 2초, 브루트 포스
// for 0 ~ 3, if operation_cnt > 0일 때,
// max, min 비교는 height에 대해 전체 operation을 다 쓴 경우

void process(int v, int depth) {
    if (depth == N) {
        MIN = min(MIN, v);
        MAX = max(MAX, v);
    }

    for (int i = 0; i < 4; i++) {
        operation_cnt[i]--;
        if (i == 0 && operation_cnt[0] > -1)
            process(v + number_list[depth], depth + 1);
        else if (i == 1 && operation_cnt[1] > -1)
            process(v - number_list[depth], depth + 1);
        else if (i == 2 && operation_cnt[2] > -1)
            process(v * number_list[depth], depth + 1);
        else if (i == 3 && operation_cnt[3] > -1)
            process(v / number_list[depth], depth + 1);
        operation_cnt[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> number_list[i];
    for (int i = 0; i < 4; i++)
        cin >> operation_cnt[i];

    int default_v = number_list[0];
    process(default_v, 1);

    cout << MAX << "\n" << MIN << "\n";
}