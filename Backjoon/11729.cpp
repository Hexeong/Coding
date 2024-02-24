#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> s1;
stack<int> s2;
stack<int> s3;
vector<int> res;

void re_odd(int n) {
	if (n == 1) {

	}
	else {

	}
}

void move(int start, int end) {
	if (start == 1) {
		if (end == 2) {
			s2.push(s1.top());
			s1.pop();
		}
		else {
			s3.push(s1.top());
			s1.pop();
		}
	}
	else if (start == 2) {
		if (end == 1) {
			s1.push(s2.top());
			s2.pop();
		}
		else {
			s3.push(s2.top());
			s2.pop();
		}
	}
	else {
		if (end == 1) {
			s1.push(s3.top());
			s3.pop();
		}
		else {
			s2.push(s3.top());
			s3.pop();
		}
	}
	return;
}

void re_even(int n, int start, int end) {
	if (n == 1) {
		move(start, end);
		return;
	}
	else {
		if (s1.empty()) {
			re_even(n - 1, 2, 1);

			s3.push(s2.top());
			s2.pop();

			re_even(n - 1, 1, 3);
		}
		else {
			re_even(n - 1, 1, 2);

			s3.push(s1.top());
			s1.pop();

			re_even(n - 1, 2, 3);
		}

		return;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = N; i > 0; i--) s1.push(i);

	if (N % 2 == 0) re_even(N, 1, 3);
	else re_odd(N);
	
	return 0;
}