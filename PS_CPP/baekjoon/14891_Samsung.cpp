// https://www.acmicpc.net/problem/14891
#include <cmath>
#include <iostream>

using namespace std;

bool wheel[4][8]; // true는 S, false는 N
int north_point[4]; // 현재 톱니바퀴 중 12 방향을 가리키는 톱니를 저장
// 맨 처음은 모두 0으로 0번 idx가 12시 방향을 가리킴

void rotate(int cur_wheel, bool direction) { // 시계 방향 = true, 반 시계 방향 = false
    // 돌려야 할 바퀴 판단
    bool toRotate[8] = {false};
    for (int i = cur_wheel; i > 0; i--)
        // 내 기준, 왼쪽의 톱니와의 맞닿은 부분이 다를 때
        if (wheel[i][(north_point[i] + 6) % 8] != wheel[i - 1][(north_point[i - 1] + 2) % 8])
            toRotate[i - 1] = true;
    for (int i = cur_wheel; i < 3; i++)
        // 내 기준, 오른쪽의 톱니와의 맞닿은 부분이 다를 때
        if (wheel[i][(north_point[i] + 2) % 8] != wheel[i + 1][(north_point[i + 1] + 6) % 8])
            toRotate[i + 1] = true;

    // 자기 자신 돌리기
    if (direction)
        north_point[cur_wheel] = (north_point[cur_wheel] + 7) % 8; // 시계방향
    else
        north_point[cur_wheel] = (north_point[cur_wheel] + 1) % 8; // 반시계방향

    // 내 왼쪽 시계들 돌리기
    bool cur_direction = direction;
    for (int i = cur_wheel - 1; i >= 0; i--) {
        if (!toRotate[i])
            break;

        if (cur_direction) // 현재 방향이 시계 방향이면
            north_point[i] = (north_point[i] + 1) % 8; // 반시계방향
        else // 현재 방향이 반시계 방향이면
            north_point[i] = (north_point[i] + 7) % 8; // 시계방향
        cur_direction = !cur_direction;
    }
    // 내 오른쪽 시계들 돌리기
    cur_direction = direction;
    for (int i = cur_wheel + 1; i < 4; i++) {
        if (!toRotate[i])
            break;

        if (cur_direction) // 현재 방향이 시계 방향이면
            north_point[i] = (north_point[i] + 1) % 8; // 반시계방향
        else // 현재 방향이 반시계 방향이면
            north_point[i] = (north_point[i] + 7) % 8; // 시계방향
        cur_direction = !cur_direction;
    }
    int a = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input[4];
    for (int i = 0; i < 4; i++) {
        cin >> input[i];
        for (int j = 0; j < 8; j++)
            wheel[i][j] = input[i][j] - '0';
    }

    int K;
    cin >> K;
    while (K--) {
        int number, direction;
        cin >> number >> direction;
        rotate(number - 1, direction == 1 ? true : false);
    }

    int sum = 0;
    for (int i = 0; i < 4; i++)
        if (wheel[i][north_point[i]])
            sum += pow(2, i);

    cout << sum << endl;

    return 0;
}