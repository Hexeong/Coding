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
////�����ð�, ����ȣ�� �����ϴ� ����׷���
//vector<pii> graph[200005];
//
////����ȣ,a���� ����
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
//        //�ٸ� ȣ���� ��, ȣ�� ����, �� �� ���� ����
//        if (lineFlag != lineNum) {
//            lineFlag = lineNum;
//            preStationNum = stationNum;
//        }
//        //���� ȣ���� ��, �� ��, �� �� ����
//        else {
//            graph[stationNum].push_back({ goTime,preStationNum });
//            graph[preStationNum].push_back({ goTime ,stationNum });
//            preStationNum = stationNum;
//        }
//    }
//
//    //�ΰ� �̻��� ������ �� �� ���� ��� ����ȣ�� ���� ���� ���� Ž���ϱ� ���� ����
//    for (int i = 1; i < stations.size(); i++) {
//        sort(graph[i].begin(), graph[i].end());
//    }
//}
//
//void solve() {
//    //�����ð���, ����ȣ �������� ���ĵ� �켱����ť
//    priority_queue<pii, vector<pii>, greater<pii>> pq;
//    //������������ �ε��������� �����ð����� ����
//    vector<int> dst;
//    //�ε����� �� ���� ����
//    vector<int> par;
//    //B ��ɾ� �Է� �� �ִ� ��θ� ����ϱ� ���� ����
//    vector<int> ans;
//    char cmd;
//    int start;
//    int end;
//
//    //dst, par, ans �ʱ�ȭ
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
//            //cost�� ���� ���� ���� pop
//            int cost = pq.top().first;
//            int cur = pq.top().second;
//            pq.pop();
//
//            //��ǥ ���� ���� �� ���� �ð� ���
//            if (cur == end) {
//                cout << cost << "\n";
//                return;
//            }
//
//            for (int i = 0; i < graph[cur].size(); i++) {
//                //�ֺ� �������� ���� �ð�, �� ��ȣ ����
//                int nxtCost = graph[cur][i].first;
//                int nxt = graph[cur][i].second;
//
//                //�ش� �������� ���� �����ð����� �� ª�� �����ð��� �� ���� �� pq�� ����
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
//            //cost�� ���� ���� ���� pop
//            int cost = pq.top().first;
//            int cur = pq.top().second;
//            pq.pop();
//
//            if (cur == end) {
//                //��ǥ�������� ����������� ������
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
//                //�ֺ����� ���� ���� �ð�, ����ȣ ���� 
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