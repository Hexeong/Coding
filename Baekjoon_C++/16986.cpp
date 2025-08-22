//
// Created by admin on 2025-08-21.
//
#include <iostream>

using namespace std;

int compatibility[9][9];

int behavior[3][20]; // 지우, 경희, 민호 행동 순서
int turn[3]; // 지우, 경희, 민호의 자기 차례가 온 횟수
int win_cnt[3]; // 지우, 경희, 민호 순서
bool is_used[9]; // 지우가 사용한 손동작을 마킹한 것

int N, K;
bool end_flag = false;

bool calculate_winner(int p1_idx, int p2_idx, int p1_behavior, int p2_behavior) {
    if (compatibility[p1_behavior][p2_behavior] == 2) // 이긴다.
        return true;
    if (compatibility[p1_behavior][p2_behavior] == 1) // 비긴다.
        return p1_idx > p2_idx; // idx가 p1이 더 크면 true, 작으면 false
    // 진다. p2 win
    return false;
}

void bt(int last_winner_idx, int cur_opponent_idx, int next_opponent_idx) { // 지우가 무조건 last_winer 혹은 cur_opponent로 만들기
    if (win_cnt[last_winner_idx] == K) {
        if (last_winner_idx == 0)
            end_flag = true;
        return;
    }

    if (turn[0] >= N || turn[1] >= N || turn[2] >= N)
        return;

    if (next_opponent_idx == 0) {
        if (calculate_winner(last_winner_idx, cur_opponent_idx,
                behavior[last_winner_idx][turn[last_winner_idx]++],
                behavior[cur_opponent_idx][turn[cur_opponent_idx]++])) {
            win_cnt[last_winner_idx]++;
            bt(last_winner_idx, next_opponent_idx, cur_opponent_idx);
            win_cnt[last_winner_idx]--;
        } else {
            win_cnt[cur_opponent_idx]++;
            bt(cur_opponent_idx, next_opponent_idx, last_winner_idx);
            win_cnt[cur_opponent_idx]--;
        }
        turn[last_winner_idx]--;
        turn[cur_opponent_idx]--;

        return;
    }

    for (int i = 0; i < N; i++) {
        if (is_used[i]) continue; // 사용하지 않은 건 건너 뛰기

        // 해당 것을 사용했을 때의 경기 결과
        if (last_winner_idx == 0) {
            is_used[i] = true;
            if (calculate_winner(last_winner_idx, cur_opponent_idx, i,
                behavior[cur_opponent_idx][turn[cur_opponent_idx]++])) {
                win_cnt[last_winner_idx]++;
                bt(last_winner_idx, next_opponent_idx, cur_opponent_idx);
                win_cnt[last_winner_idx]--;
            } else {
                win_cnt[cur_opponent_idx]++;
                bt(cur_opponent_idx, next_opponent_idx, last_winner_idx);
                win_cnt[cur_opponent_idx]--;
            }
            is_used[i] = false;
            turn[cur_opponent_idx]--;
        } else { // cur_opponent_idx == 0
            is_used[i] = true;
            if (calculate_winner(last_winner_idx, cur_opponent_idx,
                behavior[last_winner_idx][turn[last_winner_idx]++],
                i)) {
                win_cnt[last_winner_idx]++;
                bt(last_winner_idx, next_opponent_idx, cur_opponent_idx);
                win_cnt[last_winner_idx]--;
            } else {
                win_cnt[cur_opponent_idx]++;
                bt(cur_opponent_idx, next_opponent_idx, last_winner_idx);
                win_cnt[cur_opponent_idx]--;
            }
            is_used[i] = false;
            turn[last_winner_idx]--;
        }

        if (end_flag)
            return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> compatibility[i][j];

    for (int i = 0; i < 20; i++) {
        cin >> behavior[1][i];
        behavior[1][i]--;
    }
    for (int i = 0; i < 20; i++) {
        cin >> behavior[2][i];
        behavior[2][i]--;
    }

    bt(0,1,2);

    cout << (end_flag ? 1 : 0) << "\n";
}