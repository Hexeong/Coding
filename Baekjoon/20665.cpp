#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N, T, P, total;
int timeT[25][60][101];

class Time {
public:
	int sh;
	int sm;
	int eh;
	int em;
	Time(int sh, int sm, int eh, int em) {
		this->sh = sh;
		this->sm = sm;
		this->eh = eh;
		this->em = em;
	}
};

bool cmp(const Time& a, const Time& b) {
	if (a.sh == b.sh) {
		if (a.sm == b.sm) {
			if (a.eh == b.eh) {
				return a.em < b.em;
			}
			return a.eh < b.eh;
		}
		return a.sm < b.sm;
	}
	return a.sh < b.sh;
}

pair<int, int> distance(int index, int h, int m) {
	int distance = 987654321;
	int minIndex = 1;
	for (int i = 1; i <= N; i++) {
		if (index == i)  continue;
		if (timeT[h][m][i]) {
			int d = abs(index - i);
			if (distance > d) {
				distance = d;
				minIndex = i;
			}
		}
	}

	pair<int, int> a; a.first = distance; a.second = minIndex;
	return a;
}

int findSeat(int h, int m) {
	int index = 1;
	int maxDis = 0;
	for (int i = 1; i <= N; i++) {
		if (!timeT[h][m][i]) {
			pair<int, int> a = distance(i, h, m);
			if (a.first > maxDis) {
				maxDis = a.first;
				index = i;
			}
		}
	}
	return index;
}

vector<Time> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T >> P;

	for (int i = 0; i < T; i++) {
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		v.push_back(Time(tmp1 / 100, tmp1 % 100, tmp2 / 100, tmp2 % 100));
	}

	sort(v.begin(), v.end(), cmp);
	for (Time t : v) {
		int sH = t.sh;  int sM = t.sm;
		int eH = t.eh;  int eM = t.em;
		int idx = findSeat(sH, sM);
		for (int i = sH; i <= eH; i++) {
			if (sH == eH) {
				for (int j = sM; j < eM; j++) {
					timeT[i][j][idx] = 1;
				}
				break;
			}
			if (i == sH) {
				for (int j = sM; j <= 59; j++) {
					timeT[i][j][idx] = 1;
				}
			}
			else if (i == eH) {
				for (int j = 0; j < eM; j++) {
					timeT[i][j][idx] = 1;
				}
			}
			else {
				for (int j = 0; j <= 59; j++) {
					timeT[i][j][idx] = 1;
				}
			}
		}
	}
	for (int i = 9; i <= 20; i++) {
		for (int j = 0; j <= 59; j++) {
			if (!timeT[i][j][P]) {
				total += 1;
			}
		}
	}
	cout << total;
}

/*
int* tn = new int[T];
	vector<int>  th;
	for (int i = 9; i < 21; i++) {
		for (int j = 0; j < 60; j += 10) {

			for (int k = 0; k < T; k++) {
				if (t[k].sh == i && t[k].sm == j) { // 자리 등록
					// 처음은 0번째 자리, 가장 먼곳으로 자리 차지
					th.push_back(k);

				}

				if (t[k].eh == i && t[k].em == j) { // 자리 퇴실
					for (int x = 0; x < T; x++) {
						if (tn[x] == k) {
							tn[x] = 0;
							break;
						}
					}
				}
			}


			if (tn[P - 1] == 0) total += 10;
		}
	}

	cout << total << "\n";
*/