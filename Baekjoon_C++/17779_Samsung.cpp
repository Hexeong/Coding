// https://www.acmicpc.net/problem/17779
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N;
int min_v = 10000000;
int people[21][21];
bool visited[21][21];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int divide_area(int x, int y, int d1, int d2) { // y행, x열
    memset(visited, false, sizeof(visited));

    int sum = 0;
    int j = x;
    for (int i = y; i <= y + d1; i++) {
        visited[i][j] = true;
        sum += people[i][j];
        j--;
    }
    j = x + 1;
    for (int i = y + 1; i <= y + d2; i++) { // 2번 경계선
        visited[i][j] = true;
        sum += people[i][j];
        j++;
    }
    j = x - d1 + 1;
    for (int i = y + d1 + 1; i <= y + d1 + d2; i++) { // 3번 경계선
        visited[i][j] = true;
        sum += people[i][j];
        j++;
    }
    j = x + d2 - 1;
    for (int i = y + d2 + 1; i < y + d2 + d1; i++) { // 4번 경계선
        visited[i][j] = true;
        sum += people[i][j];
        j--;
    }

    return sum;
}

int cal_people_sum_by_vote(int x, int y, int d1, int d2, int area5) {
    int cur_min = 1000000;
    int cur_max = 0;

    // 1번
    int sum = 0;
    for (int r = 1; r < y + d1; r++) {
        for (int c = 1; c <= x; c++) {
            if (visited[r][c])
                break;
            sum += people[r][c];
            visited[r][c] = true;
        }
    }
    cur_min = min(cur_min, sum);
    cur_max = max(cur_max, sum);
    // 2번
    sum = 0;
    for (int r = 1; r <= y + d2; r++) {
        for (int c = N; c > x; c--) {
            if (visited[r][c])
                break;
            sum += people[r][c];
            visited[r][c] = true;
        }
    }
    cur_min = min(cur_min, sum);
    cur_max = max(cur_max, sum);
    // 3번
    sum = 0;
    for (int r = y + d1; r <= N; r++) {
        for (int c = 1; c < x - d1 + d2; c++) {
            if (visited[r][c])
                break;
            sum += people[r][c];
            visited[r][c] = true;
        }
    }
    cur_min = min(cur_min, sum);
    cur_max = max(cur_max, sum);
    // 4번
    sum = 0;
    for (int r = y + d2 + 1; r <= N; r++) {
        for (int c = N; c >= x - d1 + d2; c--) {
            if (visited[r][c])
                break;
            sum += people[r][c];
            visited[r][c] = true;
        }
    }
    cur_min = min(cur_min, sum);
    cur_max = max(cur_max, sum);
    // 5번
    for (int r = y; r <= y + d1 + d2; r++) {
        for (int c = x - d1; c <= x + d2; c++) {
            if (!visited[r][c])
                area5 += people[r][c];
        }
    }
    cur_min = min(cur_min, area5);
    cur_max = max(cur_max, area5);

    return cur_max - cur_min;
}

void find_min(int x, int y, int d1, int d2) {
    int area5 = divide_area(x, y, d1, d2);
    min_v = min(min_v, cal_people_sum_by_vote(x, y, d1, d2, area5));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> people[i][j];
        }
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            for (int d1 = 1; d1 < N; d1++) {
                for (int d2 = 1; d2 < N; d2++) {
                    if (y + d1 + d2 > N || x + d2 > N || x - d1 < 1)
                        continue;

                    find_min(x, y, d1, d2);
                }
            }
        }
    }

    cout << min_v << "\n";
}