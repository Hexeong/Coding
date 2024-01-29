#include <iostream>
#include <algorithm>

using namespace std;

class information {
public:
	int age;
	string name;
	int seq;
	information() {
	}
	information(int a, string n, int s) {
		age = a;
		name = n;
		seq = s;
	}
};

bool compare(information i, information j) {
	if (i.age == j.age) {
		return i.seq < j.seq;
	}
	else return i.age < j.age;
}

int main() {
	int N; cin >> N;
	information* arr = new information[N];

	for (int i = 0; i < N; i++) {
		int a; string n; cin >> a >> n;
		arr[i] = information(a, n, i + 1);
	}

	sort(&arr[0], &arr[N], compare);

	for (int i = 0; i < N; i++) {
		cout << arr[i].age << " " << arr[i].name << "\n";
	}

}