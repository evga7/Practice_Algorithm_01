#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[101];
int n;
long long dp[101][21];
long long DFS(int Sum, int cnt)
{
	if (Sum < 0 || Sum>20)
		return 0;
	if (dp[cnt][Sum] != -1) return dp[cnt][Sum];
	if (cnt == n - 2)
	{
		if (Sum == arr[n - 1])
			return 1;
		else
			return 0;
	}
	long long &res = dp[cnt][Sum];
	res = 0;
	res+=DFS(Sum + arr[cnt + 1], cnt + 1)+DFS(Sum - arr[cnt + 1], cnt + 1);
	return res;
}
int main()
{
	scanf("%d", &n);
	int i,j;
	for (i = 0; i <n; i++)
	{
		scanf("%d", &arr[i]);
	}
	fill(&dp[0][0], &dp[0][0] + 101 * 21, -1);
	printf("%lld", DFS(arr[0], 0));
}