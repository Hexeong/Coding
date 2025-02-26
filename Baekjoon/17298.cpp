#include <iostream>
#include <utility>

using namespace std;

int arr[1000001]; // 입력 값
int nge[1000001]; // 결과 값
pair<int, int> stacks[1000001]; // 실제 스택
int A, arr_size, max;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A;
  for(int i = 0; i < A; i++) {
    cin >> arr[i];
    
    if(i > 0) {
      while(arr_size > 0 && stacks[arr_size - 1].second < arr[i]) {
        nge[stacks[arr_size - 1].first] = arr[i];
        arr_size--;
      }
    }
    
    stacks[arr_size] = make_pair(i, arr[i]);
    arr_size++;
  }
  
  // 스택에 남아있는 것들은 그것들보다 큰 것을 찾지 못한수
  // 5 9 8 ? 5 는 이미 9 단계에서 사라짐
  // 5 2
  
  while(arr_size > 0) {
    nge[stacks[arr_size - 1].first] = -1;
    arr_size--;
  }

  cout << nge[0];
  for(int i = 1; i<A; i++) {
    cout << ' ' << nge[i];
  }
  cout << '\n';
  
  return 0;
}