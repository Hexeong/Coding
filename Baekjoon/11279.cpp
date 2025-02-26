#include <algorithm>
#include <iostream>

using namespace std;

int N, arr_size;
int arr[100001];

void enqueue(int x) {
  arr[++arr_size] = x;
  int temp = arr_size;
  while (temp > 1) {
    if (arr[temp] > arr[temp / 2]) {
      swap(arr[temp], arr[temp / 2]);
      temp /= 2;
    } else {
      break;
    }
  }
}

void dequeue() {
  if (arr_size > 0)
    cout << arr[1] << '\n';
  else {
    cout << 0 << '\n';
    return;
  }

  arr[1] = arr[arr_size];
  arr_size--;

  int temp = 1;

  while (1) {
    if (temp * 2 + 1 <= arr_size) {
      if (arr[temp] < arr[temp * 2] && arr[temp * 2] >= arr[temp * 2 + 1]) {
        swap(arr[temp], arr[temp * 2]);
        temp *= 2;
      } else if (arr[temp] < arr[temp * 2 + 1] &&
                 arr[temp * 2] < arr[temp * 2 + 1]) {
        swap(arr[temp], arr[temp * 2 + 1]);
        temp = temp * 2 + 1;
      } else {
        break;
      }
    } else if (temp * 2 <= arr_size) {
      if (arr[temp] < arr[temp * 2]) {
        swap(arr[temp], arr[temp * 2]);
        temp *= 2;
      } else {
        break;
      }
    } else
      break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    if (x > 0) {
      enqueue(x);
    } else if (x == 0) {
      dequeue();
    }
  }

  return 0;
}