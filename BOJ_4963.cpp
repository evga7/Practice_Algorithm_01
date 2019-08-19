#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int>>q;
int N, M;
int map[55][55];
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
void bfs(int x, int y)
{
	map[x][y] = -1;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int n_x, n_y;
		n_x = q.front().first;
		n_y = q.front().second;
		q.pop();
		int i;
		for (i = 0; i < 8; i++)
		{
			int cur_x = n_x + dx[i];
			int cur_y = n_y + dy[i];
			if (cur_x >= M || cur_x < 0 || cur_y >= N || cur_y < 0 || map[cur_x][cur_y] == -1 || map[cur_x][cur_y] == 0)
				continue;
			q.push(make_pair(cur_x, cur_y));
			map[cur_x][cur_y] = -1;
		}
	}
}
int main()
{
	int cnt = 0;
	while (1)
	{
		int i, j;
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)
			break;
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		cnt = 0;
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (map[i][j] == 1)
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		memset(map, 0, sizeof(map));
	}
}