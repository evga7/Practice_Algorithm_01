#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <map>
using namespace std;
int dp[31];
int main()
{
	int N;
	cin >> N;
	int i,j;
	dp[0] = 1;
	dp[2] = 3;
	for (i = 4; i <= N; i+=2)
	{
		dp[i] = dp[i - 2] * 3;
		for (j = 4; j <= i; j += 2)
		{
			dp[i] += dp[i - j]*2;
		}
	}
	cout << dp[N];
}