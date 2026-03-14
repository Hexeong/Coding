// 11279.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

class PQ {
private:
    vector<int> nodes;
public:
    PQ() {

    }
    void insert(int x) {
        for (vector<int>::iterator it = nodes.begin(); it != nodes.end(); it++) {
            if (*it > x) {
                nodes.insert(it, x);
                return;
            }
        }
        nodes.push_back(x);
    }
    int removeMax() {
        if (nodes.size() == 0) {
            return 0;
        }
        else {
            int tmp = nodes[nodes.size() - 1];
            nodes.pop_back();
            return tmp;
        }
    }
};

class Heap {
private:
    vector<int> v;
    int heap_size;
    int root_index;
    int direction;
public:
    Heap(int direction) {
        v.push_back(-1);
        heap_size = 0;
        root_index = 1;
        this->direction = direction;
    }
    void swap(int idx1, int idx2) {
        v[0] = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = v[0];
    }
    void upHeap(int idx) {
        if (idx == root_index) return;
        else {
            int parent = idx / 2;
            if (v[parent] * direction > v[idx] * direction) { // min = 1, max = -1
                swap(parent, idx);
                upHeap(idx);
            }
        }
    }
    void downHeap(int idx) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        if (right <= heap_size) {
            if (v[left] * direction <= v[right] * direction) {
                if (v[left] * direction < v[idx] * direction) {
                    swap(left, idx);
                    downHeap(left);
                }
                else return;
            }
            else {
                if (v[right] * direction < v[idx] * direction) {
                    swap(right, idx);
                    downHeap(right);
                }
                else return;
            }
        }
        else if (left <= heap_size) {
            if (v[left] * direction < v[idx] * direction) {
                swap(left, idx);
                downHeap(left);
            }
            else return;
        }
        else return;
    }
    void insert(int e) {
        v.push_back(e);
        heap_size++;
        upHeap(heap_size);
    }
    int pop() {
        if (heap_size == 0) {
            return 0;
        }
        else {
            int top = v[root_index];
            v[root_index] = v[heap_size]; heap_size--;
            v.pop_back();
            downHeap(root_index);
            return top;
        }
    }

    int top() { return v[root_index]; }

    int size() { return heap_size; }

    bool isEmpty() { return heap_size == 0; }
};

int main()
{
    /*PQ pq;
    int N;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            cout << pq.removeMax() << endl;
        }
        else {
            pq.insert(arr[i]);
        }
    }*/
    Heap heapPQ(-1);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            cout << heapPQ.pop() << endl;
        }
        else {
            heapPQ.insert(tmp);
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
