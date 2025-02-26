#include <iostream>

using namespace std;

char arr[1000001];
int arr_size, cnt;
string s, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (cnt == t.size()) {
      arr_size -= t.size(); // adbdCC4 ,
      cnt = 0;
      int temp = arr_size - t.size();
      for (int j = 0; j < t.size(); j++) {
        if (t[cnt] == arr[temp + j])
          cnt++;
        else {
          cnt = 0;
          if (t[cnt] == arr[temp + j])
            cnt++;
        }
      }
      i--;
    } else if (cnt < t.size()) {
      if (t[cnt] == s[i])
        cnt++;
      else {
        cnt = 0;
        if (t[cnt] == s[i])
          cnt++;
      }
      arr[arr_size] = s[i];
      arr_size++;
    }
  }

  // 마지막 검사
  if (cnt == t.size())
    arr_size -= t.size();

  // 출력
  if (arr_size == 0)
    cout << "FRULA\n";
  else {
    for (int i = 0; i < arr_size; i++)
      cout << arr[i];
    cout << '\n';
  }

  return 0;
}