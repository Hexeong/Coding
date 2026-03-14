#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int N;

vector<int> v; // o d l r e h w

void printing() {
	cout << "  " << v[5] << v[4] << v[2] << v[2] << v[0] << "\n";
	cout << "+ " << v[6] << v[0] << v[3] << v[2] << v[1] << "\n";
	cout << "-------\n";
	cout << setw(7) << right << N << "\n";
}

void fifth(int t,int g) {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (g + i + j == t && i != j) {
				auto it = find(v.begin(), v.end(), i);
				if (it != v.end()) continue;
				auto gt = find(v.begin(), v.end(), j);
				if (gt != v.end()) continue;

				v.push_back(i);
				v.push_back(j);
				printing();
				exit(0);
			}
		}
	}
}

void fourth(int t, int g) {
	for (int i = 0; i < 10; i++) {
		if ((g + v[0] + i) % 10 == t % 10) {
			auto it = find(v.begin(), v.end(), i);
			if (it != v.end()) continue;

			v.push_back(i);
			int m = (g + v[0] + i) / 10;
			fifth(t / 10, m);
			v.pop_back();
		}
	}
}

void third(int t, int g) {
	for (int i = 0; i < 10; i++) {
		if ((g + v[2] + i) % 10 == t % 10) {
			auto it = find(v.begin(), v.end(), i);
			if (it != v.end()) continue;

			v.push_back(i);
			int m = (g + v[2] + i) / 10;
			fourth(t / 10, m);
			v.pop_back();
		}
	}
}

void second(int t, int g) {
	for (int i = 0; i < 10; i++) {
		if ((g + 2 * i) % 10 == t % 10) {
			auto it = find(v.begin(), v.end(), i);
			if (it != v.end()) continue;

			v.push_back(i);
			int m = (g + 2 * i) / 10;
			third(t / 10, m);
			v.pop_back();
		}
	}
}

void first() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if ((i + j) % 10 == N % 10 && i != j) {
				v.push_back(i);
				v.push_back(j);
				int m = (i + j) / 10;
				second(N / 10, m);
				v.pop_back();
				v.pop_back();
			}
	cout << "No Answer\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 재귀로 표현하자 back tracking으로
	first();
}

/*
vector<vector<int>> v(2); // d o

	int tmp = N;
	bool deter = true;
	int pivot = tmp % 10; tmp /= 10;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (pivot == (i + j) % 10) {
				v[1].push_back(i);
				v[0].push_back(j);
				deter = false;
			}
		}
	}
	if (deter) {
		cout << "No Answer\n";
		return;
	}

	while (!v[0].empty() && !v[1].empty()) {
		int all = tmp;

		pivot = all % 10; all /= 10;

		int o{ v[1].front() }, d{ v[0].front() }, l, r, e, h, w;
		v[1].erase(v[1].begin());
		v[0].erase(v[0].begin());

		int merge = (o + d >= 10 ? 1 : 0);

		for (int i = 0; i < 10; i++) {
			if ((merge + 2 * i) % 10 == pivot) {
				l = i;
				deter = false;
				merge = (merge + 2 * i >= 10 ? 1 : 0);
			}
		}

		if (deter) continue;
		deter = true;
		pivot = all % 10; all /= 10;

		for (int i = 0; i < 10; i++) {
			if ((merge + l + i) % 10 == pivot) {
				r = i;
				deter = false;
				merge = (merge + l + i >= 10 ? 1 : 0);
			}
		}

		if (deter) continue;
		deter = true;
		pivot = all % 10; all /= 10;

		for (int i = 0; i < 10; i++) {
			if ((merge + o + i) % 10 == pivot) {
				e = i;
				deter = false;
				merge = (merge + o + i >= 10 ? 1 : 0);
			}
		}

		if (deter) continue;
		deter = true;
		pivot = all % 10; all /= 10;
	}

	cout << "No Answer\n";
*/