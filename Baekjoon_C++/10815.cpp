#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, tmp;

long long arr[500000];

vector<int> ans;

void Binary(int start, int end, long long goal) {
	if (start > end) {
		ans.push_back(0);
		return;
	}

	int index = (start + end) / 2;
	if (arr[index] > goal) {
		Binary(start, index - 1, goal);
	}
	else if (arr[index] < goal) {
		Binary(index + 1, end, goal);
	}
	else {
		ans.push_back(1);
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp; Binary(0, N - 1, tmp);
	}
	
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << "\n";
}