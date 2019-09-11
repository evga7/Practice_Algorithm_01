#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int arr[101][101];
int visited[101][101];
int N, M;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0, };
priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
int res = 999999;
void BFS()
{
	visited[0][0] = 1;
	q.push(make_pair(0,make_pair(0,0)));
	while (!q.empty())
	{
		int cur_x;
		int cur_y;
		int block;
		cur_x = q.top().second.first;
		cur_y = q.top().second.second;
		block = q.top().first;
		q.pop();
		int i;
		if (cur_x == N - 1 && cur_y == M - 1)
		{
			res = block;
			return;
		}
		for (i = 0; i < 4; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (n_x<0 || n_x>=N || n_y<0 || n_y>=M||visited[n_x][n_y])
				continue;
			if (arr[n_x][n_y] == 1)
			{
				q.push(make_pair(block+1,make_pair(n_x, n_y)));
			}
			else
			{
				q.push(make_pair(block,make_pair(n_x, n_y)));
			}
			visited[n_x][n_y] = 1;
		}
	}
}
int main()
{
	scanf("%d %d", &M, &N);
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%1d", &arr[i][j]);
	BFS();
	printf("%d", res);
}