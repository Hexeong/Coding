#include <iostream>
#include <algorithm>

using namespace std;

int M, N;

int candy[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	long long sum = -M;

	for (int i = 0; i < N; i++) cin >> candy[i], sum += (long long)candy[i];


	sort(candy, candy + N);
	long long ans = 0;
	for (int n = 0; n < N; n++) {
		long long w = min((long long)candy[n], sum / (N - n));
		ans += w * w;
		sum -= w;
	}

	printf("%lld\n", ans);
}


/*sort(arr, arr + N, compare);

	for (int i = 1; M != 0; i++) {
		long long diff = arr[0] - arr[i];
		for (int j = 0; j < i; j++) {
			if (M >= diff) {
				arr[j] -= diff;
				M -= diff;
			}
			else {
				arr[j] -= M;
				M = 0;
				break;
			}
		}
	}*/


	// 평탄화 작업 필요
//unsigned long long total = 0;
//for (long long i = 0; i < N; i++) {
//	total += arr[i];
//	arr[i] = 0;
//}
//
//while (total > 0) {
//	unsigned long long mean = total / N;
//	if (mean > 0) {
//		for (unsigned long long i = 0; i < N; i++) arr[i] += mean;
//		total %= N;
//	}
//	else {
//		for (unsigned long long i = 0; total > 0; i++) {
//			arr[i]++;
//			total--;
//		}
//	}
//}
//
//for (unsigned long long i = 0; i < N; i++) {
//	result += pow(arr[i], 2);
//}
//
//cout << result << "\n";