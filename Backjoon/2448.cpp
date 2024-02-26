#include <iostream>

using namespace std;

int N, h;
bool star[6144][6144]; // 6 * 1024(2 ** 10)

void re(int H, int s_h, int s_r) {
	if (H == 1) {
		star[s_h][s_r] = true;
		star[s_h + 1][s_r - 1] = true; star[s_h + 1][s_r + 1] = true;
		for (int i = 0; i < 5; i++) star[s_h + 2][s_r - 2 + i] = true;
	}
	else {
		re(H / 2, s_h, s_r);
		re(H / 2, s_h + H / 2 * 3, s_r - H * 3 / 2);
		re(H / 2, s_h + H / 2 * 3, s_r + H * 3 / 2);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	h = N / 3;

	re(h, 1, 3 * h);

	for (int i = 1; i <= 3 * h; i++) {
		for (int j = 1; j <= 6 * h - 1; j++) {
			cout << (star[i][j] ? '*' : ' ');
		}
		cout << '\n';
	}

	return 0;
}