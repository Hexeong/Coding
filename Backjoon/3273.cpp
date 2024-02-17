#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
// 2^17 = 131072
int h[131073];
int res = 0;
int n, hn;

void heapsort() {
	// heap�� �ֱ�
	hn = 0;
	for (int i = 0; i < n; i++) {
		hn++;
		h[hn] = a[i];

		int temp = hn;
		// �ּ� ���� Ʈ��
		while (temp != 1) {
			if (h[temp] < h[temp / 2]) {
				// swap
				h[0] = h[temp];
				h[temp] = h[temp / 2];
				h[temp / 2] = h[0];
			}
			else {
				break;
			}
			temp /= 2;
		}
	}

	// heap���� ����
	int j = 0;
	while (hn > 0) {
		a[j] = h[1];
		h[1] = h[hn];

		int temp = 1;
		while (temp * 2 <= hn) {
			if (h[temp] > h[temp * 2] && h[temp * 2] != 0) {
				if (h[temp] > h[temp * 2 + 1] && h[temp * 2 + 1] != 0) {
					if (h[temp * 2 + 1] < h[temp * 2]) {
						h[0] = h[temp];
						h[temp] = h[temp * 2 + 1];
						h[temp * 2 + 1] = h[0];
						temp = temp * 2 + 1;
					}
					else {
						h[0] = h[temp];
						h[temp] = h[temp * 2];
						h[temp * 2] = h[0];
						temp *= 2;
					}
				}
				else {
					h[0] = h[temp];
					h[temp] = h[temp * 2];
					h[temp * 2] = h[0];
					temp *= 2;
				}
			}
			else {
				break;
			}
		}
		j++;
		hn--;
	}
}

int main() {
	// �迭 ����
	// i1, i2 => 
	// i1 + i2 > x : i2--;
	// i1 + i2 < x :
	//   i1++;
	// i1 + i2 == x :
	//   i2--; res++;
	// ���� ���� : i1 == i2

	cin >> n;
	int i1{ 0 }, i2{ n - 1 };
	for (int i = 0; i < n; i++) cin >> a[i];
	int x; cin >> x;

	// �迭 ���� �ʿ� O(n^2)? O(nlogn)?
	// N = 100,000,000 �϶� O(n)�� 1��

	// heapsort();, sort�� ���� O(nlogn)�� �Ǿ� ��
	sort(a, a + n);

	while (i1 != i2) {
		if (a[i1] + a[i2] > x) i2--;
		else if (a[i1] + a[i2] < x) i1++;
		else {
			res++;
			i2--;
		}
	}

	cout << res << "\n";

	return 0;
}

// 1 2 3 5 7 9 10 11 12
// 1 12; res
// 1 11
// 2 11; res
// 2 10
// 3 10; res
// 3 9
// 5 9
// 5 7
// 7 7; ����