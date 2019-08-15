#include <stdio.h>

long long dp[1001][1001];
int main()
{
	int i, j,k;
	for (i = 0; i < 10; i++)
		dp[1][i] = 1;
	int N;
	long long sum = 0;
	scanf("%d", &N);
	for (i = 2; i <= N; i++)
	{
		for (j = 0; j < 10; j++)
		{
			for (k = j; k < 10; k++)
			{
				dp[i][k] += dp[i-1][j];
				dp[i][k] %= 10007;
			}
		}
	}
	for (i = 0; i < 10; i++)
		sum += dp[N][i];
	printf("%lld", sum%10007);
}

