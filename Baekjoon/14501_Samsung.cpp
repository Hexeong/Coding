#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> paper;
int benefit[16] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int T, P;
        cin >> T >> P;
        paper.push_back(make_pair(T, P));
    }

    // idx 일까지의 최대 수익
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < i; j++) {
            if (paper[j].first + j <= i)
                benefit[i] = max(benefit[i], benefit[j] + paper[j].second);
        }
    }

    cout << benefit[N] << endl;

    return 0;
}