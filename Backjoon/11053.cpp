//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//#pragma warning(disable: 4996)
//
//using namespace std;
//
//int T, N, M, K, H, X, Y;
//int answer = 0;
//
//int dp[1001];
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    vector<int> v;
//    cin >> T;
//
//    for (int i = 0; i < T; i++) {
//        cin >> K;
//        v.emplace_back(K);
//        int dp_maximum = 0;
//
//        for (int j = 0; j < v.size(); j++) {
//            if (v[i] > v[j]) {
//                if (dp_maximum < dp[j])
//                    dp_maximum = dp[j];
//            }
//        }
//        dp[i] = dp_maximum + 1;
//        answer = max(answer, dp[i]);
//    }
//
//    cout << answer << "\n";
//
//    return 0;
//}