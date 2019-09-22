#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int N;
int arr[101][101];
int visited[101][101];
int cnt = 2;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
queue<pair<int, int>>q;
void BFS1()
{
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		int i;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int n_x;
			int n_y;
			n_x = cur_x + dx[i];
			n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N || visited[n_x][n_y] || arr[n_x][n_y] == 0)
				continue;
			visited[n_x][n_y] = 1;
			arr[n_x][n_y] = cnt;
			q.push(make_pair(n_x, n_y));
		}
	}
}
int res = 999999;
int BFS2(int cnt)
{
	queue<pair<int, int>>q;
	int i,j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			if (arr[i][j] == cnt)
			{
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
	}
	int res2 = 0;
	while (!q.empty())
	{
		int cur_size = q.size();
		for (i = 0; i <cur_size; i++)
		{
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();
			for (j = 0; j < 4; j++)
			{
				int n_x = cur_x + dx[j];
				int n_y = cur_y + dy[j];
				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N || visited[n_x][n_y])
					continue;
				if (arr[n_x][n_y] != cnt && arr[n_x][n_y])
				{
					return res2;
				}
				else if (!arr[n_x][n_y])
				{
					visited[n_x][n_y] = 1;
					q.push(make_pair(n_x, n_y));
				}
			}
		}
		res2++;
	}
}

int main()
{
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (!visited[i][j] && arr[i][j] == 1)
			{
				q.push(make_pair(i, j));
				arr[i][j] = cnt;
				visited[i][j] = 1;
				BFS1();
				cnt++;
			}
		}
	}
	for (i = 2; i <cnt; i++)
	{
		memset(visited, 0, sizeof(visited));
		res = min(res, BFS2(i));
	}

	printf("%d", res);

}