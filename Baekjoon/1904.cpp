#include <iostream>
#include <vector>

using namespace std;

int N;

vector<long long> v = { 0,1,2 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

    long long tmp;
    for (int i = 3; i <= N; i++)
    {
        tmp = v[i - 1] + v[i - 2];
        v.push_back(tmp % 15746);
    }

    cout << v[N] % 15746 << "\n";
}