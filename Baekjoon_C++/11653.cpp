#include <iostream>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int div = 2;
	if (N != 1) {
		while (N > 1) {
			if (N % div == 0) {
				cout << div << "\n";
				N /= div;
			}
			else div++;
		}
	}
}