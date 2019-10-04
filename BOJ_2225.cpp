#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
long long dp[201][201];
int n,k;
int mod = 10e8;
int main()
{
	int i, j, l;
	scanf("%d %d", &n, &k);
	for (i = 0; i <= n; i++)
	{
		dp[i][1] = 1;
	}
	for (i = 0; i <= n; i++)
	{
		for (j = 1; j <=k; j++)
		{
			for (l = 0; l<=i; l++)
			{
				dp[i][j] += (dp[i - l][j - 1])%mod;
			}
		}
	}
	printf("%lld", dp[n][k]%mod);
}
