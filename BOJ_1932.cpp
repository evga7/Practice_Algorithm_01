#include <stdio.h>
int dp[501][501];
int Max(int a, int b)
{
	return a > b ? a : b;
}
void triangle(int N)
{
	int i,j;
	int max = -99999999;
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				dp[i][j] += dp[i - 1][j];
			}
			else if (i == j)
			{
				dp[i][j] += dp[i - 1][j-1];
			}
			else
			{
				dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - 1]) + dp[i][j];
			}
			if (max < dp[i][j])max = dp[i][j];
		}
	}
	printf("%d", max);
}
int main()
{
	int N;
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		for (j = 1; j <= i; j++)
			scanf("%d", &dp[i][j]);
	triangle(N);
}