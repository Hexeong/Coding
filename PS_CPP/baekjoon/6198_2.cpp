//
// Created by admin on 2025-07-29.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct building {
    int height;
    int idx;
    building(int h, int idx) : height(h), idx(idx) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<int> height(N);
    for (int i = 0; i < N; i++)
        cin >> height[i];

    long long result = 0;
    stack<building> buildings;
    buildings.push(building(height[0], 0));
    for (int i = 1; i < N; i++) {
        while (!buildings.empty() && buildings.top().height <= height[i])
            buildings.pop();

        result += buildings.size();

        buildings.push(building(height[i], i));
    }

    cout << result << '\n';
}