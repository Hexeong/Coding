#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<long long, long long> arr[200001];
priority_queue<long long, vector<long long>, greater<long long>> v;

bool compare(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + N, compare);

	v.push(arr[0].second);

	for (int i = 1; i < N; i++) {
		if (v.top() <= arr[i].first) {
			v.pop();
			v.push(arr[i].second);
		}
		else v.push(arr[i].second);
	}

	cout << v.size() << "\n";
}

/*

	while (!v.empty()) {
		last = arr[v[0]].second;
		v[0] = -1;
		for (int i = 1; i < v.size(); i++) {
			if (last <= arr[v[i]].first) {
				last = arr[v[i]].second;
				v[i] = -1;
			}
		}
		for (int i = v.size() - 1; i > -1; i--) {
			if (v[i] == -1) v.erase(v.begin() + i);
		}
		cnt++;
	}*/