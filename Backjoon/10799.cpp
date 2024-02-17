#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int result;

string z;

stack<int> steal;

vector<int> razor;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> z;

	for (int i = 0; i < z.size(); i++) {
		if (z[i] == '(') {
			steal.push(i);
		}
		else if (z[i] == ')') {
			if (z[i - 1] == '(') {
				razor.push_back(i - 1);
				steal.pop();
			}
			else {
				int start = steal.top();
				int cnt = 0;
				for (int j = 0; j < razor.size(); j++) {
					if (start <= razor[j] && i >= razor[j]) {
						cnt++;
					}
				}
				result += (cnt + 1);
				steal.pop();
			}
		}
	}

	cout << result << "\n";
}