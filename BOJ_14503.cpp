#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { -1,0,1,0 }; //ºÏµ¿³²¼­
int dy[4] = { 0,1,0,-1 };
int back_dx[4] = { 1,0,-1,0 };
int back_dy[4] = { 0,-1,0,1 };
int N, M;
int arr[52][52];
int cnt = 1;
queue<pair<int, int>>q;
void DFS(int x, int y, int dir)
{
	if (arr[x][y] == 1)
		return;
	if (arr[x][y] == 0)
	{
		cnt++;
		arr[x][y] = 2;
	}
	int i;
	for (i = 0; i < 4; i++)
	{	
		int n_dir = dir - 1 < 0 ? 3 : dir - 1;
		int n_x = x + dx[n_dir];
		int n_y = y + dy[n_dir];
		if (arr[n_x][n_y] == 0)
		{
			DFS(n_x, n_y, n_dir);
			return;
		}
		else
			dir = n_dir;
	}
	int n_x = x + back_dx[dir];
	int n_y = y + back_dy[dir];
	DFS(n_x, n_y, dir);
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	int x, y, d;
	scanf("%d %d %d", &x, &y, &d);
	q.push(make_pair(x, y));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	arr[x][y] = 2;
	DFS(x, y, d);
	printf("%d", cnt);
}
