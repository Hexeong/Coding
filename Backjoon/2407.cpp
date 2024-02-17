#include <iostream>
#include <string>
#include <algorithm>

// 큰 숫자 땜시 참고를 좀 했습니다...

using namespace std;

int n, m;
string factorial[101][101];

string add(string n1, string n2)
{
    int s = 0;
    string r;

    while (!n1.empty() || !n2.empty() || s)
    {
        if (!n1.empty())
        {
            s += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty())
        {
            s += n2.back() - '0';
            n2.pop_back();
        }
        r.push_back((s % 10) + '0');
        s /= 10;
    }

    reverse(r.begin(), r.end());
    return r;
}

string C(int n, int r) {
	if (n == r || r == 0) return "1";
	string& res = factorial[n][r];

    if (res != "") return res;

    res = add(C(n - 1, r - 1), C(n - 1, r));
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

    cout << C(n, m) << "\n";
}