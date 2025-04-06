// https://www.acmicpc.net/problem/15685
#include <iostream>
#include <vector>

using namespace std;

bool map[100][100];
vector<vector<vector<pair<int, int>>>> dragon(
    4,
    vector<vector<pair<int, int>>>(
        11,
        vector<pair<int, int>>()));

int N; // N <= 20
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

// g는 10까지니까, 10세대까지 드래곤 커브가 어떤 점들을 포함하는지에 대해 미리 계산해두기
// 0세대부터 10세대까지 2의 등비수열만큼 계산을 하기에 4 * pow(2, 10) = 대략 5000정도 되어 보임
// 모든 방향에 대해서도 계산해둘려고 함. 만약 시간 초과가 난다면,
// 한 방향에 대해서만 계산하고, 나머지 방향은 위치 반전으로 반시계로 회전하면 될 듯
// x, y를 기점으로 bool map에 true로 나타내기
// 99 * 99에 대하여 2 * 2를 살펴보기, 계산량 40000

void calculate_dragon_curve() {
    for (int i = 0; i < 4; i++) { // 차례대로 동, 북, 서, 남
        // 0세대에 대한 초기값
        dragon[i][0].push_back(make_pair(0, 0));
        dragon[i][1].push_back(make_pair(dx[i], dy[i]));
        // 1세대부터 10세대까지 dp
        for (int j = 1; j < 11; j++) { // 각 방향에 대해서 10세대까지 계산
            pair<int, int> last_point = dragon[i][j - 1].back();
            dragon[i][j] = dragon[i][j - 1]; // 이전에 계산한 값 복사
            for (int k = dragon[i][j].size() - 1; k > -1; k--) { // 끝점을 제외하고 반복, 역순으로 돌려서 push
                // 끝점을 제외한 드래곤 커브 지점들을 원점 기준으로 이동
                int diff_x = dragon[i][j][k].first - last_point.first;
                int diff_y = dragon[i][j][k].second - last_point.second;

                // 시계 방향 90도 회전 및 다시 기준점 기준으로 이동
                dragon[i][j].push_back(make_pair(
                    last_point.first + diff_y, last_point.second - diff_x));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    // dragon curve 미리 계산하기
    calculate_dragon_curve();

    // map에 드래곤 커브가 지나간 점들 표시하기
    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g; // d는 0, 1, 2, 3으로 차례대로 동, 북, 서, 남

        for (int j = 0; j < dragon[d][g].size(); j++) {
            map[y][x] = true;
        }
    }

    //


    return 0;
}