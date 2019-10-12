#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
char arr[101][101];
int visited[101][101];
int N,M;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
queue<pair<int, int>> q;
int is_not_in_Area(int x,int y)
{
	if (x < 0 || x >= N || y < 0 || y>=M)
		return 1;
	else
		return 0;
}
int BFS(int x, int y)
{
	q.push(make_pair(x, y));
	visited[x][y] = 0;
	int i;
	int max = 0;
	while (!q.empty())
	{
		int cur_x, cur_y;
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int n_x, n_y;
			n_x = cur_x + dx[i];
			n_y = cur_y + dy[i];
			if (is_not_in_Area(n_x,n_y)||visited[n_x][n_y])
				continue;
			visited[n_x][n_y] = visited[cur_x][cur_y] + 1;
			if (max < visited[n_x][n_y])
				max = visited[n_x][n_y];
			q.push(make_pair(n_x, n_y));
		}
	}
	return max;
}
void copy_map()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			if (arr[i][j] == 'W')
				visited[i][j] = 1;
			else
				visited[i][j] = 0;
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	int i, j;
	getchar();
	int max = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			copy_map();
			if (visited[i][j] == 0)
			{
				int num = BFS(i, j);
				if (max < num)
					max = num;
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	printf("%d", max);
}