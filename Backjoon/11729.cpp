#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> s1;
stack<int> s2;
stack<int> s3;
vector<pair<int, int>> res;

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

void re(int n, int start, int end) {
	if (n == 1) {
		move(start, end);
		res.push_back(make_pair(start, end));
		return;
	}
	else {
		bool x[] = { true, true, true };
		x[start - 1] = false;
		x[end - 1] = false;
		for (int i = 0; i < 3; i++) {
			if (x[i]) {
				re(n - 1, start, i + 1);

				move(start, end);
				res.push_back(make_pair(start, end));

				re(n - 1, i + 1, end);
				return;
			}
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

	re(N, 1, 3);
	
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << "\n";
	}

	return 0;
}