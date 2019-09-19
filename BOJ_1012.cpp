#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int>> q;
int arr[51][51];
int arr2[1500];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int N, M;
void BFS(int x,int y)
{
	q.push(make_pair(x, y));
	arr[x][y] = -1;
	while (!q.empty())
	{
		int cur_x, cur_y;
		cur_x = q.front().first;
		cur_y = q.front().second;
		int i;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int n_x, n_y;
			n_x = cur_x + dx[i];
			n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y<0 || n_y>=M || arr[n_x][n_y] == 0 || arr[n_x][n_y] == -1)
				continue;
			arr[n_x][n_y] = -1;
			q.push(make_pair(n_x, n_y));
		}
	}
}
int main()
{
	int K;
	int T;
	int i,j;
	scanf("%d", &T);
	while (T--)
	{
		memset(arr, 0, sizeof(arr));
		int cnt = 0;
		scanf("%d %d %d", &N, &M, &K);
		int x, y;
		for (i = 0; i < K; i++)
		{
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}
		for (i = 0; i < N; i++)
		{
			for (j=0;j<M;j++)
				if (arr[i][j] == 1)
				{
					BFS(i, j);
					cnt++;
				}
		}
		printf("%d\n", cnt);
	}
}