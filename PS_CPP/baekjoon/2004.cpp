#include <iostream>

using namespace std;

int n, m;

long long two{ 0 }, five{ 0 };

long long diver(int a, int b) {
	int num = 0;
	for (long long i = b; a / i >= 1; i *= b) num += a / i;
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	two = diver(n, 2) - diver(n - m, 2) - diver(m, 2);
	five = diver(n, 5) - diver(n - m, 5) - diver(m, 5);
	
	cout << min(five, two) << "\n";
}