#include <iostream>
#include <vector>

using namespace std;

vector<int> deck;
int k;
vector<int> v;

void bt(int cur) {
	if (deck.size() == 6) { // Ãâ·Â
		for (int i = 0; i < 6; i++) cout << deck[i] << " ";
		cout << "\n";
		return;
	}

	while (cur <  k) {
		deck.push_back(v[cur]);
		bt(cur + 1);
		deck.pop_back();
		cur++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> k;
	while (k != 0) {
		int tmp;
		for (int i = 0; i < k; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}

		bt(0);
		cout << "\n";

		v.clear();
		cin >> k;
	}
}