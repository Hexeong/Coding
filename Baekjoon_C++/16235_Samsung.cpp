// https://www.acmicpc.net/problem/16235
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct tree {
    int age;
    bool status;
    tree(int age, bool status) : age(age), status(status) {}
};

int N, M, K;
int A[10][10];
int map[10][10];
vector<vector<vector<tree>>> trees(10, vector<vector<tree>>(10, vector<tree>()));

void process_spring() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = trees[i][j].size() - 1; k > -1; k--) {
                if (map[i][j] - trees[i][j][k].age >= 0) {
                    map[i][j] -= trees[i][j][k].age;
                    trees[i][j][k].age++;
                }
                else trees[i][j][k].status = false;
            }
        }
    }
}

void process_summer() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < trees[i][j].size(); k++) {
                if (!trees[i][j][k].status) {
                    map[i][j] += (trees[i][j][k].age / 2);
                    trees[i][j].erase(trees[i][j].begin() + k);
                    k--;
                }
            }
        }
    }
}

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void process_fall() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < trees[i][j].size(); k++) {
                if (trees[i][j][k].age % 5 == 0) {
                    for (int m = 0; m < 8; m++) {
                        int ny = i + dy[m];
                        int nx = j + dx[m];
                        if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1) continue;

                        trees[ny][nx].push_back(tree(1, true));
                    }
                }
            }
        }
    }
}

void process_winter() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] += A[i][j];
        }
    }
}

bool compare(tree& a, tree& b) { // 가을에 나무가 번식하면서 삭제보다 추가 연산을 많이 할 것 같기에
    return a.age > b.age;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i<N; i++)
        for (int j = 0; j<N; j++) {
            cin >> A[i][j]; // r, c는 1부터 시작
            map[i][j] = 5; // 초기 양분 조건
        }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x - 1][y - 1].push_back(tree(z, true));
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sort(trees[i][j].begin(), trees[i][j].end(), compare);

    for (int k = 0; k < K; k++) {
        process_spring();
        process_summer();
        process_fall();
        process_winter();
    }

    int tree_sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tree_sum += trees[i][j].size();
    cout << tree_sum << endl;
}