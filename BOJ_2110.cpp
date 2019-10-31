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
	int N, C;
	cin >> N >> C;
	int i;
	for (i = 1; i <=N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N+1);
	int left = 1;
	int right = arr[N] - arr[1];
	int res=0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 1;
		int back = arr[1];
		for (i = 1; i <= N; i++)
		{
			if (mid <= arr[i] - back)
			{
				cnt++;
				back = arr[i];
			}
		}
		if (cnt >= C)
		{
			res = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << res;
}