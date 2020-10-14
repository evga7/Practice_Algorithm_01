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
int arr[1001][1001];
ll dp[3][1001][1001];
int visited[1001][1001];
int dx[3] = { 0,0,1 };
int dy[3] = { -1,1,0 };
int solve(int dir,int x,int y)
{
	ll& ret = dp[dir][x][y];
	if (x == N - 1 && y == M - 1)
		return arr[x][y];
	if (ret != MIN)
		return ret;
	int i;
	ll n1, n2, n3;
	n1 = n2 = n3 = MIN;
	visited[x][y] = 1;
	if (y - 1 >=0 &&! visited[x][y-1])
		n1 = solve(0, x, y - 1);
	if (y + 1 < M && !visited[x][y + 1])
		n2 = solve(1, x, y + 1);
	if (x + 1 < N && !visited[x + 1][y])
		n3 = solve(2, x + 1, y);
	visited[x][y] = 0;
	return ret = arr[x][y] + max({ n1,n2,n3 });
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = MIN;
		}
	}
	 cout<<solve(0,0,0);
}