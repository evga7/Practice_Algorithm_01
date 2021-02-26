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
int m[101][101];
int dist[101][101];
int solve()
{
	queue<pi>q;
	q.push({ 0,0 });
	dist[0][0] = 1;
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		int cost = dist[cur_x][cur_y];
		q.pop();
		int i;
		for (i = 0; i < 4; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (!m[n_x][n_y] || n_x < 0 || n_x >= N || n_y<0 || n_y >= M ||dist[n_x][n_y])continue;
			dist[n_x][n_y] = cost + 1;
			q.push({ n_x,n_y });
		}
	}
	return dist[N - 1][M - 1];
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%1d", &m[i][j]);
		}
	}
	printf("%d", solve());
}
