#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct page { // page에 대한 구조체 : 
    string url; // page의 주소
    bool visited = false; // page 방문 여부
};

struct link { // link에 대한 구조체 : 
    string end; // edge가 가리키는 정점
    int end_idx; // 그 정점이 배열에서 위치한 index를 멤버 변수
};


int N; // 전체 주소 개수
vector<link> graph[1000]; // graph, index가 시작 page이고, 벡터인 graph[index]에 link 정보가 저장되어 있음
vector<link> graph_t[1000]; // transposed graph
page pages[1000]; // 모든 page에 대한 정보를 저장하는 배열, graph의 벡터들 순서와 pages의 순서가 동일

string leader; // Phase2에서 DFS 중 현재 leader값 저장 객체
stack<int> finished; // finished stack

string result[1000]; // 사전 순대로 출력하기 위해 SCC 결과가 저장된 배열


void input(); // input 값을 받는 함수
void phase1(int start); // phase1용 DFS 함수
void phase2(int start); // phase2용 DFS 함수

int main()
{
    // C 표준 stream과 C++ 표준 스트림의 동기화를 끊어 독립적인 버퍼를 사용으로 시간 감소
    ios::sync_with_stdio(false);
    // 입출력 소모 시간 감소를 위한 코드
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 함수 아래에 구현
    input();

    // phase1
    for (int i = 0; i < N; i++) // 모든 정점에 대해 DFS 순회
        if (!pages[i].visited) // 하지만, 이미 방문한 정점은 DFS하지 않기
            phase1(i); // DFS 시작, DFS를 돌면서 중간 정보 출력
    cout << "\n";

    // 다음 DFS를 위한 방문 여부 변수 visited 초기화
    for (int i = 0; i < N; i++) 
        pages[i].visited = false;

    // phase2
    while (!finished.empty()) { // finished stack의 top을 시작 정점으로 하여 DFS 순회
        if (!pages[finished.top()].visited) { // 이미 방문한 정점은 순회하지 않음
            leader = pages[finished.top()].url; // 순회 전 시작 정점을 leader로 지정
            phase2(finished.top()); // DFS 시작
        }
        finished.pop(); // 진행을 위해 pop 실행
    }

    // 결과 출력
    for (int i = 0; i < N; i++) cout << result[i] << " ";
    cout << "\n";

    return 0; // main 함수 종료
}

bool compare_link(link a, link b) { // sort함수를 위한 link 구조체 용 비교 함수
    return a.end < b.end; // link가 가리키는 페이지 주소를 기준으로 사전 순으로 정렬
}

bool compare_page(page a, page b) { // sort함수를 위한 page 구조체 용 비교 함수
    return a.url < b.url; // 페이지 주소를 기준으로 사전 순으로 정렬
}

void input() {

    cin >> N; // 데이터 입력 중 1)에 해당하는 N 입력


    for (int i = 0; i < N; i++) { // 데이터 입력 중 2)에 해당하는 모든 page에 대한 주소 입력
        page p; cin >> p.url; // page 구조체의 url 멤버 변수는 string
        pages[i] = p; // 배열에 저장
    }
    sort(pages, pages + N, compare_page); // N개의 page를 사전 순으로 정렬


    for (int i = 0; i < N; i++) { // 데이터 입력 중 3)에 해당하는 모든 link에 대한 입력
        string start, end; // 현재 page 주소와 link가 가리키는 page 주소를 위한 변수
        int start_idx, end_idx, links; // 현재 page 주소의 index, 가리키는 page 주소의 index, 현재 page의 총 link개수
        cin >> start >> links; // 현재 page 주소와 page의 총 link 개수 입력

        for (int j = 0; j < N; j++) // 입력받은 현재 page 주소가 배열에서 위치한 index를 순차 검색
            if (pages[j].url == start) { // 찾으면 start_idx에 저장 후 break;
                start_idx = j; 
                break;
            }   

        for (int j = 0; j < links; j++) { // link 개수만큼 link가 가리키는 page 주소 입력 받기
            cin >> end; // 가리키는 page 주소 입력
            for (int k = 0; k < N; k++)  // 가리키는 page 주소가 배열에서 위치한 index를 순차 검색
                if (pages[k].url == end) { // 찾으면 end_idx에 저장 후 break;
                    end_idx = k;
                    break;
                }

            link l; // graph에 추가하기 위한 link 변수 l을 생성
            l.end = end; // 멤버 변수에 end page 주소와
            l.end_idx = end_idx; // 그 page의 index를 저장
            graph[start_idx].push_back(l); // graph의 현재 page가 저장된 index에 link를 추가

            link l_t; // transposed graph에 추가하기 위한 link 변수 l_t를 생성, 즉 반대 방향으로의 edge를 생성
            l_t.end = start; // link가 가리키는 page 주소에 start page 주소를,
            l_t.end_idx = start_idx; // link가 가리키는 page index에 start_idx를 저장
            graph_t[end_idx].push_back(l_t); // transposed graph의 end_idx에 반대 방향으로의 link를 추가 
        }
    }

    for (int i = 0; i < N; i++) { // 주소를 기준으로, 각 page에 대한 모든 link들을 사전 순으로 정렬
        sort(graph[i].begin(), graph[i].end(), compare_link);
        sort(graph_t[i].begin(), graph_t[i].end(), compare_link);
    }
    
    return; // input 함수 종료
}

void phase1(int start) { // 재귀 함수로 구현한 DFS, start값은 해당 page의 index 값
    pages[start].visited = true; // 방문 완료
    for (int i = 0; i < graph[start].size(); i++) { // graph에서 현재 page의 모든 link에 대하여 다시 DFS 시작
        // 이미 방문한 경우 pass
        if (pages[graph[start].at(i).end_idx].visited) continue; // 벡터인 graph[start]에서 i번째 link의 index값으로 pages 배열에 접근해 방문 여부 체크
        // 방문하지 않았다면 다시 순회 시작
        phase1(graph[start].at(i).end_idx);
    }
    finished.push(start); // 더 이상 갈 edge가 없을 시 stack에 추가
    cout << pages[start].url << " "; // finished 된 순서대로 중간 정보 출력
}

void phase2(int start) { // 재귀 함수로 구현한 DFS, start값은 해당 page의 index 값
    pages[start].visited = true; // 방문 완료
    result[start] = leader; // 방문 완료와 동시에 leader값을 result 배열의 현재 page의 index값에 저장
    for (int i = 0; i < graph_t[start].size(); i++) { // graph_t에서 현재 page의 모든 link에 대하여 다시 DFS 시작
        // 이미 방문한 경우 pass
        if (pages[graph_t[start].at(i).end_idx].visited) continue; // 벡터인 graph_t[start]에서 i번째 link의 index값으로 pages 배열에 접근해 방문 여부 체크
        // 방문하지 않았다면 다시 순회 시작
        phase2(graph_t[start].at(i).end_idx);
    }
}