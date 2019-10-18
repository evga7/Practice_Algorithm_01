#include <iostream>
#include<string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int T;
int dp[101][100001];
int arr[101][2];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int i,j,k;
	for (i = 1; i <=N; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (i = 1; i <=N; i++)
	{
		for (j = 0; j <= K; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j-arr[i][0]>=0)
			dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
		}
	}
	printf("%d", dp[N][K]);
}