#include <iostream>
#include <string>
using namespace std;

int N;
long long cnt = 0;
long long dp[91][91];
void dfs(int a, int b,int go)
{
	if (go == N)
	{
		cnt++;
		return;
	}
	else
	{
		if (b == 0)
		{
			dfs(1, 0, go + 1);
			dfs(0, 1, go + 1);
		}
		if (a == 0)
		{
			dfs(1, 0, go + 1);
		}

	}
}

int main()
{
	scanf("%d", &N);
	int i, j;
	dp[1][1] = 1;
	for (i = 2 ;i<= N; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	printf("%lld", dp[N][0] + dp[N][1]);
}

