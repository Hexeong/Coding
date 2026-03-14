#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001][3]; // »¡, ÃÊ , ÆÄ

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	int a, b, c;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		arr[i][0] = a + min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] = b + min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] = c + min(arr[i - 1][0], arr[i - 1][1]);
	}

	cout << min(arr[N][0], min(arr[N][1], arr[N][2])) << "\n";
}