#include <iostream>
#include <vector>
#include <string>

using namespace std;

int t;
vector<string> s;

class node {
public:
    node* prev;
    node* next;
    char c;
    node() {
        prev = nullptr;
        next = nullptr;
    }
    node(char c) {
        prev = nullptr;
        next = nullptr;
        this->c = c;
    }

};

node* cur;
node list[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        string st; cin >> st;
        s.push_back(st);
    }

    for (int i = 0; i < t; i++) {
        node* first = new node();
        cur = first;
        for (int j = 0; j < s[i].size(); j++) {
            if (s[i][j] == '-') {
                // 글자 제거
                if (cur != first) {
                    if (cur->next != nullptr) cur->next->prev = cur->prev;
                    cur->prev->next = cur->next;
                    cur = cur->prev;
                }
            }
            else if (s[i][j] == '<') {
                // 커서 왼쪽 이동
                if (cur->prev != nullptr) cur = cur->prev;
            }
            else if (s[i][j] == '>') {
                // 커서 오른쪽 이동
                if (cur->next != nullptr) cur = cur->next;
            }
            else {
                // 글자 추가, first가 맨 앞에 있기에 다 가능.
                list[j] = node(s[i][j]);
                list[j].next = cur->next;
                list[j].prev = cur;
                if (cur->next != nullptr) cur->next->prev = &list[j];
                cur->next = &list[j];
                cur = &list[j];
            }
        }


        // 출력
        node* p = first->next;
        while (p != nullptr) {
            cout << p->c;
            p = p->next;
        }
        cout << "\n";
    }

    // 결국 삽입 삭제가 O(1)이어야만 함


    return 0;
}

// 반례 : ab-cd-ewgg<<b>>B























//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int t;
//
//struct node {
//	char c;
//	node* prev;
//	node* next;
//};
//
//int s;
//node* first;
//node* cur;
//vector<string> v;
//
//int main() {
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		string st; cin >> st;
//		v.push_back(st);
//	}
//	for (int i = 0; i < t; i++) {
//		first = new node;
//		first->prev = NULL;
//		first->next = NULL;
//
//		for (int j = 0; j < v[i].size(); j++) {
//			if (v[i][j] == '-') {
//				if (s > 0) {
//					cur->prev->next = cur->next;
//					cur->next->prev = cur->prev;
//					s--;
//					cur = cur->next;
//				}
//			}
//			else if (v[i][j] == '<') {
//				if (cur->prev != NULL) {
//					cur = cur->prev;
//				}
//			}
//			else if (v[i][j] == '<') {
//				if (cur->next != NULL) {
//					cur = cur->next;
//				}
//			}
//			else {
//				if (s == 0) {
//					first->c = v[i][j];
//					cur = first;
//				}
//				else {
//					node* temp = new node;
//					temp->next = cur;
//					temp->prev = cur->prev;
//					temp->c = v[i][j];
//					cur->prev = temp;
//				}
//				s++;
//			}
//		}
//
//		// 출력, first 부터
//		node* n = first;
//		while (n->next != NULL) {
//			cout << n->c;
//		}
//		cout << "\n";
//	}
//
//
//	return 0;
//}

//string res;
		//for (int j = 0; j < st.size(); j++) {
		//	if (st[j] == '-') {
		//		// 글자 제거
		//		if (!res.empty() && cursor > 0) {
		//			res.erase(res.begin() + cursor - 1); // 이거가 O(n)이기에 ㅈㄴ 시간을 먹음
		//			cursor--;
		//		}
		//	}
		//	else if (st[j] == '<') {
		//		// 커서 왼쪽 이동
		//		if (cursor > 0) cursor--;
		//	}
		//	else if (st[j] == '>') {
		//		// 커서 오른쪽 이동
		//		if (cursor < res.size()) cursor++;
		//		// abc
		//	}
		//	else {
		//		// 글자 추가
		//		res.insert(res.begin() + cursor, st[j]); // 이거가 O(n)이기에 ㅈㄴ 시간을 먹음
		//		cursor++;
		//	}
		//}

		//cout << res << "\n";