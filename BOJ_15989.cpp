#include <iostream>
#include<string>
#include <stack>
#include <algorithm>
using namespace std;
int T;
int N;
int dp[10001];
int main() 
{
	scanf("%d", &T);
	dp[0] = 1;		int i, j;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 10000; j++)
		{
			if (j - i >= 0)
				dp[j] += dp[j - i];
		}
	}
	while (T--)
	{
		scanf("%d", &N); 

		printf("%d\n", dp[N]);
	}
}