#include <iostream>

using namespace std;

bool chess[10][10];
bool visited_right[20];
bool visited_left[20];
int result[2];
int N;

void DFS(int cnt, int x, int y, int color) {
    if (x >= N) {
        y++;
        if (x % 2 == 0) x = 1;
        else x = 0;
    }
    if (y >= N) {
        if (cnt > result[color])
            result[color] = cnt;
        return;
    }

    if (chess[y][x] && !visited_right[x + y + 1] && !visited_left[x - y + N]) {
        visited_right[x + y + 1] = true;
        visited_left[x - y + N] = true;
        DFS(cnt + 1, x + 2, y, color);
        visited_right[x + y + 1] = false;
        visited_left[x - y + N] = false;
    }
    DFS(cnt, x + 2, y, color);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> chess[i][j];

    DFS(0, 0, 0, 0); //검은색 체스판
    DFS(0, 1, 0, 1); //흰색 체스판

    cout << result[0] + result[1] << "\n";
}