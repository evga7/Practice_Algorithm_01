#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001];
int visited[1001][1001][2];
queue<pair<pair<int, int>,int>> q;
int N, M;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int res = 2100000000;
int BFS()
{
	q.push(make_pair(make_pair(0, 0),1));
	visited[0][0][1] = 1;
	while (!q.empty())
	{
		int cur_x, cur_y;
		int block;
		cur_x = q.front().first.first;
		cur_y = q.front().first.second;
		block = q.front().second;
		q.pop();
		int i;
		int n_x, n_y;
		if (cur_x == N - 1 && cur_y == M - 1)
		{
			return visited[N - 1][M - 1][block];
		}
		for (i = 0; i < 4; i++)
		{
			n_x = cur_x + dx[i];
			n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M)
				continue;
			if (arr[n_x][n_y] == 1&&block)
			{
				visited[n_x][n_y][block-1] = visited[cur_x][cur_y][block]+1;
				q.push(make_pair(make_pair(n_x, n_y),block-1));
			}
			else if (arr[n_x][n_y] == 0&&visited[n_x][n_y][block]==0)
			{
				visited[n_x][n_y][block] = visited[cur_x][cur_y][block] + 1;
				q.push(make_pair(make_pair(n_x, n_y),block));
			}
		}
	}
	return -1;
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	printf("%d", BFS());
}

