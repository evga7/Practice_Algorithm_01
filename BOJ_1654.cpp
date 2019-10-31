#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
long long arr[10001];
int K, N;
int main()
{
	int i;
	long long res = 0;
	scanf("%d %d", &K, &N);
	for (i = 0; i < K; i++)
	{
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + K);
	long long left = 1;
	long long  right = arr[K - 1];
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (i = 0; i < K; i++)
		{
			cnt += arr[i] / mid;
		}
		if (cnt >= N)
		{
			res = max(res, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%lld", res);
}