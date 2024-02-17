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

    // 1��
    for (int i = 0; i < N; i++) {
        ans1 += inp[i];
    }
    double re = (double)ans1 / (double)N;
    int res = floor(re + 0.5);

    // 2��, ��ü ���� �Լ����� ���� �Լ��� �λ��� �����Լ� ��, �ؿ��� �ᵵ ������ ����
    //int* check = new int[N];
    //for (int i = 0; i < N; i++) { // ���� 1�ܰ�, selection sort
    //    check[i] = inp[i];
    //}
    //for (int i = 0; i < N; i++) { // ���� 2�ܰ�
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

    // 3��
    int count[8001] = { 0 };
    vector<int> v;
    for (int i = 0; i < N; i++) {
        count[inp[i] + 4000]++; // index 1���� ������ �ȴ�
    }
    int max{ 0 }, max_count{ 0 };
    for (int i = 0; i < N; i++) {
        if (count[inp[i] + 4000] > max_count) {
            max = inp[i];
            max_count = count[inp[i] + 4000];
        }
    }
    v.push_back(max); // �ֺ��̸鼭 ���� ���� ��
    for (int i = 0; i < N; i++) {
        if (max_count == count[inp[i] + 4000] && max != inp[i]) { // �ߺ����� �ʰ� ���� ���� ���ڵ��� �����ϱ� ����
            v.push_back(inp[i]);
            max = inp[i];
        }
    } // �̹� ���ĵǾ� �ֱ� ������ sort �ʿ� ����

    // 4��, inp[N-1] - inp[0]

    printf("%d\n%d\n%d\n%d\n", res, inp[(N - 1) / 2], (v.size() == 1 ? v[0] : v[1]), inp[N - 1] - inp[0]);
}