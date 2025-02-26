#include <iostream>
#include <algorithm>

using namespace std;

int N, C;

long long arr[200000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	int start = 0; // 최소 거리
	int end = arr[N - 1] - arr[0]; // 최대 거리
	int result = 0;
	
	while (start <= end) {
		int mid = (start + end) / 2; // 중간
		
		int cnt = 1;
		int prev_house = arr[0]; // 이전 집
		
		for (int i = 1; i < N; i++) {
			if (arr[i] - prev_house >= mid) { // 이전 집과의 거리 
				cnt++;
				prev_house = arr[i];
			}
		}
		
		if (cnt >= C) {
			result = max(result, mid);
			start = mid + 1;
		}
		else end = mid - 1;
	}


	cout << result << "\n";
}

//for (int i = 0; i < N; i++) arr[i] = arr[i + 1] - arr[i]; // i < N - 1
//
//int in = 0, mid;
//for (int i = 0; i < N - C; i++) {
//	// 초기값을 갈수록 더해 가기
//	// 보다 크게 찾기, 못 찾으면 그 예외 처리, 찾으면 max 처리
//	in += arr[i];
//	mid = 0;
//	for (int j = i + 1; j < C - 1; j++) {
//		if (arr[j] >= in || mid >= in) {
//			cnt++;
//			mid = 0;
//		}
//		else mid += arr[j];
//
//		if (cnt == C - 1) break;
//	}
//	if (cnt == C - 1) {
//		maximum = max(maximum, in);
//	}
//}