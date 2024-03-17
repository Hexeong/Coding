#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int res;

char field[12][6];
bool check[12][6];

queue<pair<int, int>> q;
vector<pair<int, int>> st;

bool checking(int o, int x, int y, char c) {
	if (o == 1) {
		return (x > 0 && !check[x][y] && field[x][y] == c);
	}
	else if (o == 2) {
		return (x < 11 && !check[x][y] && field[x][y] == c);
	}
	else if (o == 3) {
		return (y > 0 && !check[x][y] && field[x][y] == c);
	}
	else if (o == 4) {
		return (y < 5 && !check[x][y] && field[x][y] == c);
	}
	return true;
}

void BFS(pair<int, int> p) {
	q.push(p);

	char first = field[p.first][p.second];
	while (!q.empty()) {
		pair<int, int> loc = q.front();
		q.pop();

		// loc.first - 1 > 0 && !check[loc.first - 1][loc.second] && field[loc.first - 1][loc.second] != '.'
		// check 함수 필요
		if (checking(1, loc.first - 1, loc.second, first)) {
			q.push(make_pair(loc.first - 1, loc.second));
			check[loc.first - 1][loc.second] = true;
			st.push_back(make_pair(loc.first - 1, loc.second));
		}
		else if (checking(2, loc.first + 1, loc.second, first)) {
			q.push(make_pair(loc.first + 1, loc.second));
			check[loc.first + 1][loc.second] = true;
			st.push_back(make_pair(loc.first + 1, loc.second));
		}
		else if (checking(3, loc.first, loc.second - 1, first)) {
			q.push(make_pair(loc.first, loc.second - 1));
			check[loc.first][loc.second - 1] = true;
			st.push_back(make_pair(loc.first, loc.second - 1));
		}
		else if (checking(4, loc.first, loc.second + 1, first)) {
			q.push(make_pair(loc.first, loc.second + 1));
			check[loc.first][loc.second + 1] = true;
			st.push_back(make_pair(loc.first, loc.second + 1));
		}
	}

	// 처리 구문
	if (st.size() >= 4) {
		// 위치 없애기
		for (int i = 0; i < st.size(); i++) {
			field[st[i].first][st[i].second] = '.';
			check[st[i].first][st[i].second] = false;
		}



		// 연쇄 횟수 ++
		res++;
	}
}

// 시작점 찾기
pair<int, int> find_start() {
	for (int i = 11; i > -1; i--) for (int j = 0; j < 6; j++) {
		if (field[i][j] != '.' && !check[i][j]) return make_pair(i, j);
	}
	return make_pair(-1, -1);
}

int mains() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 12; i++) {
		string s; cin >> s;
		for (int j = 0; j < 6; j++) field[i][j] = s[j];
	}

	pair<int, int> temp;
	// 시작점 찾기 11, 0
	temp = find_start();
	// while 더 안터질 때까지
	while (temp.first != -1) {
		// 시작점부터 돌리기
		// true : 뿌요 재배치
		BFS(temp);
		// false : 다른 시작점 찾기, 없음 break;
		temp = find_start();
	}

	cout << res << "\n";

	return 0;
}