//
// Created by admin on 2025-08-13.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> edge; // -1 : cycle이 만들어진 것, -2 : cycle이 만들어질 수 없는 것
// cycle 구간에 대해서 idx로 시작 지점을 파악할 수 있다면 cycle의 끝 vertex의 idx - cycle 시작 vertex의 idx를 빼서
// 해당 cycle에 참여한 인원을 구할 수 있다. 이러면 굳이 뒤돌아 오면서 마킹작업이 필요하지 않다.
bool visit[100001];
int root;
int flag;

void dfs(int cur) {
    if (edge[cur] < 0) {
        flag = 2;
        return;
    }
    if (root == edge[cur]) {
        // root와 cur의 다음이 같아 cycle인 경우
        flag = 1;
        edge[cur] = -1;
        return;
    }
    if (visit[edge[cur]]) {
        // root와 cur의 다음이 같진 않지만, root의 다음 노드 중에서 cycle이 이뤄진 경우
        flag = cur == edge[cur] ? 2 : 1;
        root = edge[cur];
        edge[cur] = -1;
        return;
    }

    visit[edge[cur]] = true;
    dfs(edge[cur]);
    visit[edge[cur]] = false;

    if (flag == 1) {
        edge[cur] = -1;
        if (root == cur)
            flag = 2;
    }
    else if (flag == 2)
        edge[cur] = -2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // graph의 cycle 찾기

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        edge.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> edge[i];

        for (int i = 1; i <= n; i++) {
            flag = 0;
            if (edge[i] == -1 && edge[i] == -2) continue;

            root = i;
            dfs(i);
        }

        int result = 0;
        for (int i = 1; i <= n; i++)
            if (edge[i] != -1) result++;

        cout << result << endl;
    }
}