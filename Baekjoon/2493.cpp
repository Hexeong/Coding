#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> stk;
int N, h;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> h;
		while (!stk.empty()) {
			if (stk.top().second > h) {
				cout << stk.top().first << ' ';
				break;
			}
			stk.pop();
		}

		if (stk.empty()) cout << "0 ";

		stk.push(make_pair(i, h));
	}
}

//if (i <= s.size() && s.size() != 0) {
//	int cur = s.top();
//	s.pop();
//	if (s.size() == 0) continue;
//	if (cur == m) {
//		arr[i] = 0;
//		continue;
//	}
//	while (s.top() < cur) {
//		s.pop();
//		if (s.size() == 0) break;
//	}
//}
//arr[i] = s.size();

//cin >> N;
//
//int tmp; int m = 0;
//for (int i = 1; i <= N; i++) {
//	cin >> tmp; s.push(tmp);
//	m = max(m, tmp);
//}
//
//for (int i = N; i > 0; i--) {
//	// if t가 0이면
//	if (t.size() != 0) {
//		t.push(s.top());
//		s.pop();
//
//		while (t.top() > s.top()) {
//			t.push(s.top());
//			s.pop();
//		}
//		// s.size() 저장
//		t.pop();
//	}
//	else {
//		if (t.top() < s.top()) {
//			// s.size() 저장
//			t.pop();
//		}
//		else {
//		}
//	}
//}
//
//for (int i = 1; i <= N; i++) cout << arr[i] << " ";
//cout << "\n";