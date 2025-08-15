//
// Created by admin on 2025-08-15.
//
#include <iostream>
#include <stack>

using namespace std;

int M, N, K;
int sec = 0;
bool flag = false;

stack<int> columns[4]; // 기둥

int circle_pos[61]; // 각 원판마다의 위치 저장

void move(int from, int to) {
    sec++; // 시간 counting
    circle_pos[columns[from].top()] = to - 1; // 옮긴 원판의 기둥 위치 저장
    columns[to].push(columns[from].top()); // 옮기기
    columns[from].pop();
}

bool check() {
    if (sec == K) { // K초가 되었을 때의 원판마다의 위치 출력 후 종료
        for (int i = 1; i <= N; i++)
            cout << circle_pos[i] + 1 << " ";
        flag = true;
        return true;
    }
    return false;
}

void hanoi_one(int n, int from, int middle, int to) {
    if (n == 0 || flag)
        return;

    hanoi_one(n - 1, from, to, middle);

    if (flag) return;
    move(from, to);
    if (check()) return;

    hanoi_one(n - 1, middle, from, to);
}

void hanoi_two(int n, int from, int middle, int to) {
    if (n == 0 || flag)
        return;

    hanoi_two(n - 1, from, middle, to);

    if (flag) return;
    if (abs(from - middle) == 2) {
        move(from, to);
        if (check()) return;
        move(to, middle);
    } else
        move(from, middle);
    if (check()) return;

    hanoi_two(n - 1, to, middle, from);

    if (flag) return;
    if (abs(middle - to) == 2) {
        move(middle, from);
        if (check()) return;
        move(from, to);
    } else
        move(middle, to);
    if (check()) return;

    hanoi_two(n - 1, from, middle, to);
}

void hanoi_three(int n, int from, int middle, int to) {
    if (flag) return;
    if (n == 1) {
        if (from < to) { // (1, 2), (1, 3), (2, 3)
            if (abs(from - to) == 2) {
                move(from, middle);
                if (check()) return;
                move(middle, to);
            } else
                move(from, to);
        } else {
            if (abs(from - to) == 2) // (2, 1), (3, 1), (3, 2)
                move(from, to);
            else {
                move(from, middle);
                if (check()) return;
                move(middle, to);
            }
        }
        return;
    }

    hanoi_three(n - 1, from, middle, to);

    if (flag) return;
    if (from < middle) { // (1, 2), (1, 3), (2, 3)
        if (abs(from - middle) == 2) {
            move(from, to);
            if (check()) return;
            move(to, middle);
        } else
            move(from, middle);
    } else {
        if (abs(from - middle) == 2) // (2, 1), (3, 1), (3, 2)
            move(from, middle);
        else {
            move(from, to);
            if (check()) return;
            move(to, middle);
        }
    }
    if (check()) return;

    hanoi_three(n - 1, to, middle, from);

    if (flag) return;
    if (middle < to) { // (1, 2), (1, 3), (2, 3)
        if (abs(middle - to) == 2) {
            move(middle, from);
            if (check()) return;
            move(from, to);
        } else
            move(middle, to);
    } else {
        if (abs(middle - to) == 2) // (2, 1), (3, 1), (3, 2)
            move(middle, to);
        else {
            move(middle, from);
            if (check()) return;
            move(from, to);
        }
    }
    if (check()) return;

    hanoi_three(n - 1, from, middle, to);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;

    for (int i = N; i >= 1; i--)
        columns[1].push(i);

    if (M == 1)
        hanoi_one(N, 1, 2, 3);
    else if (M == 2)
        hanoi_two(N, 1, 2, 3);
    else
        hanoi_three(N, 1, 2, 3);
}