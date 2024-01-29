#include <iostream>
#include <vector>

using namespace std;

int N, res, x, y;
bool check_colum[14][14];
bool c, d;

void func(int cnt) { // cnt ��ü�� row(����) üũ
	if (cnt == N) {
		res++;
		return;
	}
	for (int i = 0; i < N; i++) {
		d = true;
		for (int k = 0; k < cnt; k++) {
			if (check_colum[k][i] == true) {
				d = false;
				break;
			}
		}
		if (d == true) {// colum(����) üũ ����
			c = true;
			for (int j = 1; j <= cnt; j++) {
				x = i - j;
				y = i + j;
				if (x >= 0) if (check_colum[cnt - j][x] == true) {
					c = false; break;
				}
				if (y < N) if (check_colum[cnt - j][y] == true) {
					c = false; break;
				}
			}
			if (c == true) { // �밢�� üũ ����
				check_colum[cnt][i] = true;
				func(cnt + 1);
				check_colum[cnt][i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	func(0);

	cout << res << "\n";
	return 0;
}