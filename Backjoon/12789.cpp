#include <iostream>
#include <vector>

using namespace std;

vector<int> v; // ���
vector<int> s; // �Է�
vector<int> z; // ���
int p = 1;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		s.push_back(t); 
	}

	while (s.size() != 0 || v.size() != 0) {
		if (v.size() != 0 && v[v.size() - 1] == p) {
			z.push_back(v[v.back()]);
			v.pop_back();
			p++;
		}

		if (s.size() != 0) {
			if (s[0] == p) {
				z.push_back(s[0]);
				s.erase(s.begin());
				p++;
			}
			else {
				v.push_back(s[0]); // �Ѵ� �տ� ���� �� ��η� ������
				s.erase(s.begin());
			}
		}

		if (s.size() == 0  && v[v.size() - 1] != p) {
			cout << "Sad";
			return;
		} // ��������
	}

	if (p == n + 1) cout << "Nice";


	return 0;
}