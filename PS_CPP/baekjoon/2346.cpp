#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N;

struct node {
	int idx, v;
	node* prev;
	node* next;
} Node[1002];

node* cur;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Node[i].v;
		Node[i].idx = i;
		Node[i].prev = &Node[i - 1];
		Node[i].next = &Node[i + 1];
		Node[i + 1].prev = &Node[i];
		Node[i - 1].next = &Node[i];
	}
	Node[1].prev = &Node[N];
	Node[N].next = &Node[1];

	cur = &Node[1];

	while (1) {
		// 출력
		cout << cur->idx << " ";
		if (cur->next == cur) break;

		// Node 지우기
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		int k = cur->v;

		if (k > 0) { // 양수
			while (k--) cur = cur->next;
		}
		else { // 음수
			while (k++) cur = cur->prev;
		}
	}


	return 0;
}