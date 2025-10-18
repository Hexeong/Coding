//
// Created by hex on 25. 10. 18..
//
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        unordered_set<string> us;
        int not_permitted_cnt = 0;

        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            if (us.find(s) != us.end()) {
                not_permitted_cnt++;
            } else {
                us.insert(s);
            }
        }

        cout << not_permitted_cnt << endl;
    }
}