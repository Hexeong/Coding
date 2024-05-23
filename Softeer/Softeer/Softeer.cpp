// Softeer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

class SequenceList {
private:
    struct Node {
        string e;
        Node* prev;
        Node* next;
    };
public:
    class Iterator { //반복자 클래스
    private:
        Node* v;
        Iterator(Node* u);
    public:
        string& operator*();
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();
        Iterator& operator--();

        friend class SequenceList;
    };
private:
    int n;
    Node* header;
    Node* trailer;
public:
    SequenceList();
    int size() const;
    bool empty() const;
    Iterator begin() const;
    Iterator end() const;
    void insertFront(const string& e);
    void insertBack(const string& e);
    void insert(const Iterator& p, const string& e);
    void eraseFront();
    void eraseBack();
    void erase(const Iterator& p);

    SequenceList::Iterator atIndex(int i) const;
    int indexOf(const Iterator& p) const;
};

SequenceList::SequenceList() {
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

void SequenceList::insert(const SequenceList::Iterator& p, const string& e) {
    Node* w = p.v;
    Node* u = w->prev;
    Node* v = new Node;
    v->e = e;
    v->next = w; w->prev = v;
    v->prev = u; u->next = v;
    this->n++;
}

void SequenceList::insertFront(const string& e) {
    insert(begin(), e);
}

void SequenceList::insertBack(const string& e) {
    insert(end(), e);
}

void SequenceList::erase(const Iterator& p) {
    Node* v = p.v;
    Node* w = v->next;
    Node* u = v->prev;
    u->next = w; w->prev = u;
    delete v;
    this->n--;
}

void SequenceList::eraseFront() {
    erase(begin());
}

void SequenceList::eraseBack() {
    erase(--end());
}

int SequenceList::size() const {
    return n;
}

bool SequenceList::empty() const {
    return (n == 0);
}

SequenceList::Iterator::Iterator(Node* u) {
    v = u;
}

SequenceList::Iterator SequenceList::begin() const {
    return Iterator(header->next);
}

SequenceList::Iterator SequenceList::end() const {
    return Iterator(trailer);
}

string& SequenceList::Iterator::operator*() {
    return v->e;
}

bool SequenceList::Iterator::operator==(const Iterator& p) const {
    return v == p.v;
}

bool SequenceList::Iterator::operator!=(const Iterator& p) const {
    return v != p.v;
}

SequenceList::Iterator& SequenceList::Iterator::operator++() {
    v = v->next;
    return *this;
}

SequenceList::Iterator& SequenceList::Iterator::operator--() {
    v = v->prev;
    return *this;
}

SequenceList::Iterator SequenceList::atIndex(int i) const {
    Iterator p = begin();
    for (int j = 0; j < i; j++) {
        ++p;
    }
    return p;
}

int SequenceList::indexOf(const Iterator& p) const {
    Iterator q = begin();
    int j = 0;

    while (q != p) {
        ++q;
        ++j;
    }
    return j;
}

int main() {
    int T;//테스트 케이스의 수
    int N, M, K;//표 행 개수, 명령어 개수, 초기 선택 행
    string name;
    string oper; //명령어
    int x;
    cin >> T;

    SequenceList dl;
    SequenceList::Iterator iter = dl.begin();

    for (int j = 0; j < T; j++) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; ++i) {
            cin >> name;
            dl.insert(dl.atIndex(i), name);
        }
        dl.atIndex(K);
        for (int i = 0; i < M; i++) {
            cin >> oper;
            if (oper == "up") {
                cin >> x;
                if (dl.size() == 0)
                    continue;
                else if (dl.indexOf(iter) - x < 0) {
                    iter = dl.begin();
                }
                else {
                    iter = dl.atIndex(dl.indexOf(iter) - x);
                }
            }
            else if (oper == "cut") {
                if (dl.empty())
                    continue;
                else if (iter == dl.begin()) {
                    dl.erase(iter);
                    iter = dl.begin();
                }
                else {
                    SequenceList::Iterator temp = --iter;
                    dl.erase(++iter);
                    iter = temp;
                }
            }
            else if (oper == "down") {
                cin >> x;
                if (dl.empty()) {
                    continue;
                }
                else if (dl.indexOf(iter) + x > dl.size() - 1) {
                    iter = --dl.end();
                }
                else {
                    iter = dl.atIndex(dl.indexOf(iter) + x);
                }
            }
            else if (oper == "append") {
                cin >> name;
                if (dl.empty()) {
                    dl.insert(dl.atIndex(0), name);
                    iter = dl.begin();
                }
                else
                    dl.insert(iter, name);
            }
        }
        if (dl.size() == 0) {
            cout << "And Then There Were None" << endl;
        }
        else {
            iter = dl.begin();
            for (int i = 0; i < dl.size(); ++i) {
                cout << *iter << " ";
            }
            cout << endl;
        }
    }
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
