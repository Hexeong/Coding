#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string i, string j) {
	if (i.size() == j.size()) {
		for (int x = 0; x < i.size(); x++) {
			if (i[x] != j[x]) return i[x] < j[x];
		}
		return false;
	}
	else return i.size() < j.size();
}

int main() {
	int N; cin >> N;
	string* arr = new string[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(&arr[0], &arr[N], compare);

	string s = "";
	for (int i = 0; i < N; i++) {
		if (i != 0) s = arr[i - 1];
		if (s != arr[i]) cout << arr[i] << "\n";
	}
}