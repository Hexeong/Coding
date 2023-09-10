// No. 18258
// #include <iostream>

// using namespace std;

// int arr[2000001];
// int start = 1;
// int qsize = 0;

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   int N;
//   cin >> N;
//   for (int i = 0; i < N; i++) {
//     string s;
//     cin >> s;
//     if (s == "push") {
//       int a;
//       cin >> a;
//       qsize++;
//       arr[start + qsize - 1] = a;
//     } else if (s == "pop") {
//       if (qsize == 0) {
//         cout << -1 << '\n';
//       } else {
//         cout << arr[start] << '\n';
//         start++;
//         qsize--;
//       }
//     } else if (s == "size") {
//       cout << qsize << '\n';
//     } else if (s == "empty") {
//       if (qsize == 0)
//         cout << "1\n";
//       else
//         cout << "0\n";
//     } else if (s == "front") {
//       if (qsize == 0) {
//         cout << -1 << '\n';
//       } else {
//         cout << arr[start] << '\n';
//       }
//     } else if (s == "back") {
//       if (qsize == 0) {
//         cout << -1 << '\n';
//       } else {
//         cout << arr[start + qsize - 1] << '\n'; // 1 + 1 - 1, 1 + 2 - 1
//       }
//     }
//   }

//   return 0;
// }