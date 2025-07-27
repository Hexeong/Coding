//
// Created by admin on 2025-07-09.
//
#include <iostream>
#include <vector>

using namespace std;

int N, M;

struct node {
    char value;
    node* next;
    node* prev;
    node(char value) : value(value), next(nullptr), prev(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    node* start = new node('*');
    node* cur = start;
    for (int i = 0; i < s.length(); i++) {
        node* c = new node(s[i]);
        cur->next = c;
        c->prev = cur;
        cur = cur->next;
    }

    cin >> M;
    while (M--) {
        char command;
        cin >> command;

        if (command == 'L' && cur->prev != nullptr)
            cur = cur->prev;
        else if (command == 'D' && cur->next != nullptr)
            cur = cur->next;
        else if (command == 'B' && cur->prev != nullptr) {
            node* del = cur;
            cur->prev->next = cur->next;
            if (cur->next != nullptr)
                cur->next->prev = cur->prev;
            cur = cur->prev;
            delete del;
        }
        else if (command == 'P') {
            char new_char; cin >> new_char;
            node* new_node = new node(new_char);
            new_node->prev = cur;
            new_node->next = cur->next;
            if (cur->next != nullptr)
                cur->next->prev = new_node;
            cur->next = new_node;
            cur = cur->next;
        }
    }

    cur = start;
    while (cur->next != nullptr) {
        cout << cur->next->value;
        cur = cur->next;
    }
    cout << endl;
}