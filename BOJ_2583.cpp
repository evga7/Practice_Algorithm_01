#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, int>> q;

int arr[101];
int dp[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int M,N;
int BFS(int x,int y)
{
	int i;
	q.push(make_pair(x, y));
	dp[x][y] = 1;
	int cnt = 1 ;
	while (!q.empty())
	{
		int cur_X, cur_Y;
		cur_X = q.front().first;
		cur_Y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int n_X, n_Y;
			n_X = cur_X + dx[i];
			n_Y = cur_Y + dy[i];
			if (n_X < 0 || n_X >= N || n_Y < 0 || n_Y >= M||dp[n_X][n_Y])
				continue;
			dp[n_X][n_Y] = 1;
			q.push(make_pair(n_X, n_Y));
			cnt++;
		}
	}
	return cnt;
}

int compare(const void *a, const void *b)
{
	int *A = (int*)a;
	int *B = (int*)b;
	if (*A > *B)
		return 1;
	else if (*A < *B)
		return -1;
	else
		return 0;
}

int main()
{
	int i,j,q,w,k;
	int x1, y1, x2, y2;
	int cnt = 0;
	scanf("%d %d %d", &M,&N,&k);
	getchar();
	memset(dp, 0, sizeof(dp));
	memset(arr, 0, sizeof(arr));
	for (i = 0; i < k; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (q= x1; q <x2; q++)
		{
			for (w = y1; w <y2; w++)
			{
				dp[q][w] = 1;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (dp[i][j] == 0)
			{
				arr[cnt++]=BFS(i, j);
			}
		}
	}
	qsort(arr,cnt, sizeof(int), compare);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
}