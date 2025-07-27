#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> res;

void tracking(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++) cout << res[i] << " ";
		cout << "\n";
		return;
	}
	else {
		int temp;
		for (int i = 0; i < arr.size(); i++) {
			temp = arr[i];

			res.push_back(temp);
			arr.erase(arr.begin() + i);
			tracking(n + 1);
			arr.insert(arr.begin() + i, temp);
			res.pop_back();
		}
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.begin() + N);

	tracking(0);

	return 0;
}