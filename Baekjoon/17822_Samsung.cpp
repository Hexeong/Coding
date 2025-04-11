// https://www.acmicpc.net/problem/17822
#include <iostream>
#include <vector>

using namespace std;

int N, M, T;
vector<pair<int, bool>> circle[51]; // 원판
int north[50]; // 각 원판마다 북쪽을 가리키는 수

void rotate(int idx, int direction, int k) {
    if (direction == 0) // 시계 방향, north point를 - 방향으로 이동
        north[idx] = (north[idx] + M - k) % M;
    else // 반시계 방향, north point를 + 방향으로 이동
        north[idx] = (north[idx] + k) % M;
}

void erase_adjacent() {
    int sum = 0;
    int cnt = 0;
    bool flag = true; // 인접한 수가 있어 지운 경우에 대한 flag
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (circle[i][(north[i] + j) % M].first != -1) { // 완전히 지운 칸이 아닐 때
                int cur_v = circle[i][(north[i] + j) % M].first;

                // flag 처리를 위한 sum 구하기
                sum += cur_v;
                cnt++;
                // 현재와 인접한 것들에 대해 확인
                if (cur_v == circle[i + 1][(north[i + 1] + j) % M].first) { // i, j와 i + 1, j 비교
                    flag = false;
                    circle[i + 1][(north[i + 1] + j) % M].second = false;
                    circle[i][(north[i] + j) % M].second = false;
                }
                if (cur_v == circle[i][(north[i] + j + 1) % M].first) { // i, j와 i, j + 1 비교
                    flag = false;
                    circle[i][(north[i] + j + 1) % M].second = false;
                    circle[i][(north[i] + j) % M].second = false;
                }
                if (cur_v == circle[i][(north[i] + j + M - 1) % M].first) { // i, j와 i, j - 1 비교
                    flag = false;
                    circle[i][(north[i] + j + M - 1) % M].second = false;
                    circle[i][(north[i] + j) % M].second = false;
                }
            }
        }
    }
    for (int j = 0; j < M; j++) {
        if (circle[N][(north[N] + j) % M].first != -1) { // 완전히 지운 칸이 아닐 때
            int cur_v = circle[N][(north[N] + j) % M].first;

            // flag 처리를 위한 sum 구하기
            sum += cur_v;
            cnt++;
            // 현재와 인접한 것들에 대해 확인
            if (cur_v == circle[N][(north[N] + j + 1) % M].first) { // i, j와 i, j + 1 비교
                flag = false;
                circle[N][(north[N] + j + 1) % M].second = false;
                circle[N][(north[N] + j) % M].second = false;
            }
            if (cur_v == circle[N][(north[N] + j + M - 1) % M].first) { // i, j와 i, j - 1 비교
                flag = false;
                circle[N][(north[N] + j + M - 1) % M].second = false;
                circle[N][(north[N] + j) % M].second = false;
            }
        }
    }

    // flag == true일 때의 처리, 즉 인접한 값이 아예 없을 때
    if (flag) {
        double mean = (double)sum / cnt;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (circle[i][(north[i] + j) % M].first != -1) { // 지운 칸이 아닐 때
                    if (mean < (double)circle[i][(north[i] + j) % M].first) {
                        circle[i][(north[i] + j) % M].first--;
                    }
                    else if (mean > (double)circle[i][(north[i] + j) % M].first) {
                        circle[i][(north[i] + j) % M].first++;
                    }
                }
            }
        }
    }
    else {
        // false로 마킹해 놓은 값들 -1로 first 바꾸기
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (!circle[i][j].second) { // false로 마킹해 놓은 값들
                    circle[i][j].first = -1;
                }
            }
        }
    }
}

void process(int x, int d, int k) {
    for (int i = 1; i <= N; i++) {
        if (i % x == 0) { // i가 x의 배수일 때
            rotate(i, d, k);
        }
    }
    erase_adjacent();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            int a; cin >> a;
            circle[i].push_back({a, true}); // 값과 생존 여부
        }
    }

    for (int i = 0; i < T; i++) {
        int x, d, k;
        cin >> x >> d >> k;
        process(x, d, k);
    }

    // 원판에 적힌 수의 합 구하기
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (circle[i][(north[i] + j) % M].first != -1) {
                sum += circle[i][(north[i] + j) % M].first;
            }
        }
    }

    cout << sum << endl;
}