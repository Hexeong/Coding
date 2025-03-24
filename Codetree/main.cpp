#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    public:
    LinkedList();
    void Print();
    void Append(int data);
    void Delete(int idx);
    void Update(int idx, int data);
    void minmax_sum();

    private:
    node *head;
    node *tail;
    int size;
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void LinkedList::Print() {
    if (size == 0) {
        cout << "empty\n";
        return;
    }

    node* cur = head;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void LinkedList::Append(int data) {
    node* new_node = new node(data);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
        size++;
        return;
    }

    tail->next = new_node;
    tail = tail->next;
    size += 1;
}

void LinkedList::Delete(int idx) {
    if (idx >= size || idx < 0) {
        cout << -1 << "\n";
        return;
    }

    node* cur = head;
    for (int i = 0; i < idx - 1; i++) {
        cur = cur->next;
    }

    node* del = cur->next; // 13 5 9, 2번을 지우잖아.
    cur->next = del->next;
    delete del;
    size--;
}

void LinkedList::Update(int idx, int data) {
    if (idx >= size || idx < 0) {
        cout << -1 << "\n";
        return;
    }

    node* cur = head;
    for (int i = 0; i < idx; i++) {
        cur = cur->next;
    }

    cur->data = data;
}

void LinkedList::minmax_sum() {
    if (size == 0) {
        cout << 0 << "\n";
        return;
    }

    node* cur = head;

    int max = cur->data;
    int min = cur->data;

    while (cur->next != nullptr) {
        if (cur->data > max)
            max = cur->data;
        if (cur->data < min)
            min = cur->data;
        cur = cur->next;
    }

    cout << max + min << "\n";
}

int main() {

    int N; cin >> N;
    LinkedList ll;
    while (N--) {
        string name; cin >> name;
        if (name == "Print") {
            ll.Print();
        }
        else if (name == "Append") {
            int x; cin >> x;
            ll.Append(x);
            ll.Print();
        }
        else if (name == "Delete") {
            int idx; cin >> idx;
            ll.Delete(idx);
        }
        else if (name == "Update") {
            int idx, x; cin >> idx >> x;
            ll.Update(idx, x);
        }
        else if (name == "MinMax_Sum") {
            ll.minmax_sum();
        }
    }

    return 0;
}