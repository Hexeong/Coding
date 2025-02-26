#include <iostream>
#include <algorithm>

using namespace std;

int n;

int p[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i - j] + p[j], dp[i]);
		}
	}

	cout << dp[n] << endl;
}

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//
//struct E {
//	ll P;
//	int idx;
//};
//
//int N;
//
//E P[1001];
//
//bool compare(E a, E b) {
//	double ad = (double)a.P / (double)a.idx; double bd = (double)b.P / (double)b.idx;
//	return ad > bd;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		cin >> P[i].P;
//		P[i].idx = i;
//	}
//
//	sort(&P[1], &P[N + 1], compare);
//
//	ll m = 0;
//	int c = N;
//	for (int i = 1; i <= N; i++) {
//		if (c >= P[i].idx) {
//			m += P[i].P * (c / P[i].idx);
//			c %= P[i].idx;
//		}
//	}
//
//	cout << m << "\n";
//}

//for (int i = 2; i <= N; i++) {
	//	// 해결법 : P[i]를 N보다 작은 최대 만큼 더한 값에 나머지 값도 포함해서 비교 -- X
	//	// 해결법 : 같은 단위 끼리 비교를 시작, 초기값이 P[1]인 m과 P[i]를 비교해 나가면서 dp에 저장해나감 

	//	// i에 해당하는 만큼 P[i - 1]을 빼고, P[i]번째의 값을 더하기
	//	// j = (N%i == 0 ? N/i : N/i + 1);
	//	// tmp = ?
	//	// 최대와 비교해 봤을 때 tmp 크면 i 유지
	//	// 최대가 클경우 최대 유지
	//	// m = max(m, tmp);
	//}