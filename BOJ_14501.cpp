#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int N;
int day[20];
int point[20];
int dp[20];
int main()
{
	scanf("%d", &N);
	int i,j;
	for (i = 1; i <=N; i++)
		scanf("%d %d", &day[i],&point[i]);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j<=i; j++)
		{
			if (day[j] + i <= N + 1 && dp[day[j] + i] < dp[j] + point[j])
			{
				dp[day[j] + i] = dp[j] + point[j];
			}
		}
	}
	cout << dp[N + 1];
}