#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int N;
int dp[1000001];
int main()
{

	dp[0] = 1;
	dp[1] = 2;
	scanf("%d", &N);
	int i;
	for (i = 2; i < N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])%15746;
	printf("%d", dp[N - 1]%15746);
}
