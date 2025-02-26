//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int N, K, total;
//
//pair<int, int> value[100];
//pair<int, vector<int>> dp[100001];
//
////bool compare(pair<double, double> a, pair<double, double> b) {
////	return a.second / a.first > b.second > b.first;
////}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> N >> K;
//
//	for (int i = 0; i < N; i++) {
//		cin >> value[i].first >> value[i].second;
//		dp[value[i].first].first = value[i].second;
//		dp[value[i].first].second.push_back(i);
//	}
//
//	// dp의 index는 무게를
//	// dp 안의 값은 가치 합의 최댓값으로 지정
//
//	// 문제점 : 중복되서 선택하면 안됨.
//	bool find;
//	for (int i = 1; i <= K; i++) { 
//		for (int j = 0; j < N; j++) {
//			if (i - value[j].first >= 0 && dp[i - value[j].first].first != 0) {
//				// dp[i - value[j].first].second에 j가 들어가 있는지 검사
//				// 있으면 continue;
//				find = false;
//
//				for (auto& e : dp[i - value[j].first].second) {
//					if (e == j) find = true;
//				}
//				if (find) continue;
//				
//				if (dp[i].first < dp[i - value[j].first].first + value[j].second) {
//					dp[i].first = dp[i - value[j].first].first + value[j].second;
//					
//					dp[i].second.clear();
//					for (auto& e : dp[i - value[j].first].second) dp[i].second.push_back(e);
//					dp[i].second.push_back(j);
//				}
//			}
//		}
//		
//		// 만약 위의 과정을 거쳐도 0인 경우
//		// i - 1의 경우가 가치합이 최대가 됨
//		if (dp[i].first < dp[i - 1].first) {
//			dp[i].first = dp[i - 1].first;
//
//			dp[i].second.clear();
//			for (auto& e : dp[i - 1].second) dp[i].second.push_back(e);
//		}
//	}
//
//	cout << dp[K].first << "\n";
//}