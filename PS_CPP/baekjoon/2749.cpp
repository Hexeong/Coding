#include <iostream>

using namespace std;

long long n;
const int M = 1000000;
const int P = 15 * (M / 10);
int fibonacci[P];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n == 0) cout << "0\n";
	else if (n == 1) cout << "1\n";
	else {
		fibonacci[0] = 0; fibonacci[1] = 1;
		for (int i = 2; i < P; i++) {
			fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % M;
		}
		cout << fibonacci[n % P] << "\n";
	}
}