// No. 10866
#include <iostream>

using namespace std;

int arr[20001];
int N, arr_size, deque_start{10000};

// 9999 + 2 - 1

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  
  cin >> N;
  for(int i = 0; i<N; i++) {
    string s; cin >> s;
    if(s == "push_front") {
      int x; cin >> x;
      arr[--deque_start] = x;
      arr_size++;
    } else if (s == "push_back") {
      int x; cin>> x;
      arr_size++;
      arr[deque_start + arr_size - 1] = x;
    } else if (s == "pop_front") {
      if(arr_size == 0) cout << -1 << '\n';
      else {
        cout << arr[deque_start] << '\n';
        deque_start++; arr_size--;
      }
    } else if (s == "pop_back") {
      if(arr_size == 0) cout << -1 << "\n";
      else {
        cout << arr[deque_start + arr_size - 1] << "\n";
        arr_size--;
      }
    } else if (s == "size") {
      cout << arr_size << "\n";
    } else if (s == "empty") {
      if(arr_size == 0) cout << 1 << '\n';
      else cout << 0 << '\n';
    } else if (s == "front") {
      if(arr_size == 0) cout << -1 << '\n';
      else cout << arr[deque_start] << "\n";
    } else if (s == "back") {
      if(arr_size == 0) cout << -1 << '\n';
      else cout << arr[deque_start + arr_size - 1] << '\n';
    }
  }
  
  return 0;
}