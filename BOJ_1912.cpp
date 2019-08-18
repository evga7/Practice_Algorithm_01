#include <iostream>
#include <queue>
using namespace std;
int arr[100001];
int dp[100001];
int main()
{
	int N;
	int i, j;
	int ans;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	ans=dp[0] = arr[0];
	for (i = 1; i < N; i++)
	{
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		ans = max(dp[i], ans);
	}
	printf("%d", ans);
}


