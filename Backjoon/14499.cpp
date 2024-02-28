#include <iostream>
#include <algorithm>

using namespace std;

int N, M, x, y, K;
int order[1000];
int map[20][20];
int bottom = 6;

int dice[6] = { 1, 2, 3, 4, 5, 6 };
// 1, 3, 4, 6 - 동 서
// 1, 2, 5, 6 - 북 남

bool check(int o) {
	if (o == 1) {
		if (x == N - 1) return true;
		else return false;
	}
	else if (o == 2) {
		if (x == 0) return true;
		else return false;
	}
	else if (o == 3) {
		if (y == 0) return true;
		else return false;
	}
	else {
		if (y == M - 1) return true;
		else return false;
	}
}

void roll(int o) {
	if (o == 1) {
		x++;
		int temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[5];
		dice[5] = temp;
	}
	else if (o == 2) {
		x--;
		int temp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[2];
		dice[2] = temp;
	}
	else if (o == 3) {
		y--;
		int temp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[1];
		dice[1] = temp;
	}
	else {
		y++;
		int temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[5];
		dice[5] = temp;
	}
}

void revert() {
	if (map[x][y] == 0) {
		// bottom == dice[5]
		map[x][y] = dice[5];
	}
	else {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		cin >> map[i][j];
	}

	for (int i = 0; i < K; i++) {
		cin >> order[i];
		if (check(order[i])) { // 밖으로 넘어가는지 check
			continue;
		}
		// 주사위 굴리기
		roll(order[i]);
		// 값 변환
		revert();
		// 값 출력
		cout << dice[0] << "\n";
	}



	return 0;
}