#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N;
int arr[1001][1001];
int dp[1001][3];
int main()
{
	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d %d %d", &arr[i][0],&arr[i][1],&arr[i][2]);
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	for (i = 0; i < N; i++)
	{
		dp[i][0] =arr[i][0]+ min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] =arr[i][1]+ min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] =arr[i][2]+ min(dp[i - 1][0], dp[i - 1][1]);
	}
	printf("%d", min({ dp[N - 1][0],dp[N - 1][1],dp[N - 1][2] }));
}
