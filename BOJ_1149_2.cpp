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
int res = MAX;
vec v;
int m[1001][1001];
int dp[1001][1001];
int solve()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + m[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + m[i][2];
		dp[i][3] = min(dp[i - 1][2], dp[i - 1][1]) + m[i][3];
	}
	for (i = 1; i <= 3; i++)
		res = min(res, dp[N][i]);
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			cin >> m[i][j];
		}
	}
	cout << solve();
}
