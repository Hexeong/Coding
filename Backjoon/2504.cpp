#include <iostream> 
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

stack<pair<char, int>> st;
vector<vector<pair<int, int>>> floors[16]; // i = start_floor, j = list, first = value, second = end_floor

int main() {
	string t; cin >> t;

	int floor{ 0 }, last_floor{ 0 };
	for (int k = 0; k < t.size(); k++) {
		if (t[k] == '(') {

			floor++; last_floor = floor;
			st.push(make_pair('(', floor));

		}
		else if (t[k] == ')') {
			if (st.size() != 0 && st.top().first == '(') {
				if (st.top().second == last_floor) {
				}
				else if (st.top().second + 1 == last_floor) {
					
					last_floor -= 1;
				}
				floor--;
				st.pop();

			}
			else {
				cout << 0;
				return 0;
			}
		}
		else if (t[k] == '[') {

		}
		else if (t[k] == ']') {

		}
	}

	return 0;
}








//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//stack<pair<char, int>> s;
//int floors[16][16]; // i = start floor, j = end floor로 해서 *2의 경우 end floor가 +1인 곳 부터 곱하기
//
//int main() {
//	string t; cin >> t;
//
//	int res = 0;
//	int floor = 0;
//	int last_floor = 0;
//
//	for (int i = 0; i < t.size(); i++) {
//		if (t[i] == '(') {
//			floor++;
//			s.push(make_pair('(', floor));
//			last_floor = floor;
//
//			if (floor == 1) {
//				for (int i = 1; i < 16; i++) for (int j = 0; j < 16; j++) {
//					res += floors[i][j];
//					floors[i][j] = 0;
//				}
//			}
//		}
//		else if (t[i] == ')') {
//			if (s.size() != 0 && s.top().first == '(') {
//				if (s.top().second == last_floor) {
//					floors[s.top().second][s.top().second] += 2;
//				}
//				else if (s.top().second == last_floor - 1) {
//					// 이전 것 싹다 곱하기
//					for (int j = s.top().second + 1; j < 16; j++) {
//						if (floors[i][j] != 0) {
//							floors[i][s.top().second] = floors[i][j];
//							floors[i][j] = 0;
//						}
//					}
//					last_floor -= 1;
//				}
//				s.pop();
//				floor--;
//			}
//			else {
//				cout << 0;
//				return 0;
//			}
//		}
//		else if (t[i] == '[') {
//			floor++;
//			s.push(make_pair('[', floor));
//			last_floor = floor;
//
//			if (floor == 1) {
//				for (int i = 1; i < 16; i++) {
//					res += floors[i];
//					floors[i] = 0;
//				}
//			}
//		}
//		else if (t[i] == ']') {
//			if (s.size() != 0 && s.top().first == '[') {
//				if (s.top().second == last_floor) {
//					floors[s.top().second] += 3;
//				}
//				else if (s.top().second == last_floor - 1) {
//					// 이전 것 싹다 곱하기
//					for (int i = s.top().second + 1; i < 16; i++) {
//						floors[i] *= 3;
//					}
//					last_floor -= 1;
//				}
//				s.pop();
//				floor--;
//			}
//			else {
//				cout << 0;
//				return 0;
//			}
//		}
//	}
//
//	if (s.size() > 0) {
//		cout << 0;
//		return 0;
//	}
//
//	for (int i = 1; i < 16; i++) {
//		res += floors[i];
//		floors[i] = 0;
//	}
//
//	cout << res;
//
//	return 0;
//}