// https://www.acmicpc.net/problem/14890
#include <iostream>
#include <cmath>

using namespace std;

int N, L;
int map[100][100];
int road_cnt = 0;

int dy[] = {-1, 0, 1, 0}; // 북, 동, 남, 서
int dx[] = {0, 1, 0, -1};

// 2초, 100크기, 브루트 포스

void process_col(int col_i) {
    bool isSettled[100] = { false };
    for (int i = 1; i < L; i++) {
        if (map[i][col_i] == map[i - 1][col_i] + 1) // 오르막길 경사로를 놓는 상황
            return;
        if (map[i][col_i] + 1 == map[i - 1][col_i]) { // 내리막길 경사로를 놓는 상황
            if (i + L > N) // 놓을 때 놓을 공간이 없는 경우
                return;

            for (int j = i; j < i + L; j++) {
                if (map[j][col_i] != map[i][col_i] // 낮은 지점의 칸의 높이가 모두 연속되게 같이 않을 경우
                    || isSettled[j]) // 이미 놓았거나
                        return;
                isSettled[j] = true;
            }
        }
        else if (abs(map[i][col_i] - map[i - 1][col_i]) > 1) // 낮은 칸과 높은 칸의 높이 차이가 1이 아닐때
            return;
    }
    for (int i = L; i < N; i++) {
        if (map[i][col_i] == map[i - 1][col_i] + 1) { // 오르막길 경사로를 놓는 상황
            // 올라가는 상황
            // 경사로를 놓을 수 있을 때 놓기
            // 놓을 수 없으면 return;
            if (i - L < 0) // 놓을 때 놓을 공간이 없는 경우
                return;

            for (int j = i - 1; j >= i - L; j--) {
                if (map[j][col_i] != map[i - 1][col_i] // 낮은 지점의 칸의 높이가 모두 연속되게 같이 않을 경우
                    || isSettled[j]) // 이미 놓았거나
                    return;
                isSettled[j] = true;
            }
        }
        else if (map[i][col_i] + 1 == map[i - 1][col_i]) { // 내리막길 경사로를 놓는 상황
            // 내려가는 상황
            // 경사로를 놓을 수 있을 때 놓기
            // 놓을 수 없으면 return;
            if (i + L > N) // 놓을 때 놓을 공간이 없는 경우
                return;

            for (int j = i; j < i + L; j++) {
                if (map[j][col_i] != map[i][col_i] // 낮은 지점의 칸의 높이가 모두 연속되게 같이 않을 경우
                    || isSettled[j]) // 이미 놓았거나
                        return;
                isSettled[j] = true;
            }
        }
        else if (abs(map[i][col_i] - map[i - 1][col_i]) > 1) // 낮은 칸과 높은 칸의 높이 차이가 1이 아닐때
            return;

        // if문을 모두 통과한 경우 정상적인 경사로를 두었거나, 같은 높이인 것이다.
    }
    road_cnt++;
}

void process_row(int row_i) {
    bool isSettled[100] = { false };
    for (int i = 1; i < L; i++) {
        if (map[row_i][i] == map[row_i][i - 1] + 1)
            return;
        if (map[row_i][i] + 1 == map[row_i][i - 1]) {
            if (i + L > N) // 놓을 때 놓을 공간이 없는 경우
                return;

            for (int j = i; j < i + L; j++) {
                if (map[row_i][j] != map[row_i][i] // 낮은 지점의 칸의 높이가 모두 연속되게 같이 않을 경우
                    || isSettled[j]) // 이미 놓았거나
                        return;
                isSettled[j] = true;
            }
        }
        else if (abs(map[row_i][i] - map[row_i][i - 1]) > 1) // 낮은 칸과 높은 칸의 높이 차이가 1이 아닐때
            return;
    }

    for (int i = L; i < N; i++) {
        if (map[row_i][i] == map[row_i][i - 1] + 1) { // 오르막길 경사로를 놓는 상황
            // 올라가는 상황
            // 경사로를 놓을 수 있을 때 놓기
            // 놓을 수 없으면 return;
            if (i - L < 0) // 놓을 때 놓을 공간이 없는 경우
                return;

            for (int j = i - 1; j >= i - L; j--) {
                if (map[row_i][j] != map[row_i][i - 1] // 낮은 지점의 칸의 높이가 모두 연속되게 같이 않을 경우
                    || isSettled[j]) // 이미 놓았거나
                        return;
                isSettled[j] = true;
            }
        }
        else if (map[row_i][i] + 1 == map[row_i][i - 1]) { // 내리막길 경사로를 놓는 상황
            // 내려가는 상황
            // 경사로를 놓을 수 있을 때 놓기
            // 놓을 수 없으면 return;
            if (i + L > N) // 놓을 때 놓을 공간이 없는 경우
                return;

            for (int j = i; j < i + L; j++) {
                if (map[row_i][j] != map[row_i][i] // 낮은 지점의 칸의 높이가 모두 연속되게 같이 않을 경우
                    || isSettled[j]) // 이미 놓았거나
                        return;
                isSettled[j] = true;
            }
        }
        else if (abs(map[row_i][i] - map[row_i][i - 1]) > 1) // 낮은 칸과 높은 칸의 높이 차이가 1이 아닐때
            return;

        // if문을 모두 통과한 경우 정상적인 경사로를 두었거나, 같은 높이인 것이다.
    }

    road_cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++) {
        process_col(i);
        process_row(i);
    }

    cout << road_cnt << "\n";

    return 0;
}