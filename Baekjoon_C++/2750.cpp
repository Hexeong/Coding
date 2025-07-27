// heap sort 시도, 2021-07-11
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int heap[1000000], n;

void swap(int i1, int i2) {
	heap[0] = heap[i1];
	heap[i1] = heap[i2];
	heap[i2] = heap[0];
}

void upheap(int cur) {
	if (cur != 1) {
		while (cur / 2 > 0) {
			if (heap[cur] < heap[cur / 2]) {
				swap(cur / 2, cur);
				cur /= 2;
			}
			else break;
		}
	}
}

void downheap(int cur, int size) {
	if (size != 1) {
		if (size == 2) if (heap[2] < heap[1]) swap(1, 2);

		while (cur * 2 + 1 <= size) {
			if (heap[cur * 2 + 1] < heap[cur * 2]) {
				if (heap[cur * 2 + 1] < heap[cur]) {
					swap(cur * 2 + 1, cur);
					cur = cur * 2 + 1;
				}
				else break;
			}
			else {
				if (heap[cur * 2] < heap[cur]) {
					swap(cur * 2, cur);
					cur = cur * 2;
				}
				else break;
			}
		}
	}
}

void heapif() {
	int tmp = 1;
	while (tmp <= n) {
		upheap(tmp);
		tmp++;
	}
}

void removeMin() {
	int size = n;

	while (size >= 1) {
		cout << heap[1] << "\n";
		swap(1, size);
		size--;
		
		downheap(1, size);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> heap[i];
	}

	heapif(); // O(nlogn)

	removeMin(); // O(nlogn)
}

//void swap(vector<int>& v, int i1, int i2) {
//	v[0] = v[i1];
//	v[i1] = v[i2];
//	v[i2] = v[0];
//}
//
//void insert(vector<int>& v, int& k, int& s) {
//	v.push_back(k);
//	s++;
//
//	int idx = s;
//	while (idx > 0 && v[idx] < v[idx / 2]) {
//		swap(v, idx, idx / 2);
//		idx /= 2;
//	}
//}
//
//int removeMin(vector<int>& v, int& s) {
//	int tmp = v[1];
//	v[1] = v[s];
//	v.pop_back();
//	s--;
//
//	if (2 == s) {
//		if (v[2] < v[1]) {
//			swap(v, 2, 1);
//		}
//	}
//
//	int i = 1;
//	while (2 * i + 1 <= s) {
//		if (v[2 * i + 1] < v[2 * i]) {
//			if (v[2 * i + 1] < v[i]) {
//				swap(v, 2 * i + 1, i);
//				i = 2 * i + 1;
//			}
//			else break;
//		}
//		else {
//			if (v[2 * i] < v[i]) {
//				swap(v, 2 * i, i);
//				i = 2 * i;
//			}
//			else break;
//		}
//	}
//
//	return tmp;
//}
//
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//	vector<int> v;
//	v.push_back(0);
//	int N, s; s = 0;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		int tmp; scanf("%d", &tmp);
//		insert(v, tmp, s);
//	}
//
//	for (int i = 0; i < N; i++) {
//		int tmp; tmp = removeMin(v, s);
//		printf("%d\n", tmp);
//	}
//}

// top-down 방식