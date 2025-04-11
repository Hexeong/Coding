// https://www.acmicpc.net/problem/17140
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int r, c, k;
int A[100][100];
int num_cnt[101];
int row_max_length = 3;
int col_max_length = 3;

// 5천만 가능
// 100초 * operation(100 * 100)
void operation_R() {
    int cur_row_max = 0;
    for (int i = 0; i < col_max_length; i++) {
        memset(num_cnt, 0, sizeof(num_cnt));
        int j = 0;
        while (j < row_max_length) {
            if (A[i][j] == 0) {
                j++;
                continue;
            };
            num_cnt[A[i][j]]++; // 원소에 대한 개수 파악
            A[i][j] = 0;
            j++;
        }
        vector<vector<int>> num_to_cnt(101);
        // 개수에 대하여 정렬, num_cnt를 작은 것부터 순회하므로 같은 크기에 대해서 작은 숫자부터 vector에 추가된다는 것이 보장됨
        for (int k = 1; k < 101; k++)
            if (num_cnt[k] != 0) {
                num_to_cnt[num_cnt[k]].push_back(k); // 원소가 key값인 상태에서 크기가 key값이 되도록 변환
            }
        j = 0;
        for (int k = 1; k < num_to_cnt.size(); k++) {
            for (int m = 0; m < num_to_cnt[k].size(); m++) { // 정렬된 내용을 원래 2차원 배열에 적용
                if (j == 100) // 크기가 100을 넘어가는 경우는 나머지를 버린다.
                    break;
                A[i][j] = num_to_cnt[k][m]; // 원소
                A[i][j + 1] = k; // 개수
                j += 2;
            }
        }
        cur_row_max = max(cur_row_max, j);
    }
    row_max_length = cur_row_max;
}

void operation_C() {
    int cur_col_max = 0;
    for (int i = 0; i < row_max_length; i++) {
        memset(num_cnt, 0, sizeof(num_cnt));
        int j = 0;
        while (j < col_max_length) {
            if (A[j][i] == 0) {
                j++;
                continue;
            };
            num_cnt[A[j][i]]++; // 원소에 대한 개수 파악
            A[j][i] = 0;
            j++;
        }
        vector<vector<int>> num_to_cnt(101);
        // 개수에 대하여 정렬, num_cnt를 작은 것부터 순회하므로 같은 크기에 대해서 작은 숫자부터 vector에 추가된다는 것이 보장됨
        for (int k = 1; k < 101; k++)
            if (num_cnt[k] != 0) {
                num_to_cnt[num_cnt[k]].push_back(k); // 원소가 key값인 상태에서 크기가 key값이 되도록 변환
            }
        j = 0;
        for (int k = 1; k < 101; k++) { // k < num_to_cnt.size();
            for (int m = 0; m < num_to_cnt[k].size(); m++) { // 정렬된 내용을 원래 2차원 배열에 적용
                if (j == 100) // 100을 넘어가는 경우에는 나머지에 대해서 버리기
                    break;
                A[j][i] = num_to_cnt[k][m]; // 원소
                A[j + 1][i] = k; // 개수
                j += 2;
            }
        }
        cur_col_max = max(cur_col_max, j);
    }
    col_max_length = cur_col_max;
}

void process() {
    int second = 0;
    while (second < 100) {
        if (A[r][c] == k) {
            cout << second << "\n";
            return;
        }

        if (col_max_length >= row_max_length)
            operation_R();
        else
            operation_C();
        second++;
    }

    if (A[r][c] == k)
        cout << second << "\n";
    else
        cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> k;
    r -= 1;
    c -= 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int a; cin >> a;
            A[i][j] = a;
        }

    process();
}
