
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N;
int dp[301];
int arr[301];
int main()
{
	int N;
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	dp[0] = arr[0];
	for (i = 1; i < N; i++)
	{
		dp[i] = max(dp[i-2]+arr[i],arr[i-1]+arr[i]+dp[i-3]);
	}
	printf("%d", dp[N-1]);
}
