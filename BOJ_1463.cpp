#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N;
int dp[100001];
int main()
{
	int N;
	int i;
	scanf("%d", &N);
	for (i = 2; i <=N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
	}
	printf("%d", dp[N]);
}
