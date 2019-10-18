#include <iostream>
#include<string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int N;
long long dp[101];
int main()
{
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= 6; i++)
		dp[i] = i;
	for (i = 7; i <= N; i++)
	{
		for (j = 1; j <= i - 3; j++)
		{
			long long temp = dp[j] * (i- j-1);
			dp[i] = max(dp[i], temp);
		}
	}
	printf("%lld", dp[N]);
}