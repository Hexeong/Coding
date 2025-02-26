#include <iostream>
#include <algorithm>

using namespace std;

int N, tmp, r;

string arr[10];
int len[10];
int alpha[26];

bool compare(int a, int b) { return a > b; }

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		len[i] = arr[i].size();
	}

	for (int i = 0; i < N; i++) {
		tmp = 1;
		for (int j = len[i] - 1; j > -1; j--) {
			alpha[arr[i][j] - 'A'] += tmp;
			tmp *= 10;
		}
	}

	sort(alpha, alpha + 26, compare);

	for (int i = 0; i < 10; i++) {
		r += alpha[i] * (9 - i);
	}

	cout << r << "\n";
}

//bool compare(string a, string b) {
//	return a.size() > b.size();
//}

//for (int i = 0; i < N; i++) {
	//	tmp = 0;
	//	for (int j = v_s[i].size() - 1; j > -1; j--) { // 맨 앞자리부터
	//		if (alpha[v_s[i][j] - 'A'] == 0) {
	//			alpha[v_s[i][j] - 'A'] = cnt;
	//			tmp += pow(10, j) * cnt;
	//			cnt--;
	//		}
	//		else {
	//			tmp += pow(10, j) * alpha[v_s[i][j] - 'A'];
	//		}
	//	}
	//	total += tmp;
	//}


//for (int i = 0; i < N; i++) {
//	cin >> v_s[i];
//}
//
//sort(v_s, v_s + N, compare); // 길이 큰 순으로 정렬?
//
//int idx = 0;
//// 순서 역순으로 해서 for문 2번
//while (1) {
//
//	for (int i = 0; i < N; i++) {
//		int len = v_s[0].size() - v_s[i].size();
//		if (v_s[i].size() != v_s[i + 1].size()) break;
//	}
//	idx++;
//}
//cout << total << "\n";