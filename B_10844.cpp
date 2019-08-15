#include <stdio.h>

long long dp[101][101];
int main()
{
	int i, j;
	int N;
	scanf("%d", &N);
	long long sum = 0;
	for (i = 1; i <=9; i++)
	{
		dp[1][i] = 1;
	}
	for (i = 2; i <= N; i++)
	{
		for (j = 0; j <10; j++)
		{
			if (j == 0) // 0일때 1개밖에안됨 ex) 01
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9) //9일때 1개 ex) 98
				dp[i][j] = dp[i - 1][j - 1];
			else // 나머지 -1 +1 인수일떄 가능
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	for (i = 0; i <10; i++)
		sum += dp[N][i] % 1000000000;
	printf("%lld", sum%1000000000);
}