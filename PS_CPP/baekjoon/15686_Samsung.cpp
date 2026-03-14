// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>

using namespace std;

int N, M; // 2 <= N <= 50, 1 <= M <= 13
vector<pair<int, int>> house; // <= 100;
vector<pair<int, int>> chicken; // <= 13;
int min_dist[100];
int min_dist_sum = 1000000;


// 도시의 치킨 거리는 모든 집마다 가장 가까운 치킨집까지의 거리의 합이다.
// M개를 골랐을 때, 치킨 거리의 최소값을 구해라
// 어차피 집마다 치킨 거리가 발생. 그럼 M개를 골랐을 때, 치킨거리가 최소화되게 해야 함.
// 미리 치킨집마다 각 집까지의 치킨 거리 계산 = 1300
// dp? i개를 골랐을 때 가장 작게 최소화되는 치킨 거리
// 초기값 세팅 : 도시의 치킨 거리의 최소가 되는 치킨집 1개 찾기??
// 점화식 : 각 집마다 i - 1의 치킨 거리에 대하여, 남은 치킨집들에 대해 min(min_dist[i - 1][h], cur_dist[h])의 합을
// 구하여을 구한 다음, 도시의 치킨거리가 최소화되게 하는 치킨집을 추가하여 i번째의 도시의 치킨 거리 구하기
// 계산량 : 13 * 100(집 개수) * 13!(13 * 12 * ... * 1), 무조건 1억이 넘음. 기각

// 다른 방향 생각
// 정렬? 100개의 집에 대해서 각 13개의 거리들을 정렬, 100 * 13log13 = 대략 5200
// 하지만, 정렬한 순위의 총합이 거리의 비교로 이어진다는 보장이 없음

// 다른 방향 생각
// 백트래킹? 100 * 13! / (13 - M)!
// 무조건 가짓수 쳐내야함. 어느 조건일 경우 해당 가지 없애기
// 기존의 min값보다 해당 치킨집을 추가하고 계산한 값이 더 큰 경우 가지 없애기
void calculate_chick_dist(int depth, int cur_i, int dist_sum) {
    min_dist_sum = min_dist_sum == 0 ? dist_sum : min(min_dist_sum, dist_sum);
    if (depth == M)
        return;

    for (int i = cur_i; i < chicken.size(); i++) {
        int sum = dist_sum;
        vector<pair<int, int>> dist_tmp;
        for (int j = 0; j < house.size(); j++) {
            int cur_dist = abs(house[j].second - chicken[i].second)
                + abs(house[j].first - chicken[i].first);
            if ( min_dist[j] > cur_dist || min_dist[j] == 0) {
                sum -= min_dist[j];
                sum += cur_dist;
                dist_tmp.push_back(make_pair(j, min_dist[j]));
                min_dist[j] = cur_dist;
            }
        }
        if (sum == dist_sum)
            continue; // 해당 치킨집을 추가해봤자 치킨거리 최소화에 도움을 주지 않기 때문

        // 재귀 시작
        calculate_chick_dist(depth + 1, i + 1, sum);
        // min_dist를 원래 상태로 돌려놔야 함.
        while (dist_tmp.size() > 0) {
            min_dist[dist_tmp.back().first] = dist_tmp.back().second;
            dist_tmp.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int a; cin >> a; // 0은 빈칸, 1은 집, 2는 치킨집
            if (a == 1)
                house.push_back(make_pair(j, i));
            else if (a == 2)
                chicken.push_back(make_pair(j, i));
        }

    calculate_chick_dist(0, 0, 0);

    cout << min_dist_sum << "\n";

    return 0;
}