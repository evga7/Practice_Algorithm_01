#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
long long dp[31][31];
long long C(int N, int r)
{
	if (dp[N][r] > 0)
		return dp[N][r];
	if (r==0||N==r)
	{
		return dp[N][r] = 1;
	}
	else
		return dp[N][r] += C(N - 1, r) + C(N - 1, r - 1);
}
int main()
{
	int T;
	int r, n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &r, &n);
		C(n, r);
		printf("%d\n", dp[n][r]);	
	}
}