#include <iostream>

using namespace std;

int deque[15001];
int N, M, deque_start{501}, arr_size, counting;
int arr[50];

void first_calc() {
  deque_start++;
  arr_size--;
}

void second_calc() {
  int temp = deque[deque_start];
  deque_start++;
  deque[deque_start + arr_size - 1] = temp;
  counting++;
}

void third_calc() {
  int temp = deque[deque_start + arr_size - 1];
  deque_start--;
  deque[deque_start] = temp;
  counting++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    deque[deque_start + i] = i + 1;
  for (int i = 0; i < M; i++)
    cin >> arr[i];
  arr_size = N;
  // 입력 종료

  // 사이즈 중간 이상은 3번째 연산, 중간 이하는 2번째 연산, 1번째가 답일 때
  // 1번째 연산 10 3 <1 2 3 4 5 6 7 8 9 10> 2 9 5
  // temp = 1 -> second : 1 / 3 4 5 6 7 8 9 10 1
  // temp = 6 -> third : 3 / 10 1 3 4 5 6 7 8
  // temp = 4 -> second : 5
  for (int i = 0; i < M; i++) {
    int temp = 0;
    for (int j = 0; j < arr_size; j++) {
      if (deque[deque_start + j] == arr[i]) {
        temp = j;
        break;
      }
    }

    if (temp <= arr_size / 2) { // 전반부에 있을 가정
      for (int j = 0; j < temp; j++)
        second_calc();
    } else { // 후반부에 있다는 가정
      for (int j = 0; j < arr_size - temp; j++)
        third_calc();
    }
    // 맨 앞에 찾고자 하는 수가 있다는 가정
    first_calc();
    // for (int i = 0; i < arr_size; i++)
    //   cout << deque[deque_start + i] << " ";
    // cout << '\n';
    // cout << counting << '\n';
  }

  // 출력 시작
  cout << counting << '\n';

  return 0;
}

// 6 7 8 10 1 3 4
// 1 + 3 + 4

// 9 10 11 1 2 3 4 5 6 7 8
// 2 + 4 +