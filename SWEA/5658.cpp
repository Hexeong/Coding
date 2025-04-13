#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

int number[28]; 
// 보물 상자의 변은 4개
// 보물상자의 비밀번호는 보물 상자에 적힌 숫자로 만들 수 있는 모든 수 중,
// K번째로 큰 수를 10진수로 만든 수
unordered_map<int, bool> keys;
vector<int> key_order;

int N, K, T;
int start_point = 0;

void rotate(int K) {
	for (int i = 0; i < N / 4; i++) { // N / 4번째 회전부터는 0번째 회전으로 생긴 키와 동일하기 때문
		// key 생성
		int base_point = 0; // 기존 변이 나타내는 곳
		for (int j = 0; j < 4; j++) { // 4개의 변에 대해서 
			int key = 0;

			for (int k = 0; k < N / 4; k++) { // 각 변에 대해 10진수 값들로 생성
				key += pow(16, N / 4 - 1 - k) * number[(start_point + base_point + k) % N];
			}

			// 중복 확인 및 key 추가;
			if (!keys.count(key)) {
				keys[key] = true;
				key_order.push_back(key);
			}

			// 다음 변을 위한 연산
			base_point += N / 4;
		}
		start_point = (start_point + N - 1) % N;
	}
}

bool compare(int& a, int& b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		start_point = 0;
		key_order.clear();
		keys.clear();

		cin >> N >> K;
		string s; cin >> s;
		for (int i = 0; i < N; i++)
			number[i] = (s[i] >= 'A' && s[i] <= 'F' ? s[i] - 'A' + 10 : s[i] - '0');

		rotate(K);
		sort(key_order.begin(), key_order.end(), compare);

		cout << '#' << i << " " << key_order[K - 1] << "\n";
	}
}