// https://www.acmicpc.net/problem/17143
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct shark {
    int x;
    int y;
    int size;
    int direction; // 0~3 : 위, 오, 아, 왼
    int speed;
    shark(int _x, int _y, int _size, int _direction, int _speed) :
        x(_x), y(_y), size(_size), direction(_direction), speed(_speed) {}
};

int R, C, M;
shark* space[100][100];
shark* next_space[100][100];
vector<pair<int, int>> sharks_pos;

int dy[] = {-1, 0, 1, 0}; // 위, 오, 아, 왼
int dx[] = {0, 1, 0, -1};
pair<int, int> fishing_king = {1, -1}; // 방향, 위치
int shark_size_sum = 0;

void move_fishing_king() {
    fishing_king.second += fishing_king.first;
}

void fishing() { // space를 기반으로 탐색해야 함
    for (int i = 0; i < R; i++) {
        if (space[i][fishing_king.second] != nullptr) {
            shark_size_sum += space[i][fishing_king.second]->size; // 크기 더하기
            space[i][fishing_king.second] = nullptr; // 공간에서의 정보 지우기
            break;
        }
    }
}

void move_shark() { // 얘는 상어 기준으로 이동해야 함.
    memset(next_space, 0, sizeof(next_space));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (space[i][j] != nullptr)
                sharks_pos.push_back(make_pair(j, i));

    for (int i = 0; i < sharks_pos.size(); i++) {
        shark* shk = space[sharks_pos[i].second][sharks_pos[i].first];
        // 거리 이동 최적화
        int last_dist = shk->speed % (shk->direction % 2 == 0 ? 2 * (R - 1) : 2 * (C - 1));
        while (last_dist > 0) { // 이동하면서 진행
            int ny = shk->y + dy[shk->direction];
            int nx = shk->x + dx[shk->direction];

            if (ny < 0 || ny >= R) {
                ny = shk->y - dy[shk->direction];
                shk->direction = (shk->direction + 2) % 4;
            }
            else if (nx < 0 || nx >= C) {
                nx = shk->x - dx[shk->direction];
                shk->direction = (shk->direction + 2) % 4;
            }

            shk->x = nx;
            shk->y = ny;

            last_dist--;
        }
        // 다음 위치에 상어가 존재하는지 space 확인
        if (next_space[shk->y][shk->x] == nullptr) {
            next_space[shk->y][shk->x] = shk;
        }
        else if (next_space[shk->y][shk->x] != nullptr
            && next_space[shk->y][shk->x]->size < shk->size) {
            // 같은 칸을 사용할 경우 size를 비교하여 사용
            next_space[shk->y][shk->x] = shk;
        }
    }
    // 모든 상어가 이동한 결과에 대해 적용
    sharks_pos.clear();
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            space[i][j] = next_space[i][j];
        }
}

int direction_convert(int d) {
    if (d == 2) return d;
    if (d == 3) return d - 2;
    return d - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> M;
    while (M--) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        space[r - 1][c - 1] = new shark(c - 1, r - 1, z, direction_convert(d), s);
    }

    for (int i = 0; i < C; i++) {
        move_fishing_king();
        fishing();
        move_shark();
    }

    cout << shark_size_sum << "\n";
}