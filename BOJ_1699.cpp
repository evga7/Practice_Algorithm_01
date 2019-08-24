#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>
#include <cmath>
#include <string>
using namespace std;
int N;
int dp[100001];

int main()
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <=sqrt(i); j++)
		{
			if (dp[i] > dp[i - j * j] + 1 || dp[i] == 0)
			{
				dp[i] = dp[i - j * j] + 1;
			}
		}
	}
	printf("%d", dp[N]);
}