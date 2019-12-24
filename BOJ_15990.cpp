#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Mod 1000000009;
long long dp[100001][4];

int main()
{
	int N;
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][3] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	scanf("%d", &N);
	for (int i = 4; i <= 100000; i++)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%Mod;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % Mod;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % Mod;
	}
	while (N--)
	{
		int T;
		scanf("%d", &T);
		printf("%lld\n", (dp[T][1] + dp[T][2] + dp[T][3]) % 1000000009);
	}
}