#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef pair<int, char> pi4;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res;
vec v;
int m[501][501];
int dp[501][501];
int solve()
{
	int i, j;
	dp[0][0] = m[0][0];
	for (i = 1; i < N; i++)
	{
		for (j = 0; j <=i; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j]+m[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + m[i][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + m[i][j];
		}
	}
	for (i = 0; i <= N; i++)
	{
		res = max(res, dp[N - 1][i]);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= i; j++)
		{
			cin >> m[i][j];
		}
	}
	cout<< solve();
}
