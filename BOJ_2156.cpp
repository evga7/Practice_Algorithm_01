#include <iostream>
#include <string>
using namespace std;
int arr[10001];
int dp[10001];
int Max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int N;
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	dp[1] = dp[0] + arr[1];
	for (i = 2; i < N; i++)
	{	
		dp[i] = Max(Max(dp[i - 1], dp[i - 2] + arr[i]), dp[i-3]+arr[i - 1] + arr[i]);
	}
	printf("%d", dp[N - 1]);
}

