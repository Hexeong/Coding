//
// Created by admin on 2025-07-28.
//
#include <iostream>
#include <vector>

using namespace std;

int tower_list_size = 0;

struct tower {
    int height;
    int idx;
    tower* next;
    tower* prev;

    tower(int height, int idx) {
        this->height = height;
        this->idx = idx;
        this->next = nullptr;
        this->prev = nullptr;
    }

    static void pushTower(tower* cur, int height, int idx) {
        tower* newTower = new tower(height, idx);

        newTower->prev = cur;
        newTower->next = cur->next;
        if (cur->next != nullptr)
            cur->next->prev = newTower;
        cur->next = newTower;
        tower_list_size++;
    }

    static void eraseTower(tower* cur) {
        if (cur->prev != nullptr)
            cur->prev->next = cur->next;
        if (cur->next != nullptr)
            cur->next->prev = cur->prev;

        delete cur;
        tower_list_size--;
    }
};

tower* head = new tower(0, 0);
tower* tail = new tower(0, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    vector<int> height(N);
    vector<int> result(N, 0);
    head->next = tail;
    head->prev = tail;

    tower* cur = head;

    for (int i = 0; i < N; i++)
        cin >> height[i];

    // 최악 1, 2, 3, 4, ... , 500,000
    // N*N
    for (int i = N - 1; i >= 0; i--) {
        if (tower_list_size > 0) {
            cur = head->next;
            // head부터 시작해서 해당 탑에 수신가능한지 보고, 가능하면 erase와 함께 result에 idx값 저장
            while (cur != tail) {
                if (cur->height < height[i]) {
                    result[cur->idx] = i + 1;

                    // 지우기
                    tower* tmp = cur;
                    cur = cur->next;
                    tower::eraseTower(tmp);
                }
                else
                    break;
            }
        }

        cur = head;
        tower::pushTower(cur, height[i], i);
    }

    for (int i = 0; i < N - 1; i++)
        cout << result[i] << " ";
    cout << result[N - 1] << endl;
}