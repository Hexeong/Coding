// Backjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N, way, c; // 2 >=, 200,000 <=
int seq[200001]; // 순번, 시간, 차선
int tms[200001];
int lns[200001];
queue<int> q[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; char temp; int b; cin >> a >> temp;
        if (temp == 'A') b = 0;
        else if (temp == 'B') b = 1;
        else if (temp == 'C') b = 2;
        else if (temp == 'D') b = 3;
        seq[i] = -1; // 10 0, 10 1
        tms[i] = a;
        lns[i] = b;
    }

    for (int t = 0; t < 1000000001; t++) {
        // 차선에 추가, 같은 시간대에 들어올 차량이 있으면 추가, 시간 단축 용도
        while (t == tms[c]) {
            q[lns[c]].push(c);
            c++;
        }

        if (!(q[0].empty() && q[1].empty() && q[2].empty() && q[3].empty())) { // 차선에 차가 있을 때
            // 4차선 중 차가 나갈 수 있는 경우 : 
                // 차가 2대 나갈 수 있는 경우
                // 차가 1대만 나가는 경우
            int tmp1, tmp2;
            bool ch = true;
            for (int i = 0; i < 4; i++) { // 1 3번 탐색, 2 4 탐색
                tmp1 = (way - 1 + i < 0 ? 3 : (way - 1 + i) % 4);
                tmp2 = (way + i) % 4;

                if (!q[tmp2].empty() && q[tmp1].empty()) { // 오른 쪽 차선이 빈 차선을 찾은 경우
                    seq[q[tmp2].front()] = t;
                    q[tmp2].pop();
                    ch = false;

                    if (i < 2 && !q[(tmp2 + 2) % 4].empty() && q[(tmp1 + 2) % 4].empty()) { // 다른 차선이 함께 통과 가능한 경우
                        seq[q[(tmp2 + 2) % 4].front()] = t;
                        q[(tmp2 + 2) % 4].pop();
                        way = (way + i + 3) % 4;
                    }
                    else way = (way + i + 1) % 4;

                    break;
                }
            }
            // 차가 나갈 수 없는 경우 : 나머지 break걸고 그대로 출력
            if (ch) break;
        }
        else if (c == N) { // 차선에 차가 없고, 들어올 차도 없을 때
            break;
        }
        else { // 차선에 차가 없고, 들어올 차는 있을 때 : 다음 차로 이동 
            t = tms[c] - 1;
        }
    }

    // 출력
    for (int i = 0; i < N; i++) cout << seq[i] << "\n";



    return 0;
}

// int input[1000000001][4]; // 초를 index 삼기, 문제 -> 4byte형 int, 1024MB = int * 256,000,000개까지

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
