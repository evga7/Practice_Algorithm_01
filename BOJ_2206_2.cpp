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
int dist[1001][1001][2];
int solve()
{
	queue<pi2>q;
	q.push({ 0, { 0,0 } });
	dist[0][0][0] = 1;
	while (!q.empty())
	{
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;
		int block = q.front().first;
		q.pop();
		if (cur_x == N - 1 && cur_y== M - 1)
		{
			return dist[N - 1][M - 1][block];
		}
		int i;
		for (i = 0; i < 4; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (n_x >= N || n_x < 0 || n_y >= M || n_y < 0)continue;
			if (m[n_x][n_y] && !block)
			{
				dist[n_x][n_y][block + 1] = dist[cur_x][cur_y][block] + 1;
				q.push({ block+1,{n_x,n_y} });
			}
			else if(!m[n_x][n_y]&&!dist[n_x][n_y][block])
			{
				dist[n_x][n_y][block] = dist[cur_x][cur_y][block] + 1;
				q.push({ block,{n_x,n_y} });
			}

		}
	}
    return 0;
}

int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	int i, j;
	cin >> N >> M;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%1d", &m[i][j]);

	res = solve();
	if (res)cout << res;
	else
		cout << -1;
}
