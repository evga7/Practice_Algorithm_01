#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;

int N;
int arr[100001];
int dp[100001][2];
int res;
void sol()
{
	int i;
	res = arr[0];
	dp[0][0] = dp[0][1] = arr[0];
	for (i =1; i < N; i++)
	{
		dp[i][0] = max(dp[i - 1][1], dp[i-1][0]+arr[i]);
		dp[i][1] = max(dp[i - 1][1]+arr[i], arr[i]);
		res = max({ res,dp[i][0], dp[i][1] });
	}
	cout << res;
}


int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sol();
}


