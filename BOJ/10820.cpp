#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	while (getline(cin, s)) {

		int a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 };
		for (auto& e : s) {
			if (e >= 65 && e <= 90) a++; // �빮��
			else if (e >= 97 && e <= 122) b++; // �ҹ���
			else if (e >= 48 && e <= 57) c++; // ����
			else if (e == 32) d++; // ����
		}
		cout << b << " " << a << " " << c << " " << d << "\n";
	}
}