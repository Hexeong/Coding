#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int ans1{ 0 };
    int N; scanf("%d", &N);
    int* inp = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &inp[i]);
    }

    // 1번
    for (int i = 0; i < N; i++) {
        ans1 += inp[i];
    }
    double re = (double)ans1 / (double)N;
    int res = floor(re + 0.5);

    // 2번, 자체 정렬 함수보다 내장 함수가 훨빨라서 내장함수 씀, 밑에꺼 써도 정답은 맞음
    //int* check = new int[N];
    //for (int i = 0; i < N; i++) { // 정렬 1단계, selection sort
    //    check[i] = inp[i];
    //}
    //for (int i = 0; i < N; i++) { // 정렬 2단계
    //    int min = 4000; int idx = 0;
    //    for (int j = 0; j < N; j++) {
    //        if (min > check[j]) {
    //            min = check[j];
    //            idx = j;
    //        }
    //    }
    //    check[idx] = 4000;
    //    inp[i] = min;
    //}
    sort(inp, inp + N);

    // 3번
    int count[8001] = { 0 };
    vector<int> v;
    for (int i = 0; i < N; i++) {
        count[inp[i] + 4000]++; // index 1부터 저장이 된다
    }
    int max{ 0 }, max_count{ 0 };
    for (int i = 0; i < N; i++) {
        if (count[inp[i] + 4000] > max_count) {
            max = inp[i];
            max_count = count[inp[i] + 4000];
        }
    }
    v.push_back(max); // 최빈값이면서 가장 작은 수
    for (int i = 0; i < N; i++) {
        if (max_count == count[inp[i] + 4000] && max != inp[i]) { // 중복되지 않고 같은 빈도의 숫자들을 저장하기 위함
            v.push_back(inp[i]);
            max = inp[i];
        }
    } // 이미 정렬되어 있기 때문에 sort 필요 없음

    // 4번, inp[N-1] - inp[0]

    printf("%d\n%d\n%d\n%d\n", res, inp[(N - 1) / 2], (v.size() == 1 ? v[0] : v[1]), inp[N - 1] - inp[0]);
}