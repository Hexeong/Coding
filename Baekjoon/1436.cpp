#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	int a; cin >> a;

	if (a == 1) {
		cout << 666 << endl;
		return 0;
	}

	int cycle = 667;
	int cnt = 1;
	while (1) {
		cycle++;

		int tmp = cycle;
		int count = 0;
		while (tmp > 0) { // 연속으로 666인지 확인
			if (tmp % 10 == 6) {
				count++;
				tmp /= 10;
			}
			else if (count < 3) {
				tmp /= 10;
				count = 0;
			}
			else if (count >= 3) {
				tmp /= 10;
			}
		}

		if (count >= 3) cnt++;

		count = 0;

		if (cnt == a) {
			cout << cycle << endl;
			return 0;
		}
	}

}

//void swap(int& a, int& b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main() {
//	int a; cin >> a;
//	// 666, 1666, 2666 ... 5666, 6660 ... 6669, 10666 ... 15666 , 16660
//
//	if (a == 1) {
//		cout << 666 << endl;
//		return;
//	}
//
//	int cnt = 1;
//	vector<int> v;
//	v.push_back(0);
//	v.push_back(666);
//	int idx = 0; // 표적
//	int idx666 = 1; // 666 위치
//	while (cnt != a) {
//		cnt++;
//		if (v[idx666 - 1] == 6) {
//			swap(v[idx666 - 1], v[idx666]);
//			idx666--;
//			idx++;
//			v[idx] = 0;
//		}
//		if (v[idx666 - 1] < 6) {
//			v[idx]++;
//		}
//	}
//
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i];
//	}
//
//	cout << endl;
//}

//int combination(int n, int r)
//{
//	if (n == r || r == 0)
//		return 1;
//	else
//		return combination(n - 1, r - 1) + combination(n - 1, r);
//}

// 1: 666
	// ~ 1 + 9 * 4 : 1666 ~ 9666
	// ~ 1 + 36 + 9 * 4 : 11666 ~ 99666

	/*if (a == 1) cout << 666 << endl;

	int cnt = 1;
	while (1) {
		int tmp;
		tmp = pow(9, cnt) * combination(cnt + 3, cnt);
		if (a < 0) {
			a += tmp;
			break;
		}
		cnt++;
	}

	int* arr = new int[cnt + 3];


	while (true) {

	}*/

//vector<int> v;

//int cnt = 1;
//int i = 0;
//v.push_back(6);
//v.push_back(6);
//v.push_back(6);
//while (cnt != a) {
//	// 666, 1666 ... 5666 , 6166 ... 6666 , 6667 ... 6669, 6676
//	// ... 9666, 11666, 12666, 
//	cnt++;
//	if (v[i] == 9) {
//		if (i != 0) {
//			v[i] = 6;
//			i--;
//		}
//		else {
//			v.push_back(6); // 96666
//			for (int i = 0; i < v.size() - 3; i++) {
//				v[i] = 1;
//			} // 11666
//		}
//	}
//	else if (v[i] == 6) {
//		if ((i + 1) != v.size()) {
//			i++;
//			v[i] = 1;
//		}
//		else {
//			v[i]++;
//		}
//	}
//	else if (v[i] != 6 && v[i] != 9) {
//		v[i]++;
//	}
//}