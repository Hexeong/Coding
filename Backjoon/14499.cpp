#include <iostream>

using namespace std;

int N, M, x, y, K;

int dice[6][2][2] = {
	{ // 1
		{5, 2}, {4, 3} // ver, hor
	},
	{ // 2
		{1, 6}, {4, 3}
	},
	{ // 3
		{5, 2}, {1, 4}
	},
	{ // 4
		{5, 2}, {3, 1}
	},
	{ // 5
		{6, 1}, {4, 3}
	},
	{ // 6
		{2, 5}, {4, 3}
	},
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;



	return 0;
}