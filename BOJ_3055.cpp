#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
char map[51][51];
int visited[51][51];
int visited2[51][51];
int N, M;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
queue<pair<int, int>>q;
queue<pair<int, int>>q2;
int res = 999999999;
void BFS1()
{
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		int i;
		int n_x;
		int n_y;
		for (i = 0; i < 4; i++)
		{
			n_x = cur_x + dx[i];
			n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M || map[n_x][n_y] != '.'||map[n_x][n_y]=='X')
				continue;
			if (visited[n_x][n_y])
			{
				if (visited[cur_x][cur_y] + 1 < visited[n_x][n_y])
				{
					visited[n_x][n_y] = visited[cur_x][cur_y]+1;
					q.push(make_pair(n_x, n_y));
				}
			}
			else
			{
				visited[n_x][n_y] = visited[cur_x][cur_y] + 1;
				q.push(make_pair(n_x, n_y));
			}
		}

	}
}
void BFS2()
{
	while (!q2.empty())
	{
		int cur_x = q2.front().first;
		int cur_y = q2.front().second;
		q2.pop();
		int i;
		int n_x;
		int n_y;
		for (i = 0; i < 4; i++)
		{
			n_x = cur_x + dx[i];
			n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M)
				continue;
			if (map[n_x][n_y] == 'D')
			{
				if (visited[cur_x][cur_y] == 0)
					res = min(res, visited2[cur_x][cur_y] + 1);
				else if (visited2[cur_x][cur_y] < visited[cur_x][cur_y])
					res = min(res, visited2[cur_x][cur_y] + 1);
			}
			if (map[n_x][n_y] == '.')
			{
				if (visited2[n_x][n_y])
				{
					if (visited2[cur_x][cur_y] + 1 < visited2[n_x][n_y])
					{
						visited2[n_x][n_y] = visited2[cur_x][cur_y] + 1;
						q2.push(make_pair(n_x, n_y));
					}
				}
				else
				{
					visited2[n_x][n_y] = visited2[cur_x][cur_y] + 1;
					q2.push(make_pair(n_x, n_y));
				}
			}
		}

	}
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	getchar();
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%c", &map[i][j]);
			if (map[i][j] == '*')
			{
				q.push(make_pair(i, j));
			}
			else if (map[i][j] == 'S')
			{
				q2.push(make_pair(i, j));
			}
		}
		getchar();
	}
	BFS1();
	BFS2();
	if (res == 999999999)
		printf("KAKTUS");
	else
		printf("%d", res);
}