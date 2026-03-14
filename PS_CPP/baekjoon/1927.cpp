#include <algorithm>
#include <iostream>

using namespace std;

int N, arr_size;
int heap[100001];

void enqueue(int x) {
  heap[++arr_size] = x;
  int temp = arr_size;
  while (temp > 1) {
    if (heap[temp] < heap[temp / 2]) {
      swap(heap[temp], heap[temp / 2]);
      temp /= 2;
    } else
      break;
  }
}

void dequeue() {
  if (arr_size > 0)
    cout << heap[1] << '\n';
  else {
    cout << 0 << '\n';
    return;
  }

  swap(heap[arr_size], heap[1]);
  arr_size--;
  int temp = 1;

  while (1) {
    if (temp * 2 + 1 <= arr_size) {
      if (heap[temp * 2 + 1] < heap[temp] &&
          heap[temp * 2 + 1] <= heap[temp * 2]) {
        swap(heap[temp * 2 + 1], heap[temp]);
        temp = temp * 2 + 1;
      } else if (heap[temp * 2] < heap[temp] &&
                 heap[temp * 2] < heap[temp * 2 + 1]) {
        swap(heap[temp], heap[temp * 2]);
        temp *= 2;
      } else
        break;
    } else if (temp * 2 <= arr_size) {
      if (heap[temp * 2] < heap[temp]) {
        swap(heap[temp * 2], heap[temp]);
        temp *= 2;
      } else
        break;
    } else
      break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x > 0) {
      enqueue(x);
    } else {
      dequeue();
    }
  }

  return 0;
}