#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int res = -1;
int N, S, M;
int V[101];
int dp[1001][1001];

int main()
{
	scanf("%d %d %d", &N, &S, &M);
	int i,j;
	for (i = 1; i <=N; i++)
		scanf("%d", &V[i]);
	dp[0][S] = 1;
	for (i = 1; i <=N; i++)
	{
		for (j =0; j <=M; j++)
		{
			if (!dp[i - 1][j])
				continue;
			if (j - V[i] >= 0)
				dp[i][j - V[i]] = 1;
			if (j + V[i] <= M)
				dp[i][j + V[i]] = 1;
		}
	}
	for (i = 0; i <=M; i++)
	{
		if (dp[N][i])
			res = i;
	}
	printf("%d", res);
}
