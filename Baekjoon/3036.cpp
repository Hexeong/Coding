#include <iostream>

using namespace std;

int N;

int radius[100];
pair<int, int> rolling[100];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> radius[i];

	for (int i = 1; i < N; i++) {
		int gcd_num = gcd(radius[0], radius[i]);
		rolling[i].first = radius[0] / gcd_num;
		rolling[i].second = radius[i] / gcd_num;
	}

	for (int i = 1; i < N; i++) {
		cout << rolling[i].first << "/" << rolling[i].second << "\n";
	}
}