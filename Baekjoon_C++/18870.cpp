#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> inp, arr;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp; scanf("%d", &tmp);
		inp.push_back(tmp);
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int a : inp) {
		int pos = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
		printf("%d ", pos);
	}
	return 0;
}