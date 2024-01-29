#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

class position {
public:
	int x;
	int y;
	position() {
		x = y = NULL;
	}
	position(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool compare(position& i, position& j) {
	if (i.x == j.x) return i.y < j.y;
	else return i.x < j.x;
}

int main() {
	int N; scanf("%d", &N);
	position* arr = new position[N];

	for (int i = 0; i < N; i++) {
		int x, y; scanf("%d %d", &x, &y);
		arr[i] = position(x, y);
	}

	sort(&arr[0], &arr[N], compare);
	
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
}