#include <iostream>

using namespace std;

int arr[100001];
int arr_size;
int K, cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> K;

  for (int i = 0; i < K; i++) {
    cin >> arr[arr_size];
    if (arr[arr_size] == 0) {
      arr_size--;
      cnt -= arr[arr_size];
    } else {
      cnt += arr[arr_size];
      arr_size++;
    }
  }

  cout << cnt << '\n';

  return 0;
}