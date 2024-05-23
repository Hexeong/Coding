#include<iostream>

using namespace std;

int n, q;

int arr[200001]; // fuel와 order의 정렬을 위한 입력 버퍼
int fuel[50001];
int order[200001];
char order_idx[1000000001];

// n == 200,000,000

void merge_f(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			fuel[k++] = arr[i++];
		else
			fuel[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) fuel[k++] = arr[tmp++];

	for (int i = left; i <= right; i++) arr[i] = fuel[i];
}

void merge_o(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			order[k++] = arr[i++];
		else
			order[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) order[k++] = arr[tmp++];

	for (int i = left; i <= right; i++) arr[i] = order[i];
}

void partition_f(int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		partition_f(left, mid);
		partition_f(mid + 1, right);
		merge_f(left, right);
	}
}

void partition_o(int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		partition_o(left, mid);
		partition_o(mid + 1, right);
		merge_o(left, right);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	partition_f(1, n); // nlogn

	for (int k = 0; k < q; k++) cin >> arr[k];

	partition_o(0, q - 1); // nlogn

	int k = 0;
	for (int i = 1; i <= n; i++) { // q
		if (order[k] == fuel[i]) {
			order_idx[order[k]] = i;
			k++;
			i--;
		}
	}

	for (int i = 0; i < q; i++) {
		cout << (order_idx[order[i]] - 1) * (n - order_idx[order[i]]) << "\n";
	}

	return 0;
}