#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long max_v = 0;
long long paper[500][500];
long long area_sum[500][500];

void cal_max_1() { // 네 개 연달아 있는 모양에 대한 영역합 최대 계산
    for (int i = 0; i < N; i++) // 가로로 놓여진 블록
        for (int j = 3; j < M; j++)
            max_v = max(max_v, paper[i][j] + paper[i][j - 1]
                    + paper[i][j - 2] + paper[i][j - 3]);

    for (int i = 3; i < N; i++) // 세로로 놓여진 블록
        for (int j = 0; j < M; j++)
            max_v = max(max_v, paper[i][j] + paper[i - 1][j]
                    + paper[i - 2][j] + paper[i - 3][j]);
}

void cal_max_2() { // 2 X 2 모양에 대한 영역합 최대 계산
    for (int i = 1; i < N; i++)
        for (int j = 1; j < M; j++)
            max_v = max(max_v, paper[i][j] + paper[i - 1][j]
                    + paper[i][j - 1] + paper[i - 1][j - 1]);
}

void cal_max_3() { // 산 모양에 대한 영역합 최대 계산
    for (int i = 1; i < N; i++) // 2 X 3 모양
        for (int j = 2; j < M; j++) {
            max_v = max(max_v, paper[i][j] + paper[i][j - 1]
                    + paper[i][j - 2] + paper[i - 1][j - 1]);

            max_v = max(max_v, paper[i - 1][j] + paper[i - 1][j - 1]
                    + paper[i - 1][j - 2] + paper[i][j - 1]);
        }

    for (int i = 2; i < N; i++) // 3 X 2 모양
        for (int j = 1; j < M; j++) {
            max_v = max(max_v, paper[i][j] + paper[i - 1][j]
                    + paper[i - 2][j] + paper[i - 1][j - 1]);

            max_v = max(max_v, paper[i][j - 1] + paper[i - 1][j - 1]
                    + paper[i - 1][j] + paper[i - 2][j - 1]);
        }
}

void cal_max_4() { // L 모양에 대한 영역합 최대 계산
    for (int i = 1; i < N; i++) // 2 X 3 모양
        for (int j = 2; j < M; j++) {
            max_v = max(max_v, paper[i][j] + paper[i][j - 1]
                    + paper[i][j - 2] + paper[i - 1][j]);

            max_v = max(max_v, paper[i - 1][j] + paper[i - 1][j - 1]
                    + paper[i - 1][j - 2] + paper[i][j]);

            max_v = max(max_v, paper[i][j] + paper[i][j - 1]
                    + paper[i][j - 2] + paper[i - 1][j - 2]);

            max_v = max(max_v, paper[i - 1][j] + paper[i - 1][j - 1]
                    + paper[i - 1][j - 2] + paper[i][j - 2]);
        }

    for (int i = 2; i < N; i++) // 3 X 2 모양
        for (int j = 1; j < M; j++) {
            max_v = max(max_v, paper[i][j] + paper[i - 1][j]
                    + paper[i - 2][j] + paper[i][j - 1]);

            max_v = max(max_v, paper[i][j - 1] + paper[i - 1][j - 1]
                    + paper[i - 2][j - 1] + paper[i][j]);

            max_v = max(max_v, paper[i][j] + paper[i - 1][j]
                    + paper[i - 2][j] + paper[i - 2][j - 1]);

            max_v = max(max_v, paper[i][j - 1] + paper[i - 1][j - 1]
                    + paper[i - 2][j - 1] + paper[i - 2][j]);
        }
}

void cal_max_5() { // 번개 모양에 대한 영역합 최대 계산
    for (int i = 1; i < N; i++) // 2 X 3 모양, 해야 함
        for (int j = 2; j < M; j++) {
            max_v = max(max_v, paper[i][j] + paper[i][j - 1]
                    + paper[i - 1][j - 1] + paper[i - 1][j - 2]);

            max_v = max(max_v, paper[i - 1][j] + paper[i - 1][j - 1]
                    + paper[i][j - 1] + paper[i][j - 2]);
        }

    for (int i = 2; i < N; i++) // 3 X 2 모양
        for (int j = 1; j < M; j++) {
            max_v = max(max_v, paper[i][j] + paper[i - 1][j]
                    + paper[i - 1][j - 1] + paper[i - 2][j - 1]);

            max_v = max(max_v, paper[i][j - 1] + paper[i - 1][j - 1]
                    + paper[i - 1][j] + paper[i - 2][j]);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> paper[i][j];

    // 영역합 계산을 위한 밑 작업
    // 할필요 없음 영역 크기가 4칸으로 그때그때 더하는 것과 별 다를 바가 없음
    // area_sum[0][0] = paper[0][0];
    // for (int i = 1; i < N; i++) {
    //     area_sum[i][0] = paper[i][0] + paper[i - 1][0];
    //     area_sum[0][i] = paper[0][i] + paper[0][i - 1];
    // }
    // for (int i = 1; i < N; i++)
    //     for (int j = 1; j < M; j++)
    //         area_sum[i][j] = paper[i][j] + paper[i - 1][j] + paper[i][j - 1] - paper[i - 1][j - 1];

    cal_max_1();
    cal_max_2();
    cal_max_3();
    cal_max_4();
    cal_max_5();

    cout << max_v << "\n";

    return 0;
}