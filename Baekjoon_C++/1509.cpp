//
// Created by hex on 25. 11. 11..
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    // n * n으로 각 문자열이 대칭인지 확인하는 방법..?
    // dp로 확인을 해야겠지..?

    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0)); // i부터 j까지 펠린드롬인 조합이 몇개 들어가 있는지
    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
        if (i + 1 < s.size() && s[i] == s[i + 1])
            dp[i][i + 1] = 1;
    }

    for (int size = 1; size <= s.size(); size++) {
        for (int left = 0; left < s.size() - size; left++) {
            int right = left + size;

            if (dp[left + 1][right - 1] == 1 && s[left] == s[right]) {
                dp[left][right] = 1;
            }
        }
    }

    // dp2[i] = s[0...i]까지의 최소 팰린드롬 분할 개수
    vector<int> dp2(s.size());

    for (int i = 0; i < s.size(); i++) {
        // 1. 최악의 경우 (i+1)개로 초기화 (모두 한 글자씩 쪼갬)
        dp2[i] = i + 1;

        // 2. s[j...i]가 팰린드롬인지 검사
        for (int j = 0; j <= i; j++) {
            if (dp[j][i] == 1) { // s[j...i]가 팰린드롬이라면

                if (j == 0) {
                    // s[0...i] (즉, 처음부터 끝까지)가 통째로 팰린드롬인 경우
                    dp2[i] = 1;
                } else {
                    // s[0...j-1]의 최소 개수 + 1 (s[j...i] 조각)
                    dp2[i] = min(dp2[i], dp2[j - 1] + 1);
                }
            }
        }
    }

    // 최종 결과는 s[0]부터 s.size()-1까지의 최소 분할 개수
    cout << dp2[s.size() - 1] << '\n';
}