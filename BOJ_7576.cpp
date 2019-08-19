#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int>>q;
int N, M;
int map[1005][1005];
int dx[8] = { 0,-1,0,1 };
int dy[8] = { -1,0,1,0 };
int Max = -1;
void bfs()
{
	while (!q.empty())
	{
		int n_x, n_y;
		n_x = q.front().first;
		n_y = q.front().second;
		q.pop();
		int i;
		for (i = 0; i < 4; i++)
		{
			int cur_x = n_x + dx[i];
			int cur_y = n_y + dy[i];
			if (cur_x >= M || cur_x < 0 || cur_y >= N || cur_y < 0 || map[cur_x][cur_y] == -1)
				continue;
			if (map[cur_x][cur_y] >=1)
			{
				if (map[n_x][n_y] + 1 >= map[cur_x][cur_y])
					continue;
			}
			q.push(make_pair(cur_x, cur_y));
			map[cur_x][cur_y] = map[n_x][n_y] + 1;
		}
	}
}
int main()
{
	int cnt = 0;
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j]==1)
				q.push(make_pair(i, j));
		}
	}
	bfs();
	int flag = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (map[i][j] == 0)
			{
				Max = 0;
				flag = 1;
				break;
			}
			Max = max(Max, map[i][j]);
		}
		if (flag)
			break;
	}
	printf("%d\n", Max-1);
}