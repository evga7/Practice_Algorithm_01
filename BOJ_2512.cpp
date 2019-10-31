#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int arr[200001];
int main()
{
	int N,M;
	cin >> N;
	int res;
	int i;
	int sum = 0;
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N + 1);
	cin >> M;
	int left = 1;
	int right = arr[N];
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = 0;
		for (i = 1; i <= N; i++)
		{
			sum += min(arr[i], mid);
		}
		if (sum <= M)
		{
			res = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << res;
}