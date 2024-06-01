//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<map>
//#include<queue>
//#define pii pair<int, int>
//
//using namespace std;
//
////지연시간, 역번호를 저장하는 무향그래프
//vector<pii> graph[200005];
//
////역번호,a역명 저장
//map<int, string> stations;
//int INF = 98765432;
//int n, m;
//
//void input() {
//    int stationNum;
//    int lineNum;
//    string stationName;
//    int goTime;
//    int lineFlag = 0;
//    int preStationNum;
//
//    cin >> n >> m;
//
//    for (int i = 0; i < n; i++) {
//        cin >> stationNum >> lineNum >> stationName >> goTime;
//        stations[stationNum] = stationName;
//
//        //다른 호선일 때, 호선 정보, 전 역 정보 저장
//        if (lineFlag != lineNum) {
//            lineFlag = lineNum;
//            preStationNum = stationNum;
//        }
//        //같은 호설일 때, 전 역, 현 역 연결
//        else {
//            graph[stationNum].push_back({ goTime,preStationNum });
//            graph[preStationNum].push_back({ goTime ,stationNum });
//            preStationNum = stationNum;
//        }
//    }
//
//    //두개 이상의 역으로 갈 수 있을 경우 역번호가 작은 역을 먼저 탐색하기 위해 정렬
//    for (int i = 1; i < stations.size(); i++) {
//        sort(graph[i].begin(), graph[i].end());
//    }
//}
//
//void solve() {
//    //지연시간합, 역번호 오름차순 정렬된 우선순위큐
//    priority_queue<pii, vector<pii>, greater<pii>> pq;
//    //시작지점부터 인덱스까지의 지연시간합을 저장
//    vector<int> dst;
//    //인덱스의 전 역을 저장
//    vector<int> par;
//    //B 명령어 입력 시 최단 경로를 출력하기 위해 선언
//    vector<int> ans;
//    char cmd;
//    int start;
//    int end;
//
//    //dst, par, ans 초기화
//    for (int i = 0; i <= stations.size(); i++) {
//        dst.push_back(INF);
//        par.push_back(-1);
//    }
//
//    while (!ans.empty()) {
//        ans.pop_back();
//    }
//
//    cin >> cmd >> start >> end;
//
//    if (cmd == 'A') {
//        pq.push({ 0,start });
//        dst[start] = 0;
//
//        while (!pq.empty()) {
//            //cost가 가장 낮은 것을 pop
//            int cost = pq.top().first;
//            int cur = pq.top().second;
//            pq.pop();
//
//            //목표 지점 도착 시 지연 시간 출력
//            if (cur == end) {
//                cout << cost << "\n";
//                return;
//            }
//
//            for (int i = 0; i < graph[cur].size(); i++) {
//                //주변 역까지의 지연 시간, 역 번호 설정
//                int nxtCost = graph[cur][i].first;
//                int nxt = graph[cur][i].second;
//
//                //해당 역까지의 기존 지연시간보다 더 짧은 지연시간일 때 저장 후 pq에 삽입
//                if (dst[nxt] > nxtCost) {
//                    dst[nxt] = nxtCost;
//                    pq.push({ cost + nxtCost, nxt });
//                }
//            }
//        }
//    }
//    else if (cmd == 'B') {
//        pq.push({ 0,start });
//        par[start] = 0;
//        dst[start] = 0;
//
//        while (!pq.empty()) {
//            //cost가 가장 낮은 것을 pop
//            int cost = pq.top().first;
//            int cur = pq.top().second;
//            pq.pop();
//
//            if (cur == end) {
//                //목표지점부터 출발지점으로 역추적
//                while (par[cur] != 0) {
//                    ans.push_back(cur);
//                    cur = par[cur];
//                }
//                ans.push_back(start);
//
//                cout << ans.size() << " ";
//                for (int i = ans.size() - 1; i >= 0; i--) {
//                    cout << stations[ans[i]] << " ";
//                }
//                cout << "\n";
//
//                return;
//            }
//
//            for (int i = 0; i < graph[cur].size(); i++) {
//                //주변역에 대한 지연 시간, 역번호 저장 
//                int nxtCost = graph[cur][i].first + cost;
//                int nxt = graph[cur][i].second;
//
//                if (dst[nxt] > nxtCost) {
//                    dst[nxt] = nxtCost;
//                    par[nxt] = cur;
//                    pq.push({ nxtCost, nxt });
//                }
//            }
//        }
//    }
//
//    cout << "None\n";
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    input();
//
//    while (m--) {
//        solve();
//    }
//}