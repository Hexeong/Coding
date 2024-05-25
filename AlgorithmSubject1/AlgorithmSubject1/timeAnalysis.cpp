//#include <iostream>
//#include <stack>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct page { // page�� ���� ����ü : 
//    string url; // page�� �ּ�
//    bool visited = false; // page �湮 ����
//};
//
//struct link { // link�� ���� ����ü : 
//    string end; // edge�� ����Ű�� ����
//    int end_idx; // �� ������ �迭���� ��ġ�� index�� ��� ����
//};
//
//
//int N; // ��ü �ּ� ����
//vector<link> graph[1000]; // graph, index�� ���� page�̰�, ������ graph[index]�� link ������ ����Ǿ� ����
//vector<link> graph_t[1000]; // tansposed graph
//page pages[1000]; // ��� page�� ���� ������ �����ϴ� �迭, graph�� ���͵� ������ pages�� ������ ����
//
//string leader; // Phase2���� DFS �� ���� leader�� ���� ��ü
//stack<int> finished; // finished stack
//
//string result[1000]; // ���� ����� ����ϱ� ���� SCC ����� ����� �迭
//
//
//void input(); // input ���� �޴� �Լ�
//void phase1(int start); // phase1�� DFS �Լ�
//void phase2(int start); // phase2�� DFS �Լ�
//
//int main()
//{
//    // C ǥ�� stream�� C++ ǥ�� ��Ʈ���� ����ȭ�� ���� �������� ���۸� ������� �ð� ����
//    ios::sync_with_stdio(false);
//    // ����� �Ҹ� �ð� ���Ҹ� ���� �ڵ�
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    // �Է� �Լ� �Ʒ��� ����
//    input();
//
//    // phase1
//    for (int i = 0; i < N; i++) // ��� ������ ���� DFS ��ȸ
//        if (!pages[i].visited) // ������, �̹� �湮�� ������ DFS���� �ʱ�
//            phase1(i); // DFS ����, DFS�� ���鼭 �߰� ���� ���
//    cout << "\n";
//
//    // ���� DFS�� ���� �湮 ���� ���� visited �ʱ�ȭ
//    for (int i = 0; i < N; i++)
//        pages[i].visited = false;
//
//    // phase2
//    while (!finished.empty()) { // finished stack�� top�� ���� �������� �Ͽ� DFS ��ȸ
//        if (!pages[finished.top()].visited) { // �̹� �湮�� ������ ��ȸ���� ����
//            leader = pages[finished.top()].url; // ��ȸ �� ���� ������ leader�� ����
//            phase2(finished.top()); // DFS ����
//        }
//        finished.pop(); // ������ ���� pop ����
//    }
//
//    // ��� ���
//    for (int i = 0; i < N; i++) cout << result[i] << " ";
//    cout << "\n";
//
//    return 0; // main �Լ� ����
//}
//
//bool compare_link(link a, link b) { // sort�Լ��� ���� link ����ü �� �� �Լ�
//    return a.end < b.end; // link�� ����Ű�� ������ �ּҸ� �������� ���� ������ ����
//}
//
//bool compare_page(page a, page b) { // sort�Լ��� ���� page ����ü �� �� �Լ�
//    return a.url < b.url; // ������ �ּҸ� �������� ���� ������ ����
//}
//
//void input() {
//
//    cin >> N; // 1�ܰ�
//
//    for (int i = 0; i < N; i++) { // 2�ܰ�
//        page p; cin >> p.url;
//        pages[i] = p;
//    }
//    sort(pages, pages + N, compare_page); 
//
//
//    for (int i = 0; i < N; i++) { // 3�ܰ�
//        string start, end; 
//        int start_idx, end_idx, links; 
//        cin >> start >> links; 
//
//        for (int j = 0; j < N; j++) if (pages[j].url == start) {
//            start_idx = j;
//            break;
//        }
//
//        for (int j = 0; j < links; j++) { 
//            cin >> end; 
//            for (int k = 0; k < N; k++) if (pages[k].url == end) {
//                end_idx = k;
//                break;
//            }
//
//            link l; 
//            l.end = end; l.end_idx = end_idx; 
//            graph[start_idx].push_back(l); 
//
//            link l_t; 
//            l_t.end = start; l_t.end_idx = start_idx; 
//            graph_t[end_idx].push_back(l_t); 
//        }
//    }
//
//    for (int i = 0; i < N; i++) { 
//        sort(graph[i].begin(), graph[i].end(), compare_link);
//        sort(graph_t[i].begin(), graph_t[i].end(), compare_link);
//    }
//
//    return; // input �Լ� ����
//}
//
//void phase1(int start) { // ��� �Լ��� ������ DFS, start���� �ش� page�� index ��
//    pages[start].visited = true; // �湮 �Ϸ�
//    for (int i = 0; i < graph[start].size(); i++) { // graph���� ���� page�� ��� link�� ���Ͽ� �ٽ� DFS ����
//        // �̹� �湮�� ��� pass
//        if (pages[graph[start].at(i).end_idx].visited) continue; // ������ graph[start]���� i��° link�� index������ pages �迭�� ������ �湮 ���� üũ
//        // �湮���� �ʾҴٸ� �ٽ� ��ȸ ����
//        phase1(graph[start].at(i).end_idx);
//    }
//    finished.push(start); // �� �̻� �� edge�� ���� �� stack�� �߰�
//    cout << pages[start].url << " "; // finished �� ������� �߰� ���� ���
//}
//
//void phase2(int start) { // ��� �Լ��� ������ DFS, start���� �ش� page�� index ��
//    pages[start].visited = true; // �湮 �Ϸ�
//    result[start] = leader; // �湮 �Ϸ�� ���ÿ� leader���� result �迭�� ���� page�� index���� ����
//    for (int i = 0; i < graph_t[start].size(); i++) { // graph_t���� ���� page�� ��� link�� ���Ͽ� �ٽ� DFS ����
//        // �̹� �湮�� ��� pass
//        if (pages[graph_t[start].at(i).end_idx].visited) continue; // ������ graph_t[start]���� i��° link�� index������ pages �迭�� ������ �湮 ���� üũ
//        // �湮���� �ʾҴٸ� �ٽ� ��ȸ ����
//        phase2(graph_t[start].at(i).end_idx);
//    }
//}