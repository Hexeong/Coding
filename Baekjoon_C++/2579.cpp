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
//	int a{ 0 }, b{ 1 }; // a는 i - 1을 담아두기 위한 용도, b는 i - 2를 담아두기 위한 용도
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
//	//초기 조건 1, 2, 3 완성
//	
//	for (int i = 4; i <= x; i++) {
//		// a랑 b는 i와 i - 1을 담는 용도가 되야 한다, 그리고 check는 당선된 것을 바탕으로 이어간다
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
//			// b는 두칸 뛰는 거기에 상관 노
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

//1번째 : 10 // 1번 1 1 
//2번째 : 10 + 20 // 2번 2 1
//3번째 : 10 + 15, 20 + 15 // 2번 0 2
//4번째 : 10 + 15 + 25, 10 + 20 + 25 // 1번
//5번째 : 10 + 20 + 25 + 10 // 2번
//6번째 : 10 + 20 + 25 + 20 // 1번
/*
		if (check != 1) {
			if (stair[i - 1] > stair[i - 2]) {
				stair[i] = stair[i] + stair[i - 1];
				a = ++check; b = check;
				// check는 i - 1을 가져가야 된다.
				// a는 i가 되야 한다. b는 i -1이 되야 한다.
			}
			else {
				stair[i] = stair[i] + stair[i - 2];
				a = check = 0; b = check;
				// check는 i - 2를 가져가야 된다.
			}
		}
		else {
			stair[i] = stair[i] + stair[i - 2];
			a = check = 0; b = check;
			// check는 i - 2를 가져가야 된다.
		}
*/