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
	//	// �ذ�� : P[i]�� N���� ���� �ִ� ��ŭ ���� ���� ������ ���� �����ؼ� �� -- X
	//	// �ذ�� : ���� ���� ���� �񱳸� ����, �ʱⰪ�� P[1]�� m�� P[i]�� ���� �����鼭 dp�� �����س��� 

	//	// i�� �ش��ϴ� ��ŭ P[i - 1]�� ����, P[i]��°�� ���� ���ϱ�
	//	// j = (N%i == 0 ? N/i : N/i + 1);
	//	// tmp = ?
	//	// �ִ�� ���� ���� �� tmp ũ�� i ����
	//	// �ִ밡 Ŭ��� �ִ� ����
	//	// m = max(m, tmp);
	//}