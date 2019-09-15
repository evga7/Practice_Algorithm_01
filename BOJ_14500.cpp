#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[502][502];
int N, M;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int res = 0;
int visited[502][502];

void chk(int x,int y)
{
	if (arr[x][y] && arr[x][y - 1] && arr[x][y + 1] && arr[x + 1][y])
		res = max(res, arr[x][y] + arr[x][y - 1] + arr[x][y + 1] + arr[x + 1][y]);
	if (arr[x][y] && arr[x-1][y] && arr[x+1][y] && arr[x][y-1])
		res = max(res, arr[x][y] +arr[x - 1][y]+arr[x + 1][y]+arr[x][y - 1]);
	if (arr[x][y] && arr[x][y-1] && arr[x][y+1] && arr[x-1][y])
		res = max(res, arr[x][y] + arr[x][y-1] + arr[x][y+1] + arr[x-1][y]);
	if (arr[x][y] && arr[x - 1][y] && arr[x + 1][y] && arr[x][y + 1])
		res = max(res, arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y + 1]);
}
void DFS(int x,int y,int len,int sum)
{
	if (len == 4)
	{
		res = max(sum, res);
		return;
	}
	else
	{
		int i;
		for (i = 0; i < 4; i++)
		{
			int n_x = x + dx[i];
			int n_y = y + dy[i];
			if (n_x < 0 || n_x > N || n_y<0 || n_y>M || visited[n_x][n_y])
				continue;
			visited[n_x][n_y] = 1;
			DFS(n_x, n_y, len + 1, sum + arr[n_x][n_y]);
			visited[n_x][n_y] = 0;
		}
	}
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <=N; i++)
		for (j = 1; j <=M; j++)
			scanf("%d", &arr[i][j]);
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <=M; j++)
		{
			DFS(i, j, 0, 0);
			chk(i,j);
		}
	}
	printf("%d", res);
}
