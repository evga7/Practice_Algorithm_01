#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N;
int dp[1001];
int main()
{
	dp[0] = 1;
	dp[1] = 1;
	int i;
	scanf("%d", &N);
	for (i = 2; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]*2) % 10007;
	printf("%d", dp[N]);

}
