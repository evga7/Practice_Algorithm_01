#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[501][501];
int N, M;
int res = 0;
int dp[501][501];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0};
int DFS(int x, int y)
{
	if (x == N-1&& y ==M-1)
		return 1;
    if (x < 0 || x >= N || y < 0 || y >= M)
		return 0;
	if (dp[x][y]!=-1)
		return dp[x][y];
	dp[x][y] = 0;
	int i;
	for (i = 0; i < 4; i++)
	{
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if (arr[x][y] > arr[n_x][n_y])
			dp[x][y]+=DFS(n_x, n_y);
	}
	return dp[x][y];
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);
	for (i=0;i<=N;i++)
        fill(dp[i],dp[i]+M+1,-1);
	printf("%d", DFS(0, 0));
}