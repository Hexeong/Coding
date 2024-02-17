#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K, M, V;
pair<long long, long long> jrr[300001];
int arr[300001];
priority_queue<long long> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> jrr[i].first >> jrr[i].second;
	for (int i = 0; i < K; i++) cin >> arr[i];

	sort(jrr, jrr + N); // ���� ���� ���� ����
	sort(arr, arr + K); // ���� ���� ���� ����

	long long total = 0;
	int idx = 0;
	for (int i = 0; i < K; i++) { // ��� ������ ���鼭
		while (idx < N && jrr[idx].first <= arr[i]) pq.push(jrr[idx++].second);
		// i ��° ���濡 ���� �� �ִ� ��� ������ �ִ���
		if (!pq.empty()) {
			total += pq.top();
			pq.pop();
		}
	}

	cout << total << "\n";
}