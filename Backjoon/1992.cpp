#include <iostream>
#include <cstring>

using namespace std;

char input[64][64];
int N;
string res = "";
int cursor = 0;

void revert(int r, int c, int n) {
	bool judge = true;
	// 1»çºÐ¸é Å½»ö
	for (int i = r; i < r + n / 2; i++) {
		for (int j = c; j < c + n / 2; j++) {
			if (input[r][c] != input[i][j]) {
				judge = false;
				break;
			}
		}
		if (!judge) break;
	}
	// Å½»ö °á°ú
	if (judge) {
		res.insert(res.begin() + cursor, input[r][c]);
		cursor+=1;
	}
	else {
		res.insert(res.begin() + cursor, '(');
		cursor+=1;
		res.insert(res.begin() + cursor, ')');
		revert(r, c, n / 2);
		cursor+=1;
	}
	// 2»çºÐ¸é Å½»ö
	judge = true;
	for (int i = r; i < r + n / 2; i++) {
		for (int j = c + n / 2; j < c + n; j++) {
			if (input[r][c + n / 2] != input[i][j]) {
				judge = false;
				break;
			}
		}
		if (!judge) break;
	}
	// Å½»ö °á°ú
	if (judge) {
		res.insert(res.begin() + cursor, input[r][c + n / 2]);
		cursor+=1;
	}
	else {
		res.insert(res.begin() + cursor, '(');
		cursor+=1;
		res.insert(res.begin() + cursor, ')');
		revert(r, c + n / 2, n / 2);
		cursor+=1;
	}
	// 3»çºÐ¸é Å½»ö
	judge = true;
	for (int i = r + n / 2; i < r + n; i++) {
		for (int j = c; j < c + n / 2; j++) {
			if (input[r + n / 2][c] != input[i][j]) {
				judge = false;
				break;
			}
		}
		if (!judge) break;
	}
	// Å½»ö °á°ú
	if (judge) {
		res.insert(res.begin() + cursor, input[r + n / 2][c]);
		cursor+=1;
	}
	else {
		res.insert(res.begin() + cursor, '(');
		cursor+=1;
		res.insert(res.begin() + cursor, ')');
		revert(r + n / 2, c, n / 2);
		cursor+=1;
	}
	// 4»çºÐ¸é Å½»ö
	judge = true;
	for (int i = r + n / 2; i < r + n; i++) {
		for (int j = c + n / 2; j < c + n; j++) {
			if (input[r + n / 2][c + n / 2] != input[i][j]) {
				judge = false;
				break;
			}
		}
		if (!judge) break;
	}
	// Å½»ö °á°ú
	if (judge) {
		res.insert(res.begin() + cursor, input[r + n / 2][c + n / 2]);
		cursor+=1;
	}
	else {
		res.insert(res.begin() + cursor, '(');
		cursor+=1;
		res.insert(res.begin() + cursor, ')');
		revert(r + n / 2, c + n / 2, n / 2);
		cursor+=1;
	}


	return;
}

//void revert(int r, int c, int n) {
//	if (n == 1) {
//
//	}
//
//	revert(r, c, n / 2);
//	revert(r + n / 2, c, n / 2);
//	revert(r, c + n / 2, n / 2);
//	revert(r + n / 2, c + n / 2, n / 2);
//}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			input[i][j] = s[j];
		}
	}

	revert(0, 0, N);

	cout << '(' << res << ')';
	

	return 0;
}