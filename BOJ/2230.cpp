#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int mini;

long long arr[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int i{ 0 }, j{ 0 };
	int dif;
	while (i < N) {
		dif = arr[j] - arr[i];
		if (dif >= M) {
			if (mini == 0) mini = dif;
			else mini = min(mini, dif);
			
			i++;
		}
		else {
			j++;
		}
	}

	cout << mini << "\n";
}