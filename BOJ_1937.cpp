#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <stack>
#include <set>
#include <map>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
int N, M;
int arr[501][501];
int dp[501][501];
int visited[501][501];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int res = 0;
int solve(int x,int y)
{
	int i;
	int& ret = dp[x][y];
	if (ret)
		return dp[x][y];
	ret = 1;
	for (i = 0; i < 4; i++)
	{
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if (x < 0 || x >= N || y < 0 || y >= N)
			continue;
		if (arr[x][y] < arr[n_x][n_y])
		{
			ret=max(ret,solve(n_x, n_y)+1);
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			res = max(res, solve(i, j));
	cout << res;
	 
}