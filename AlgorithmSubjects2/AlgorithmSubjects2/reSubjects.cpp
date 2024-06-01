#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#define INFINITE 210000000;

using namespace std;

struct station {
	string name;
	int prev_idx;
};

int n, q, max_stations;
vector<pair<int, int>> graph[200001]; // pair.a = time, pair.b = idx
station stations[200001];

int tot_time[200001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void input() {
	cin >> n >> q;
	int before_course = 0;
	int before_idx;

	int station_idx, course, time;
	string station_name;

	for (int i = 0; i < n; i++) {
		cin >> station_idx >> course >> station_name >> time;
		
		stations[station_idx].name = station_name;
		max_stations = max(max_stations, station_idx);

		if (before_course != course) {
			before_course = course;
		}
		else {
			pair<int, int> up, down;
			up = { time, station_idx };
			graph[before_idx].push_back(up);

			down = { time, before_idx };
			graph[station_idx].push_back(down);
		}
		before_idx = station_idx;
	}

	for (int i = 1; i <= max_stations; i++) sort(graph[i].begin(), graph[i].end());
}

void main_func() {
	char aORb;
	int source, destination;
	cin >> aORb >> source >> destination;

	tot_time[source] = 0;
	pq.push({ 0, source });

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		if (cur.second == destination) {
			if (aORb == 'A') {
				cout << cur.first << "\n";
			}
			else {
				stack<int> st;
				int cur = destination;
				while (cur != -1) {
					st.push(cur);
					cur = stations[cur].prev_idx;
				}
				cout << st.size() << " ";
				while (!st.empty()) {
					cout << stations[st.top()].name << " ";
					st.pop();
				}
				cout << "\n";
			}

			return;
		}

		for (int i = 0; i < graph[cur.second].size(); i++) {
			int next_idx = graph[cur.second][i].second;
			int next_time = graph[cur.second][i].first;

			if (tot_time[next_idx] > tot_time[cur.second] + next_time) { // 새로운 경로의 비용이 같지만, 번호가 더 낮을 때
				tot_time[next_idx] = tot_time[cur.second] + next_time;
				stations[next_idx].prev_idx = cur.second;
				pq.push({ tot_time[next_idx], next_idx });
			}
		}
	}

	cout << "None\n";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	while (q--) {
		for (int i = 1; i <= max_stations; i++) {
			tot_time[i] = INFINITE;
			stations[i].prev_idx = -1;
		}
		main_func();
		while (!pq.empty()) pq.pop();
	}

	return 0;
}