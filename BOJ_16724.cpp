#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#define MAX 987654321
using namespace std;
typedef pair<int, int>pi;
int arr[1001][1001];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int visited[1001][1001];
int N, M;
int res = 1;
char c[201];
int dfs(int x,int y, int res)
{
	if (x < 0 || x >= N || y < 0 || y >= M)
		return 0;
	if (visited[x][y]) return visited[x][y];
	visited[x][y] = res;
	return visited[x][y] = dfs(x + dx[arr[x][y]], y + dy[arr[x][y]], res);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i,j;
	cin >> N >> M;
	c['L'] = 1, c['U'] = 0, c['D'] = 2, c['R'] = 3;
	char a;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> a;
			arr[i][j] = c[a];
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)a
		{
				int x = dfs(i, j, res);
				if (res == x)
					res++;
		}
	}
	cout << res-1;
}

a