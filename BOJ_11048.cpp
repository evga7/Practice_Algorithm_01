#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>
#include <cmath>
#include <string>
using namespace std;
int N, M;
int arr[1001][1001];
int dp[1001][1001];
void DFS()
{

}
int main()
{
	scanf("%d %d", &N, &M);
	int i, j;
	for (i = 1; i <=N; i++)
		for (j = 1; j <=M; j++)
			scanf("%d", &arr[i][j]);
	dp[1][1] = arr[1][1];
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			dp[i][j] = arr[i][j]+max(max(dp[i -1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
	}
	printf("%d", dp[N][M]);
}