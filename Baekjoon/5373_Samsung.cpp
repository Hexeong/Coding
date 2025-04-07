// https://www.acmicpc.net/problem/5373
#include <iostream>

using namespace std;

int T, N;

char cube[6][3][3]; // 위, 앞, 아래, 뒤, 오, 왼

int faceToIndex(char face) {
    switch (face) {
        case 'U': return 0;
        case 'F': return 1;
        case 'D': return 2;
        case 'B': return 3;
        case 'R': return 4;
        case 'L': return 5;
    }
    return -1;
}

void rotate_surface(int surface, char direction) {
    char tmp[3][3];
    if (direction == '+') {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = cube[surface][2 - j][i];
            }
    }
    else {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = cube[surface][j][2 - i];
            }
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cube[surface][i][j] = tmp[i][j];
        }
}

void rotate_side(int surface, char direction) { // 위, 앞, 아래, 뒤, 오, 왼
    char tmp[3];
    if (surface == 0) {
        // 윗면을 돌릴 경우 : 앞면의 1행, 오른쪽면의 1행, 뒷면의 1행, 왼쪽면의 1행
        // 뒷, 오, 앞, 왼
        if (direction == '+') {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[3][2][i];
            for (int i = 0; i < 3; i++) cube[3][2][i] = cube[5][0][2 - i];
            for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[1][0][2 - i];
            for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[4][0][2 - i];
            for (int i = 0; i < 3; i++) cube[4][0][2 - i] = tmp[i];
        }
        else {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[3][2][i];
            for (int i = 0; i < 3; i++) cube[3][2][i] = cube[4][0][2 - i];
            for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
            for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[5][0][2 - i];
            for (int i = 0; i < 3; i++) cube[5][0][2 - i] = tmp[i];
        }
    } else if (surface == 2) {
        // 아랫면을 돌릴 경우 : 앞면의 3행, 오른쪽의 3열, 뒷면의 3열, 왼쪽면의 3열
        // 앞 오 뒷 왼
        if (direction == '+') {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[1][2][i];
            for (int i = 0; i < 3; i++) cube[1][2][i] = cube[5][2][i];
            for (int i = 0; i < 3; i++) cube[5][2][i] = cube[3][0][2 - i];
            for (int i = 0; i < 3; i++) cube[3][0][2 - i] = cube[4][2][i];
            for (int i = 0; i < 3; i++) cube[4][2][i] = tmp[i];
        }
        else {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[1][2][i];
            for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
            for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][0][2 - i];
            for (int i = 0; i < 3; i++) cube[3][0][2 - i] = cube[5][2][i];
            for (int i = 0; i < 3; i++) cube[5][2][i] = tmp[i];
        }
    } else if (surface == 1) {
        // 앞면을 돌릴 경우 : 윗면의 3행, 오른쪽의 1열, 아랫면의 1행, 왼쪽면의 3열
        // 윗, 오, 밑, 왼
        if (direction == '+') {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[0][2][i];
            for (int i = 0; i < 3; i++) cube[0][2][i] = cube[5][2 - i][2];
            for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[2][0][2 - i];
            for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[4][i][0];
            for (int i = 0; i < 3; i++) cube[4][i][0] = tmp[i];
        }
        // 윗 왼 밑 오
        else {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[0][2][i];
            for (int i = 0; i < 3; i++) cube[0][2][i] = cube[4][i][0];
            for (int i = 0; i < 3; i++) cube[4][i][0] = cube[2][0][2 - i];
            for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[5][2 - i][2];
            for (int i = 0; i < 3; i++) cube[5][2 - i][2] = tmp[i];
        }
    } else if (surface == 3) {
        // 뒷면을 돌릴 경우 : 아랫면의 3행, 오른쪽면의 3열, 윗면의 1행, 왼쪽면의 1열
        // 밑, 오, 윗, 왼
        if (direction == '+') {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[2][2][i];
            for (int i = 0; i < 3; i++) cube[2][2][i] = cube[5][i][0];
            for (int i = 0; i < 3; i++) cube[5][i][0] = cube[0][0][2 - i];
            for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[4][2 - i][2];
            for (int i = 0; i < 3; i++) cube[4][2 - i][2] = tmp[i];
        }
        // 윗 왼 밑 오
        else {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[2][2][i];
            for (int i = 0; i < 3; i++) cube[2][2][i] = cube[4][2 - i][2];
            for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[0][0][2 - i];
            for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[5][i][0];
            for (int i = 0; i < 3; i++) cube[5][i][0] = tmp[i];
        }
    } else if (surface == 4) {
        // 오른쪽면을 돌릴 경우 : 윗면의 3열, 뒷면의 3열, 아랫면의 3열, 앞면의 3열
        // 윗, 앞, 아래, 뒷
        if (direction == '+') {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[0][2 - i][2];
            for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[1][2 - i][2];
            for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[2][2 - i][2];
            for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[3][2 - i][2];
            for (int i = 0; i < 3; i++) cube[3][2 - i][2] = tmp[i];
        }
        // 윗 왼 밑 오
        else {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[0][2 - i][2];
            for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[3][2 - i][2];
            for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[2][2 - i][2];
            for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[1][2 - i][2];
            for (int i = 0; i < 3; i++) cube[1][2 - i][2] = tmp[i];
        }
    } else if (surface == 5) {
        // 왼쪽 면을 돌릴 경우 : 윗면의 3열, 앞면의 3열, 아랫면의 3열, 뒷면의 3열
        // 윗, 앞, 아래, 뒷
        if (direction == '+') {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[0][i][0];
            for (int i = 0; i < 3; i++) cube[0][i][0] = cube[3][i][0];
            for (int i = 0; i < 3; i++) cube[3][i][0] = cube[2][i][0];
            for (int i = 0; i < 3; i++) cube[2][i][0] = cube[1][i][0];
            for (int i = 0; i < 3; i++) cube[1][i][0] = tmp[i];
        }
        // 윗 왼 밑 오
        else {
            for (int i = 0; i < 3; i++)
                tmp[i] = cube[0][i][0];
            for (int i = 0; i < 3; i++) cube[0][i][0] = cube[1][i][0];
            for (int i = 0; i < 3; i++) cube[1][i][0] = cube[2][i][0];
            for (int i = 0; i < 3; i++) cube[2][i][0] = cube[3][i][0];
            for (int i = 0; i < 3; i++) cube[3][i][0] = tmp[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char color[] = {'w', 'r', 'y', 'o', 'b', 'g'};

    cin >> T;
    while (T--) {
        // 큐브 초기화
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = color[i];

        cin >> N;
        for (int i = 0; i < N; i++) {
            string surfaceToRotate;
            cin >> surfaceToRotate;

            rotate_surface(faceToIndex(surfaceToRotate[0]), surfaceToRotate[1]);
            rotate_side(faceToIndex(surfaceToRotate[0]), surfaceToRotate[1]);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << cube[0][i][j];
            cout << endl;
        }
    }

    return 0;
}