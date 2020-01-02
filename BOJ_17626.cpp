#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int N;
int arr[250];
int dp[50001];
int main()
{
	cin >> N;
	int i,j;
	for (i = 1; i <= 225; i++)
	{
		arr[i] = i * i;
	}
	int sum = 0;
	int res = 0;
	dp[1] = 1;
	for (i = 2;i<=N;i++)
	{
		int Max = 9;
		for (j = 1; j*j <= i; j++)
		{
			int temp = i - arr[j];
			Max = min(dp[temp]+1, Max);
		}
		dp[i] = Max;
	}
	printf("%d", dp[N]);
}