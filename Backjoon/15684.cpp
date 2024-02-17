#include <iostream>

using namespace std;

int N, M, H, extra;

pair<int, int> horizontal[300];


// ��Ʈ��ŷ ���� 1���� �ɰ� ���� 2�� ���ٰ� �ȵǸ� �ٽ� 1������ ���ƿ�
int back(int line) {
	if (extra > 3) return -1;
	if (line > N) return extra;

	int l = line;
	for (int i = 1; i <= H; i++) {
		for (int j = 0; j < M; j++) {
			if (horizontal[j].first == i && horizontal[j].second == l) {
				l++;
			}
			else if (horizontal[j].first == i && horizontal[j].second == l - 1) {
				l--;
			}
		}
	}

	if (l == line) {
		return back(line + 1);
	}
	else {
		// �߰��غ���
		bool check;
		int cur = M;
		l = line;
		for (int i = 1; i <= H; i++) {
			check = true;
			for (int j = 0; j < M; j++) {
				if (horizontal[j].first == i && horizontal[j].second == l) {
					check = false;
					l++;
				}
				if (horizontal[j].first == i && horizontal[j].second == l - 1) {
					check = false;
					l--;
				}
			}
			if (check) {
				if (l > line) {
					horizontal[M] = make_pair(i, l - 1);
				}
				else {
					horizontal[M] = make_pair(i, l);
				}
				M++;
				extra++;
				break;
			}
		}
		if (cur == M) return -1;
		else return back(line);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b; horizontal[i] = make_pair(a, b);
	}

	cout << back(1) << "\n";
}