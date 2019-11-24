#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int arr[101][101];
int visited[101];
int N;
int res;
void DFS(int x,int y,int cnt)
{
	int i;
	visited[x] = 1;
	if (x == y)
	{
		res = cnt;
		return;
	}
	for (i = 1; i <=N; i++)
	{
		if (arr[x][i] && !visited[i])
		{
			DFS(i, y, cnt + 1);
		}
	}
}
int main()
{
	int X, Y;
	int i;
	int M;
	scanf("%d %d %d %d", &N, &X, &Y, &M);
	int a, b;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	DFS(X, Y, 0);
	if (res == 0)
		printf("-1");
	else
	printf("%d", res);
}