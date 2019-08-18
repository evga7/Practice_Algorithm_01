#include <iostream>
#include <string>
using namespace std;
int arr[2][100001];
int dp[2][100001];
int Max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int T, N;
	int i,j;
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d", &N);
		for (i = 0; i < 2; i++)
		{
			for (j=0;j<N;j++)
				scanf("%d", &arr[i][j]);
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = dp[1][0] + arr[0][1];
		dp[1][1] = dp[0][0] + arr[1][1];
		for (i = 2; i < N; i++)
		{
			dp[0][i] = arr[0][i] + Max(Max(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]);
			dp[1][i] = arr[1][i] + Max(Max(dp[0][i - 2], dp[1][i - 2]), dp[0][i - 1]);
		}
		printf("%d\n", Max(dp[0][N-1], dp[1][N-1]));
	}
}

