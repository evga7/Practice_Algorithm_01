#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
long long arr[1000000];
int main()
{
	long long N, M;
	scanf("%lld %lld", &N, &M);
	long long left = 1;
	long long right = 0;
	long long i;
	long long res = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
		right = max(right, arr[i]);
	}
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long temp = 0;
		for (i = 0; i < N; i++)
		{
			if (mid<arr[i])
			temp += arr[i] - mid;
		}
		if (temp >= M)
		{
			res = max(res, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;

	}
	printf("%lld", res);
}