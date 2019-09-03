#include <iostream>

int arr[101];
int dp[10001];
int main()
{
	int N, K;
	int i,j,k;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	dp[0] = 1;
	for (i = 0; i < N; i++) {
		for (j=arr[i]; j <= K; j++)
			dp[j] += dp[j - arr[i]];
	}
	printf("%d", dp[K]);
}
