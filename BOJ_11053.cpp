#include <iostream>
#include <string>
using namespace std;
int arr[10001];
int dp[10001];
int Max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int N;
	int i,j;
	int Min;
	int MAX= -1;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		Min = 0;
		scanf("%d", &arr[i]);
		for (j = 0; j <i; j++)
		{
			if (arr[i] > arr[j] && dp[j] >= Min)
			{
				Min = dp[j];
			}
		}
		dp[i] = Min + 1;
		MAX = Max(MAX, dp[i]);
	}
	printf("%d", MAX);
}

