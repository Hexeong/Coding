#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct page {
    string url;
    bool visited = false;
};

struct link {
    string end;
    int end_idx;
};

int N;
vector<link> graph[1000];
vector<link> graph_t[1000];
page pages[1000];
stack<int> finished;
string result[1000];


void input();
void phase1(int start);
void phase2(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    // phase1 및 중간 정보 출력
    for (int i = 0; i < N; i++)
        if (!pages[i].visited) phase1(i);
    cout << "\n";


    // 다음 DFS를 위한 visited 초기화
    for (int i = 0; i < N; i++) pages[i].visited = false;


    // phase2
    string leader;
    while (!finished.empty()) {
        if (!pages[finished.top()].visited) {
            leader = pages[finished.top()].url;
            phase2(finished.top());
        }
        result[finished.top()] = leader;
        finished.pop();
    }
    for (int i = 0; i < N; i++) cout << result[i] << " ";
    cout << "\n";

    return 0;
}

bool compare_link(link a, link b) {
    return a.end < b.end;
}

bool compare_page(page a, page b) {
    return a.url < b.url;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        page p; cin >> p.url;
        pages[i] = p;
    }
    sort(pages, pages + N, compare_page);

    for (int i = 0; i < N; i++) { // i가 start_idx
        string start, end;
        int end_idx, links;
        cin >> start >> links;
        if (links == 0) continue;

        for (int j = 0; j < links; j++) {
            cin >> end;
            for (int k = 0; k < N; k++) if (pages[k].url == end) {
                end_idx = k;
                break;
            }

            link l; l.end = end; l.end_idx = end_idx;
            graph[i].push_back(l);
            link l_t; l_t.end = start; l_t.end_idx = i;
            graph_t[end_idx].push_back(l_t);
        }
    }

    for (int i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end(), compare_link);
        sort(graph_t[i].begin(), graph_t[i].end(), compare_link);
    }
    
    return;
}

void phase1(int start) {
    pages[start].visited = true; // 방문 완료
    for (int i = 0; i < graph[start].size(); i++) {
        // 이미 방문한 경우 pass
        if (pages[graph[start].at(i).end_idx].visited) continue;
        // 방문하지 않았다면 방문
        phase1(graph[start].at(i).end_idx);
    }
    finished.push(start); // 더 이상 갈 edge가 없을 시 stack에 추가
    cout << pages[start].url << " "; // 중간 정보 출력
}

void phase2(int start) {
    pages[start].visited = true;
    for (int i = 0; i < graph_t[start].size(); i++) {
        if (pages[graph_t[start].at(i).end_idx].visited) continue;
        phase2(graph_t[start].at(i).end_idx);
    }
}