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
                // ���� ����
                if (cur != first) {
                    if (cur->next != nullptr) cur->next->prev = cur->prev;
                    cur->prev->next = cur->next;
                    cur = cur->prev;
                }
            }
            else if (s[i][j] == '<') {
                // Ŀ�� ���� �̵�
                if (cur->prev != nullptr) cur = cur->prev;
            }
            else if (s[i][j] == '>') {
                // Ŀ�� ������ �̵�
                if (cur->next != nullptr) cur = cur->next;
            }
            else {
                // ���� �߰�, first�� �� �տ� �ֱ⿡ �� ����.
                list[j] = node(s[i][j]);
                list[j].next = cur->next;
                list[j].prev = cur;
                if (cur->next != nullptr) cur->next->prev = &list[j];
                cur->next = &list[j];
                cur = &list[j];
            }
        }


        // ���
        node* p = first->next;
        while (p != nullptr) {
            cout << p->c;
            p = p->next;
        }
        cout << "\n";
    }

    // �ᱹ ���� ������ O(1)�̾�߸� ��


    return 0;
}

// �ݷ� : ab-cd-ewgg<<b>>B























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
//		// ���, first ����
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
		//		// ���� ����
		//		if (!res.empty() && cursor > 0) {
		//			res.erase(res.begin() + cursor - 1); // �̰Ű� O(n)�̱⿡ ���� �ð��� ����
		//			cursor--;
		//		}
		//	}
		//	else if (st[j] == '<') {
		//		// Ŀ�� ���� �̵�
		//		if (cursor > 0) cursor--;
		//	}
		//	else if (st[j] == '>') {
		//		// Ŀ�� ������ �̵�
		//		if (cursor < res.size()) cursor++;
		//		// abc
		//	}
		//	else {
		//		// ���� �߰�
		//		res.insert(res.begin() + cursor, st[j]); // �̰Ű� O(n)�̱⿡ ���� �ð��� ����
		//		cursor++;
		//	}
		//}

		//cout << res << "\n";