
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[101];
int dp[10001];
int main()
{
	int N, K;
	int i, j, k;
	scanf("%d %d", &N, &K);
	for (i = 1; i <=N; i++)
		scanf("%d", &arr[i]);
	for (i = 1; i <= K; i++)
		dp[i] = 999999;
	dp[0] = 0;
	for (i=1;i<=N;i++)
	{
		for (j = arr[i]; j <= K; j++)
		{
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	if (dp[K] = 999999)
		printf("-1");
	else
	printf("%d", dp[K]);
}
