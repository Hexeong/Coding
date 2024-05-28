#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct running_info {
	string stops_name;
	int stops_number;
	int course_number;
	int time;
};
struct end_station {
	string name;
	int number;
};
struct station {
	string name;
	char status = 'U';
	int prev_stat_idx;
};

int n, q, heap_size;

vector<running_info> station_course[200000]; // station 별로 가진 노선 정보
end_station cur_end_course[1000]; // 현재 노선마다 end station을 저장해둠
// 나중에 노선에 추가시 여기 값을 기준으로 새로운 edge를 추가한다음 cur_end_course update

station stations[200000];
int tot_time[200000];

// heap으로 fringe를 관리해봅시다. 한번
int heap_arr[200000];

void add(int d);
int removeMin();

bool compare_station(running_info a, running_info b) {
	return a.stops_number < b.stops_number;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		running_info r, r_t;
		cin >> r.stops_number >> r.course_number >> r.stops_name >> r.time;

		r_t.stops_number = cur_end_course[r.course_number].number;
		r_t.course_number = r.course_number;
		r_t.stops_name = cur_end_course[r.course_number].name;
		r_t.time = r.time;

		station_course[cur_end_course[r.course_number].number].push_back(r); // 상행
		station_course[r.stops_number].push_back(r_t); // 하행

		end_station s; s.name = r.stops_name; s.number = r.stops_number;
		cur_end_course[r.course_number] = s;
	}

	for (int i = 0; i < n; i++) sort(station_course[i].begin(), station_course[i].end(), compare_station);

	for (int i = 0; i < q; i++) {
		char aORb, source, destination; 
		cin >> aORb >> source >> destination;

		for (int j = 0; j < n; j++) tot_time[j] = INFINITY; // 모든 질의에 대한 초기화 과정

		int minTime = INFINITY;

		add(source); // time이 작은 순으로 minHeap을 유지
		while (heap_size > 0) {

			// removeMin한 다음
			int cur_tree = removeMin();

			// 그걸로 fringe 추가해주고 뺀 것은 tree로, distance, tot_time기록을 해야지
			for (int i = 0; i < station_course[cur_tree].size(); i++) {
				if (stations[station_course[cur_tree][i].stops_number].status == 'U') {
					add(station_course[cur_tree][i].stops_number);
					tot_time[station_course[cur_tree][i].stops_number] = tot_time[cur_tree] + station_course[cur_tree][i].time;
				}
				else if (stations[station_course[cur_tree][i].stops_number].status == 'F') {
					if (tot_time[cur_tree] + station_course[cur_tree][i].time < tot_time[station_course[cur_tree][i].stops_number]) { // 만약 추가된 edge로 인해 distance가 update해야 될 경우, wmr tot_time + 추가된 edge vs 기존의 edge
						tot_time[station_course[cur_tree][i].stops_number] = tot_time[cur_tree] + station_course[cur_tree][i].time;
						stations[station_course[cur_tree][i].stops_number].prev_stat_idx = cur_tree;
					}
				}
			}
		}

		if (aORb == 'A') {
			cout << tot_time[destination] << "\n";
		}
		else {
			int cur = destination;
			stack<int> s; s.push(cur);
			while (stations[cur].prev_stat_idx != -1) {
				s.push(stations[cur].prev_stat_idx);
				cur = stations[cur].prev_stat_idx;
			}

			cout << s.size() << " ";
			while (!s.empty()) {
				cout << s.top() << " ";
				s.pop();
			}
			cout << "\n";
		}
	}
	return 0;
}

void add(int d) {
	heap_size++;
	heap_arr[heap_size] = d;

	int cur = heap_size;
	int parent = heap_size / 2;
	while (parent) {
		if (heap_arr[parent] > heap_arr[cur]) {
			int tmp = heap_arr[parent];
			heap_arr[parent] = heap_arr[cur];
			heap_arr[cur] = tmp;
		}
		else break;
	}
	stations[heap_arr[cur]].status = 'F';
	return;
}

int removeMin() {
	int res = heap_arr[1];
	heap_arr[1] = heap_arr[heap_size];
	heap_size--;

	int cur = 1;
	int child = 2;

	while (child <= heap_size) {
		if (child + 1 <= heap_size && heap_arr[child] < heap_arr[child + 1]) child++;

		if (heap_arr[cur] > heap_arr[child]) {
			int tmp = heap_arr[cur];
			heap_arr[cur] = heap_arr[child];
			heap_arr[child] = tmp;

			cur = child;
			child = cur * 2;
		}
		else break;
	}
	stations[heap_arr[cur]].status = 'T';

	return res;
}