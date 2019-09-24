#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
int arr[16][16];
int N;
int res = 0;
void DFS(int x, int y, int op)
{
	if (x == N - 1 && y == N - 1)
	{
		res++;
		return;
	}
	if (op == 0)
	{
		if (arr[x][y + 1] == 0 && y +1< N)
		{
			DFS(x, y + 1, 0);
			if (x + 1 < N && arr[x+1][y] == 0 &&arr[x + 1][y + 1] == 0)
			{
				DFS(x + 1, y + 1, 2);
			}
		}

	}
	else if (op == 1)
	{
		if (arr[x+1][y] == 0 && x +1< N)
		{
			DFS(x+1, y, 1);
			if (y + 1 < N && arr[x][y+1] == 0&& arr[x + 1][y + 1] == 0)
			{
				DFS(x + 1, y + 1, 2);
			}
		}

	}
	else
	{
		if (y + 1 < N && arr[x][y + 1] == 0)
		{
			DFS(x, y + 1, 0);
		}
		if (x + 1 < N && arr[x + 1][y] == 0)
		{
			DFS(x + 1, y, 1);
		}
		if (x + 1 < N && y + 1 < N && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0)
		{
			DFS(x + 1, y + 1, 2);
		}
	}
}
int main()
{
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	DFS(0, 1, 0);
	printf("%d", res);
}