//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <stack>
//
//using namespace std;
//
//struct running_info {
//	string stops_name;
//	int stops_number;
//	int course;
//	int time;
//};
//
//struct next_station {
//	string stops_name;
//	int stops_number;
//	int time;
//};
//
//struct end_station {
//	string name;
//	int number = 0;
//};
//
//struct station {
//	string name;
//	char status;
//	int prev_stat_idx;
//};
//
//int n, q, max_course, max_station, heap_size;
//
//end_station end_station_by_course[1000];
//vector<next_station> station_course[200000]; // station 별로 가진 노선 정보
//
//station stations[200000];
//int tot_time[200000];
//
//// heap으로 fringe를 관리해봅시다. 한번
//next_station heap_arr[200000];
//int heap_idx[200000];
//
//void add(next_station d);
//int removeMin();
//void modify(int idx, int modified_time);
//
//bool compare_station(next_station a, next_station b) {
//	return a.stops_number < b.stops_number;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> q;
//	for (int i = 0; i < n; i++) {
//		running_info r;
//		cin >> r.stops_number >> r.course >> r.stops_name >> r.time;
//		stations[r.stops_number].name = r.stops_name;
//		if (r.time == 0) {
//			end_station_by_course[r.course].name = r.stops_name;
//			end_station_by_course[r.course].number = r.stops_number;
//		}
//		else {
//			next_station up, down; // 상행, 하행
//
//			up.stops_name = r.stops_name;
//			up.stops_number = r.stops_number;
//			up.time = r.time;
//
//			down.stops_name = end_station_by_course[r.course].name;
//			down.stops_number = end_station_by_course[r.course].number;
//			down.time = r.time;
//
//			station_course[end_station_by_course[r.course].number].push_back(up);
//			station_course[r.stops_number].push_back(down);
//
//			end_station_by_course[r.course].name = r.stops_name;
//			end_station_by_course[r.course].number = r.stops_number;
//		}
//	}
//
//	for (int i = 0; i < q; i++) {
//		char aORb;
//		int source, destination; 
//		cin >> aORb >> source >> destination;
//
//		for (int j = 0; j < n; j++) {
//			tot_time[j] = 0;
//			stations[j].status = 'U';
//			stations[j].prev_stat_idx = -1;
//		} // 모든 질의에 대한 초기화 과정
//
//		next_station s; s.stops_number = source; s.stops_name = stations[source].name; s.time = 0;
//		add(s); // time이 작은 순으로 minHeap을 유지
//		while (heap_size > 0) {
//
//			// removeMin한 다음
//			int cur_tree = removeMin();
//
//			// 그걸로 fringe 추가해주고 뺀 것은 tree로, distance, tot_time기록을 해야지
//			for (int i = 0; i < station_course[cur_tree].size(); i++) {
//
//				if (stations[station_course[cur_tree][i].stops_number].status == 'U') {
//					tot_time[station_course[cur_tree][i].stops_number] = tot_time[cur_tree] + station_course[cur_tree][i].time;
//					stations[station_course[cur_tree][i].stops_number].prev_stat_idx = cur_tree;
//					if (station_course[cur_tree][i].stops_number != destination) add(station_course[cur_tree][i]);
//					else stations[station_course[cur_tree][i].stops_number].status = 'F';
//				}
//				else if (stations[station_course[cur_tree][i].stops_number].status == 'F') {
//					// 만약 추가된 edge로 인해 distance가 update해야 될 경우, 즉 tot_time + 추가된 edge vs 기존의 edge
//					if (tot_time[cur_tree] + station_course[cur_tree][i].time < tot_time[station_course[cur_tree][i].stops_number]) {
//						tot_time[station_course[cur_tree][i].stops_number] = tot_time[cur_tree] + station_course[cur_tree][i].time;
//						stations[station_course[cur_tree][i].stops_number].prev_stat_idx = cur_tree;
//						// heap에서도 바꿔야 함
//						modify(station_course[cur_tree][i].stops_number, station_course[cur_tree][i].time);
//					}
//					else if (tot_time[cur_tree] + station_course[cur_tree][i].time == tot_time[station_course[cur_tree][i].stops_number]
//						&& cur_tree < stations[station_course[cur_tree][i].stops_number].prev_stat_idx) {
//						tot_time[station_course[cur_tree][i].stops_number] = tot_time[cur_tree] + station_course[cur_tree][i].time;
//						stations[station_course[cur_tree][i].stops_number].prev_stat_idx = cur_tree;
//						// heap에서도 바꿔야 함
//						modify(station_course[cur_tree][i].stops_number, station_course[cur_tree][i].time);
//					}
//				}
//			}
//		}
//
//		if (aORb == 'A') {
//			if (tot_time[destination] == 0) cout << "None\n";
//			else cout << tot_time[destination] << "\n";
//		}
//		else {
//			int cur = destination;
//			stack<int> s; s.push(cur);
//			while (stations[cur].prev_stat_idx != -1) {
//				s.push(stations[cur].prev_stat_idx);
//				cur = stations[cur].prev_stat_idx;
//			}
//
//			if (s.top() != source) {
//				cout << "None\n";
//			}
//
//			cout << s.size() << " ";
//			while (!s.empty()) {
//				cout << stations[s.top()].name << " ";
//				s.pop();
//			}
//			cout << "\n";
//		}
//	}
//	return 0;
//}
//
//void add(next_station d) {
//	heap_size++;
//	heap_arr[heap_size] = d;
//
//	int cur = heap_size;
//	int parent = heap_size / 2;
//	while (parent) {
//		if (heap_arr[parent].time > heap_arr[cur].time) {
//			next_station tmp = heap_arr[parent];
//			heap_arr[parent] = heap_arr[cur];
//			heap_arr[cur] = tmp;
//		}
//		else if (heap_arr[parent].time == heap_arr[cur].time && heap_arr[parent].stops_number > heap_arr[cur].stops_number) {
//			next_station tmp = heap_arr[parent];
//			heap_arr[parent] = heap_arr[cur];
//			heap_arr[cur] = tmp;
//		}
//		else break;
//		cur = parent;
//		parent = cur / 2;
//	}
//	stations[d.stops_number].status = 'F';
//	return;
//}
//
//int removeMin() {
//	int res = heap_arr[1].stops_number;
//	heap_arr[1] = heap_arr[heap_size];
//	heap_size--;
//
//	int cur = 1;
//	int child = 2;
//
//	while (child <= heap_size) {
//		if (child + 1 <= heap_size && heap_arr[child].time < heap_arr[child + 1].time) child++;
//
//		if (heap_arr[cur].time > heap_arr[child].time) {
//			next_station tmp = heap_arr[cur];
//			heap_arr[cur] = heap_arr[child];
//			heap_arr[child] = tmp;
//		}
//		else if (heap_arr[cur].time == heap_arr[child].time && heap_arr[cur].stops_number > heap_arr[child].stops_number) {
//			next_station tmp = heap_arr[cur];
//			heap_arr[cur] = heap_arr[child];
//			heap_arr[child] = tmp;
//		}
//		else break;
//
//		cur = child;
//		child = cur * 2;
//	}
//
//	stations[heap_arr[cur].stops_number].status = 'T';
//
//	return res;
//}
//
//void modify(int idx, int modified_time) {
//	for (int i = 1; i <= heap_size; i++) {
//		if (heap_arr[i].stops_number == idx) {
//			heap_arr[i].time = modified_time;
//			break;
//		}
//	}
//}