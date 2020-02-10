#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
using namespace std;
int T, N, M;
int arr[1001];
int dp[1001];
int main()
{
	int i, j;
	int N;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	dp[1] = 1;
	for (i = 1; i <= N; i++)
	{
		if (dp[i] == 0)
			break;
		for (j = 1; j <=arr[i]; j++)
		{
			if (i + j > 1000)
				break;
			if (dp[i + j] == 0)
			{
				dp[i + j] = dp[i] + 1;
			}
			else
				dp[i + j] = min(dp[i] + 1, dp[i + j]);
		}
	}
	if (dp[N] == 0)
		printf("-1");
	else
	printf("%d", dp[N]-1);
}