#include <iostream>
#include <algorithm>

using namespace std;

unsigned int stair[301];
unsigned int dp[301];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x; cin >> x;
	for (int i = 1; i <= x; i++) {
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= x; i++) {
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
	}

	cout << dp[x] << endl;
}



//
//int main() {
//	ios::sync_with_stdio(false);
//
//	int x; cin >> x;
//	for (int i = 1; i <= x; i++) {
//		cin >> stair[i];
//	}
//
//	int a{ 0 }, b{ 1 }; // a�� i - 1�� ��Ƶα� ���� �뵵, b�� i - 2�� ��Ƶα� ���� �뵵
//	// int check = 0;
//
//	if (stair[1] > stair[2]) {
//		stair[3] += stair[1];
//	}
//	else {
//		stair[3] += stair[2];
//		a++;
//		// check++;
//	}
//	stair[2] += stair[1];
//	//�ʱ� ���� 1, 2, 3 �ϼ�
//	
//	for (int i = 4; i <= x; i++) {
//		// a�� b�� i�� i - 1�� ��� �뵵�� �Ǿ� �Ѵ�, �׸��� check�� �缱�� ���� �������� �̾��
//		if (stair[i - 1] > stair[i - 2]) {
//			if (a != 1) {
//				stair[i] += stair[i - 1];
//				//b = a;
//				a++;
//			}
//			else {
//				stair[i] += stair[i - 2];
//				//b = a;
//				a = 0;
//			}
//		}
//		else {
//			// b�� ��ĭ �ٴ� �ű⿡ ��� ��
//			stair[i] += stair[i - 2];
//			//b = a;
//			a = 0;
//		}
//	}
//
//	cout << stair[x] << "\n";
//
//	return 0;
//}

//1��° : 10 // 1�� 1 1 
//2��° : 10 + 20 // 2�� 2 1
//3��° : 10 + 15, 20 + 15 // 2�� 0 2
//4��° : 10 + 15 + 25, 10 + 20 + 25 // 1��
//5��° : 10 + 20 + 25 + 10 // 2��
//6��° : 10 + 20 + 25 + 20 // 1��
/*
		if (check != 1) {
			if (stair[i - 1] > stair[i - 2]) {
				stair[i] = stair[i] + stair[i - 1];
				a = ++check; b = check;
				// check�� i - 1�� �������� �ȴ�.
				// a�� i�� �Ǿ� �Ѵ�. b�� i -1�� �Ǿ� �Ѵ�.
			}
			else {
				stair[i] = stair[i] + stair[i - 2];
				a = check = 0; b = check;
				// check�� i - 2�� �������� �ȴ�.
			}
		}
		else {
			stair[i] = stair[i] + stair[i - 2];
			a = check = 0; b = check;
			// check�� i - 2�� �������� �ȴ�.
		}
*/