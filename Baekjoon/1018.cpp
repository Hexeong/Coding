// 1018.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 패스 제한 시간 2초이고 4중 for문을 써야 되는 것 같아서 하기 싫었음

#include <iostream>

using namespace std;

int main()
{
    int a, b; cin >> a >> b;

    char** v = new char* [a];
    for (int i = 0; i < a; i++) {
        v[i] = new char[b];
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> v[i][j];
        }
    } // 입력 완료

    int min = 65;
    for (int k = 0; k < a - 7; k++) {
        for (int g = 0; g < b - 7; g++) {

            char arr[8][8];
            char brr[8][8];

            int ca{ 0 }, cb{ 0 }; // 오른쪽 맨 위가 W일때 ca, B일때 cb

            for (int j = 0; j < 8; j++) {
                for (int i = 0; i < 8; i++) {
                    arr[j][i] = v[j + k][i + g];
                    brr[j][i] = v[j + k][i + g];
                }
            }

            if (arr[0][0] != 'W') {
                arr[0][0] = 'W';
                ca++;
            }
            if (brr[0][0] != 'B') {
                brr[0][0] = 'B';
                cb++;
            }

            for (int j = 0; j < 8; j++) {

                if (j != 0) {
                    if (arr[j - 1][0] == arr[j][0]) {
                        arr[j][0] = (arr[j - 1][0] == 'W' ? 'B' : 'W');
                        ca++;
                    }
                }

                for (int i = 1; i < 8; i++) {
                    if (arr[j][i] == arr[j][i - 1]) {
                        arr[j][i] = (arr[j][i - 1] == 'W' ? 'B' : 'W');
                        ca++;
                    }
                }
            }

            for (int j = 0; j < 8; j++) {

                if (j != 0) {
                    if (brr[j - 1][0] == brr[j][0]) {
                        brr[j][0] = (brr[j - 1][0] == 'W' ? 'B' : 'W');
                        cb++;
                    }
                }

                for (int i = 1; i < 8; i++) {
                    if (brr[j][i] == brr[j][i - 1]) {
                        brr[j][i] = (brr[j][i - 1] == 'W' ? 'B' : 'W');
                        cb++;
                    }
                }
            }

            if (ca < cb) {
                if (ca < min) min = ca;
            }
            else { 
                if (cb < min) min = cb;
            }
        }
    }

    cout << min << endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


/*brr[0][0] = (brr[0][0] == 'W' ? 'B' : 'W');
    cb++;

    for (int i = 0; i < b; i++) {
        if (i != 0) {
            if (brr[0][i] == brr[0][i - 1]) {
                brr[0][i] = (brr[0][i - 1] == 'W' ? 'B' : 'W');
                cb++;
            }
        }
        for (int j = 1; j < a; j++) {
            if (brr[j][i] == brr[j - 1][i]) {
                brr[j][i] = (brr[j - 1][i] == 'W' ? 'B' : 'W');
                cb++;
            }
        }
    }

    for (int i = 0; i < b; i++) {
        if (i != 0) {
            if (arr[0][i] == arr[0][i - 1]) {
                arr[0][i] = (arr[0][i - 1] == 'W' ? 'B' : 'W');
                ca++;
            }
        }
        for (int j = 1; j < a; j++) {
            if (arr[j][i] == arr[j - 1][i]) {
                arr[j][i] = (arr[j - 1][i] == 'W' ? 'B' : 'W');
                ca++;
            }
        }
    }*/