#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct running_info {
	string stops_name;
	int stops_number;
	int course_number;
	int time;
};
struct station {
	string name;
	int number;
};

int n, q;

vector<running_info> subway_stops[200000]; // station 별로 가진 노선 정보
station cur_end_course[1000]; // 현재 노선마다 end station을 저장해둠
// 나중에 노선에 추가시 여기 값을 기준으로 새로운 edge를 추가한다음 cur_end_course update

station stops[200000];
int tot_time[200000];

// heap으로 fringe를 관리해봅시다. 한번

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

		subway_stops[cur_end_course[r.course_number].number].push_back(r); // 상행
		subway_stops[r.stops_number].push_back(r_t); // 하행

		station s; s.name = r.stops_name; s.number = r.stops_number;
		cur_end_course[r.course_number] = s;
	}

	for (int i = 0; i < n; i++) sort(subway_stops[i].begin(), subway_stops[i].end(), compare_station);

	for (int i = 0; i < q; i++) {
		char aORb, source, destination; cin >> aORb >> source >> destination;

		for (int j = 0; j < n; j++) { // 모든 질의에 대한 초기화 과정
			// heap의 unseen 필요
			tot_time[j] = INFINITY;
		}

		if (aORb == 'A') {

		}
		else {

		}
	}
	return 0;
}