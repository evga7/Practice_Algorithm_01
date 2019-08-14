#include <stdio.h>

int arr[1001];
int dp[10001];
int Min(int a, int b)
{
	return a > b ? b : a;
}
int main()
{
	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 1; i <=N; i++)
		scanf("%d", &arr[i]);
	dp[1] = arr[1];
	for (i = 2; i <= N; i++)
	{
		dp[i] = arr[i];
		for (j = 1; j <=i; j++)
			dp[i] = Min(dp[i-j] + arr[j], dp[i]);
	}
	printf("%d", dp[N]);
}