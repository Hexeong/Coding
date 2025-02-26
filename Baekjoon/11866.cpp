// No. 11866
#include <iostream>

using namespace std;

int arr[1001];
bool check[1001];

int N, K, arr_size, base, i;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  while (arr_size < N) {
    base++;
    if (base == K && !check[i]) { // 제거하지 않은 수 일 때
      check[i] = true;
      arr[arr_size] = i + 1; // 제거된 순서대로 저장하기
      arr_size++;
      base = 0;
    } else if (check[i]) {
      base--; // 제거된 수일 경우 카운트 하지 않기
    }

    // 다음 단계로 넘어가기
    i++;
    if (i >= N)
      i %= N;
  }

  cout << "<" << arr[0];
  for (int i = 1; i < N; i++)
    cout << ", " << arr[i];
  cout << ">\n";

  return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int q[1001];
// int arr[1001];
// int N, K, size;

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   cin >> N >> K;

//   for(int i = 1; i<=N; i++) q.push_back(i);

//   int base = 0;
//   while(size < N) {
//     base++;
//     if(base != K) {
//       // 뒤로 보내기
//     } else {
//       // 빼서 arr에 순서대로 저장하기
//       arr[size] =
//       base = 0;
//     }
//   }

//   return 0;
// }
