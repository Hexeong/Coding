// https://www.acmicpc.net/problem/15683
#include <iostream>

using namespace std;

int N, M;
int cctv_cnt = 0;
int wall_cnt = 0;
int min_area = 64; // 최대 사각지대 영역은 64이므로
pair<int, int> cctv_pos[8];
int map[8][8];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// 브루트 포스? CCTV가 배치되는 방향의 모든 경우의 수 = 4^8 = 65536
// CCTV 영역 계산 후, 사각지대 계산 = N * M = 64
// 총 계산 = 65536 * 64 = 대략 4,500,000, 1억 보다 낮기에 가능성 있음

void calculate(int cctv_direction[8]) {

    bool isChecked[8][8] = { false };
    // CCTV에 의해 보이는 곳 표시

    for (int i = 0; i < cctv_cnt; i++) {
        // 바라보는 방향 표시
        pair<int, int> cur_pos = cctv_pos[i];
        while (cur_pos.second > -1 && cur_pos.first > -1
            && cur_pos.second < N && cur_pos.first < M) {

            if (map[cur_pos.second][cur_pos.first] == 6)
                break;
            isChecked[cur_pos.second][cur_pos.first] = true;
            cur_pos.second += dy[cctv_direction[i]];
            cur_pos.first += dx[cctv_direction[i]];
        }
        if (map[cctv_pos[i].second][cctv_pos[i].first] == 2
            || map[cctv_pos[i].second][cctv_pos[i].first] == 5) { // 2번, 5번일 경우
            // 반대 방향에 대한 표시
            cur_pos = cctv_pos[i];
            while (cur_pos.second > -1 && cur_pos.first > -1
                && cur_pos.second < N && cur_pos.first < M) {

                if (map[cur_pos.second][cur_pos.first] == 6)
                    break;
                isChecked[cur_pos.second][cur_pos.first] = true;
                cur_pos.second -= dy[cctv_direction[i]];
                cur_pos.first -= dx[cctv_direction[i]];
            }
        }
        if (map[cctv_pos[i].second][cctv_pos[i].first] == 3
            || map[cctv_pos[i].second][cctv_pos[i].first] == 4
            || map[cctv_pos[i].second][cctv_pos[i].first] == 5) { // 3번, 4번, 5번일 경우
            // 오른쪽 방향에 대한 표시
            cur_pos = cctv_pos[i];
            while (cur_pos.second > -1 && cur_pos.first > -1
                && cur_pos.second < N && cur_pos.first < M) {

                if (map[cur_pos.second][cur_pos.first] == 6)
                    break;
                isChecked[cur_pos.second][cur_pos.first] = true;
                cur_pos.second += dy[(cctv_direction[i] + 1) % 4];
                cur_pos.first += dx[(cctv_direction[i] + 1) % 4];
            }
        }
        if (map[cctv_pos[i].second][cctv_pos[i].first] == 4
            || map[cctv_pos[i].second][cctv_pos[i].first] == 5) { // 4번, 5번일 경우
            // 왼쪽 방향에 대한 표시
            cur_pos = cctv_pos[i];
            while (cur_pos.second > -1 && cur_pos.first > -1
                && cur_pos.second < N && cur_pos.first < M) {

                if (map[cur_pos.second][cur_pos.first] == 6)
                    break;
                isChecked[cur_pos.second][cur_pos.first] = true;
                cur_pos.second += dy[(cctv_direction[i] + 3) % 4];
                cur_pos.first += dx[(cctv_direction[i] + 3) % 4];
            }
        }
    }

    // 벽, CCTV, CCTV가 감시하는 영역 모두 true로 표시됨
    int area = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!isChecked[i][j])
                area++;

    min_area = min(area - wall_cnt, min_area);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 6)
                wall_cnt++;
            else if (map[i][j] > 0 && map[i][j] < 6) {
                cctv_pos[cctv_cnt].second = i;
                cctv_pos[cctv_cnt].first = j;
                cctv_cnt++;
            }
        }

    int cctv_direction[8] = {0};
    int depth = 0;

    while (depth >= 0) {
        if (depth == cctv_cnt) {
            // 루프 끝까지 도달했을 때: 작업 수행
            calculate(cctv_direction);

            depth--; // 위로 올라가서 다음 값을 처리
            cctv_direction[depth]++;
        } else if (cctv_direction[depth] < 4) {
            // 아직 현재 depth에서 반복 가능하면 다음 depth로 진행
            depth++;
            if (depth < cctv_cnt)
                cctv_direction[depth] = 0; // 새 depth 진입 시 초기화
        } else {
            // 현재 depth에서 범위를 넘은 경우: 한 단계 위로 가서 다음 반복
            cctv_direction[depth] = 0; // 현재 depth 초기화
            depth--;
            if (depth >= 0)
                cctv_direction[depth]++;
        }
    }

    cout << min_area << "\n";
}