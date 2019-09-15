#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int arr[21][21];
int visited[21][21];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
queue <pair<pair<int, int>, int>> q;
int N;
bool cmp_food(int min_x, int min_y, int n_x, int n_y)
{
	if (min_x >= n_x)
	{
		if (min_x == n_x)
		{
			if (min_y > n_y)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
int BFS(int size)
{
	int min_x = 21;
	int min_y = 21;
	int min_dis = 9999;
	arr[min_x][min_y] = 9999;
	while (!q.empty())
	{
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int dis = q.front().second;
		int i;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N ||
				arr[n_x][n_y]>size || visited[n_x][n_y])
				continue;
			if (min_dis >= dis && arr[n_x][n_y] != 0&& size > arr[n_x][n_y])
			{
				if (cmp_food(min_x, min_y, n_x, n_y))
				{
					min_x = n_x;
					min_y = n_y;
					min_dis = dis;
				}
			}
			visited[n_x][n_y] = 1;
			q.push(make_pair(make_pair(n_x, n_y), dis + 1));
		}
	}
	if (min_x == 21)
		return 0;
	else
	{
		q.push(make_pair(make_pair(min_x, min_y), 1));

		arr[min_x][min_y] = 0;
		memset(visited, 0, sizeof(visited));
		visited[min_x][min_y] = 1;
		return min_dis;
	}
}

int main()
{
	scanf("%d", &N);
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9)
			{
				q.push(make_pair(make_pair(i, j), 1));
				visited[i][j] = 1;
				arr[i][j] = 0;
			}

		}
	}

	int size = 2;
	int res = 0;
	int cnt = 0;


	while (1)
	{
		int dis = BFS(size);
		if (!dis)
			break;
		res += dis;
		cnt++;
		if (cnt == size && size < 7)
		{
			size++;
			cnt = 0;
		}

	}
	printf("%d", res);

}