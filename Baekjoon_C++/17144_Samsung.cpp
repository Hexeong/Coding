// https://www.acmicpc.net/problem/17144
#include <iostream>
#include <vector>

using namespace std;

int R, C;
pair<int, int> cleaner_pos;
int space[50][50];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void diffusion_dust(const pair<int, int>& pos, int next_space[50][50]) {
    int diffusion_cnt = 0;
    for (int i = 0; i < 4; i++) {
        int ny = pos.second + dy[i];
        int nx = pos.first + dx[i];

        if ((cleaner_pos.first == nx && cleaner_pos.second == ny)
            || (cleaner_pos.first == nx && cleaner_pos.second - 1 == ny)
            || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

        diffusion_cnt++;
        next_space[ny][nx] += space[pos.second][pos.first] / 5;
    }
    space[pos.second][pos.first] -= (diffusion_cnt * (space[pos.second][pos.first] / 5));
}

void process_cleaner() {
    // 정화 시작
    // 위쪽 공기청정기의 반시계 방향 바람으로 인한 미세먼지 이동
    for (int i = cleaner_pos.second - 2; i >= 1; i--)
        space[i][0] = space[i - 1][0];
    for (int i = 0; i < C - 1; i++)
        space[0][i] = space[0][i + 1];
    for (int i = 0; i < cleaner_pos.second - 1; i++)
        space[i][C - 1] = space[i + 1][C - 1];
    for (int i = C - 1; i > 1; i--)
        space[cleaner_pos.second - 1][i] = space[cleaner_pos.second - 1][i - 1];
    space[cleaner_pos.second - 1][cleaner_pos.first + 1] = 0;

    // 아래쪽 공기청정기의 시계 방향 바람으로 인한 미세먼지 이동
    for (int i = cleaner_pos.second + 1; i < R; i++)
        space[i][0] = space[i + 1][0];
    for (int i = 0; i < C - 1; i++)
        space[R - 1][i] = space[R - 1][i + 1];
    for (int i = R - 1; i > cleaner_pos.second; i--)
        space[i][C - 1] = space[i - 1][C - 1];
    for (int i = C - 1; i > 1; i--)
        space[cleaner_pos.second][i] = space[cleaner_pos.second][i - 1];
    space[cleaner_pos.second][cleaner_pos.first + 1] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> space[i][j];
            if (space[i][j] == -1)
                cleaner_pos = {j, i};
        }

    while (T > 0) {
        // 동시에 일어나기에 확산된 미세먼지는 계산에 영향을 주면 안되기에 나중에 한번에 더해져야 함.
        int next_space[50][50] = { 0 };
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (space[i][j] != -1 && space[i][j] != 0)
                    diffusion_dust({j, i}, next_space);
        // 확산된 미세먼지 적용
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                space[i][j] += next_space[i][j];

        process_cleaner();
        T--;
    }

    int dust_sum = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (space[i][j] != -1)
                dust_sum += space[i][j];
        }

    cout << dust_sum << "\n";
}