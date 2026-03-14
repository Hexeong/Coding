// https://www.acmicpc.net/problem/15684
#include <iostream>
#include <vector>

using namespace std;

// 2초, 브루트포스
// 270 * 269 * 268 = 대략 2천만, 2억을 넘지 않기에 가능한 것으로 보임

int N, M, H;
int ladder[30][10]; // 사다리가 없을 때는 0, 사다리가 있을 떄는 어떤 col로 이동하는지 col을 저장
int min_v = 4; // 가로선 개수의 최댓값은 3이므로

// 오류 발생, verify과정까지 합치면 2천만 * 270 = 거의 5억이 넘어가므로 불가능해짐
// 새로운 idea, 필수적으로 각 col에 대해서 연결된 사다리의 개수는 짝수 개여야 한다.
// 이 특성을 활용해보자
// 오류 발생, 해당 특성으로 i가 i에 도착한다는 게 보장이 안됨, 즉 홀수개 연결되어 있어도 가능
// 반례 :
// 3 3 6
// 1 1
// 2 2
// 3 1
// 4 2
// 이 경우, 5 1과 6 2를 추가하여 문제를 해결할 수 있음
// 하지만 위의 아이디어로는 해를 구할 수 없기에 잘못된 방법임
// 즉 문제의 해가 탐색 범위에 포함되지 않을 수 있으므로 불가능함
bool verify() {
    for (int i = 0; i < N; i++) {
        int cur_col = i;
        for (int j = 0; j < H; j++) {
            // ladder값이 0이면 사다리가 없으니 기존값 유지, 있으면 사다리가 있으므로 해당 col로 이동
            cur_col = (ladder[j][cur_col] == 0 ? cur_col : ladder[j][cur_col] - 1);
        }
        if (i != cur_col)
            return false;
    }
    return true;
}

void calculate(int depth, int row, int col) {
    if (depth >= min_v) return;

    if (verify()) {
        min_v = depth;
        return;
    }

    if (depth == 3) return;

    for (int j = row; j < H; j++) {
        for (int i = (j == row ? col : 0); i < N - 1; i++) {
            if (ladder[j][i] == 0 && ladder[j][i + 1] == 0) {
                ladder[j][i] = i + 2;
                ladder[j][i + 1] = i + 1;

                calculate(depth + 1, j, i + 2);

                ladder[j][i] = 0;
                ladder[j][i + 1] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int req_cnt[10] = { 0 };
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a - 1][b - 1] = b + 1;
        ladder[a - 1][b] = b;
        req_cnt[b - 1]++;
    }

    calculate(0, 0, 0);

    if (min_v == 4)
        cout << -1 << "\n";
    else
        cout << min_v << "\n";
}