//
// Created by hex on 25. 10. 22..
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct task {
    int priority;
    int arrival_time;
    int task_number;
    int execution_time;

    task(int _task_num, int _arrival_time, int _execution_time, int _priority)
        : task_number(_task_num), arrival_time(_arrival_time),
            execution_time(_execution_time), priority(_priority) {}
};

struct Comparator { // 우선순위 클수록, 도착시간 낮을 수록, 작업 번호 작을수록 top에 올라오는 비교자
    bool operator()(const task &t1, const task &t2) {
        if (t1.priority == t2.priority) {
            if (t1.arrival_time == t2.arrival_time) {
                return t1.task_number > t2.task_number;
            }
            return t1.arrival_time > t2.arrival_time;
        }
        return t1.priority < t2.priority;
    }
};

bool compare(const task &t1, const task &t2) {
    return t1.arrival_time < t2.arrival_time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        priority_queue<task, vector<task>, Comparator> pq;

        vector<task> tasks;
        for (int i = 0; i < N; i++) {
            int task_number, arrival_time, execution_time, priority;
            cin >> task_number >> arrival_time >> execution_time >> priority;
            tasks.push_back(task(task_number, arrival_time, execution_time, priority));
        }

        sort(tasks.begin(), tasks.end(), compare);

        int i = 0;
        int t = 0;
        while (i < N || !pq.empty()) {
            while (i < N && t == tasks[i].arrival_time) {
                pq.push(tasks[i]);
                i++;
            }

            if (!pq.empty()) {
                task top = pq.top();
                pq.pop();

                cout << top.task_number << " ";

                top.execution_time--;
                if (top.execution_time != 0)
                    pq.push(top);
            }
            else
                cout << "0 ";

            t++;
        }
        cout << '\n';
    }
}