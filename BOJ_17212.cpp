#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int coin[4] = { 1,2,5,7 };
int dp[100001];
int main()
{
	int N;
	int res = 0;
	int Min = 100001;
	scanf("%d", &N);
	int i,j;
	int cnt = 0;
	for (i = 0; i <= N; i++)
		dp[i] = 100001;
	dp[0] = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = coin[i]; j <= N; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}

	}
	printf("%d", dp[N]);
}