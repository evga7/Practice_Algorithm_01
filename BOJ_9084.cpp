#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
using namespace std;
int T, N, M;
int arr[21];
int main()
{
	int i, j;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		scanf("%d", &M);
		int dp[10001] = { 0 };
		dp[0] = 1;
		for (i = 0; i < N; i++)
		{
			for (j = arr[i]; j <= M; j++)
			{
				dp[j] += dp[j - arr[i]];
			}
		}
		printf("%d\n", dp[M]);
	}

}