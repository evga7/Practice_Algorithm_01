#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int arr[1001];
int dp[1001];
int main(void)
{
	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 1; i <=N; i++)
		scanf("%d", &arr[i]);
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j<=i; j++)
		{
			dp[i] = max(dp[i], dp[i-j]+arr[j]);
		}
	}
	printf("%d", dp[N]);
}