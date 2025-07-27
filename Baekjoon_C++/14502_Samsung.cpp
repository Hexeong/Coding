#include <iostream>
#include <queue>

using namespace std;

// 남은 영역 계산 시, BFS 사용
// for문 3번, i, j, k가 위치, 최대 63
// k가 다 이동하면, j가 다 이동하고
// 했을 때 2를 중심으로 BFS 돌리기
// 정적으로 visit[8][8] 생성

// 계산 i, j, k에 대해서 64 * 64 * 64 = 대략 343000, 343000 * (64 + 64 + 64) = 대략 72,030,000
// 러프하게 계산했는데도 2억이 넘지 않으므로 도전

int N, M;
int default_safe_area = 0;
int max_safe_area = 0;
int map[8][8]; // 0은 빈 칸, 1은 벽, 2는 바이러스
vector<pair<int, int>> virus_pos;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int BFS(pair<int, int> init_pos, bool visit[8][8]) {
    if (visit[init_pos.second][init_pos.first])
        return 0;

    int virus_area = 0;
    queue<pair<int, int>> q;
    q.push(init_pos);
    visit[init_pos.second][init_pos.first] = true;
    virus_area++;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (p.second + dy[i] < 0 || p.second + dy[i] >= N) continue;
            if (p.first + dx[i] < 0 || p.first + dx[i] >= M) continue;
            // 방문하지 않았고, 바이러스가 퍼지지 않은 곳만 이동
            if (!visit[p.second + dy[i]][p.first + dx[i]] && map[p.second + dy[i]][p.first + dx[i]] == 0) {
                q.push(make_pair(p.first + dx[i], p.second + dy[i]));
                visit[p.second + dy[i]][p.first + dx[i]] = true;
                virus_area++;
            }
        }
    }

    return virus_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] != 1)
                default_safe_area++;
            if (map[i][j] == 2)
                virus_pos.push_back(make_pair(j, i));
        }

    for (int i = 0; i< N * M; i++) {
        if (map[i / M][i % M] != 0) // 빈칸이 아니면 벽을 세울 수 없기에 pass
            continue;
        // 벽 세우기
        pair<int, int> w1 = make_pair(i % M, i / M);
        map[w1.second][w1.first] = 1;
        for (int j = i + 1; j < N * M; j++) {
            if (map[j / M][j % M] != 0) // 빈칸이 아니면 벽을 세울 수 없기에 pass
                continue;
            // 벽 세우기
            pair<int, int> w2 = make_pair(j % M, j / M);
            map[w2.second][w2.first] = 1;
            for (int k = j + 1; k < N * M; k++) {
                if (map[k / M][k % M] != 0) // 빈칸이 아니면 벽을 세울 수 없기에 pass
                    continue;
                // 벽 세우기
                pair<int, int> w3 = make_pair(k % M, k / M);
                map[w3.second][w3.first] = 1;

                int total = 0;
                bool visit[8][8] = { false };
                for (int a = 0; a < virus_pos.size(); a++)
                    total += BFS(virus_pos[a], visit);

                max_safe_area = max(max_safe_area, default_safe_area - total - 3);

                // 벽 허물기
                map[w3.second][w3.first] = 0;
            }
            // 벽 허물기
            map[w2.second][w2.first] = 0;
        }
        // 벽 허물기
        map[w1.second][w1.first] = 0;
    }

    cout << max_safe_area << "\n";

    return 0;
}