#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int arr[101][101];
int visited[101];
int depth[101];
int N,M;
int result[101];
queue <int> q;
void BFS(int x)
{
	q.push(x);
	visited[x] = 1;
	while (!q.empty())
	{
		int cur_x;
		cur_x = q.front();
		q.pop();
		int i;
		for (i = 1;i <= N; i++)
		{
			if (visited[i] == 0 && arr[cur_x][i] == 1)
			{
				visited[i] = 1;
				q.push(i);
				depth[i] = depth[cur_x] + 1;
			}
		}
	}
}
int main()
{
	int i, j;
	int A, B;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &A, &B);
		arr[A][B] = arr[B][A] = 1;
	}
	for (i = 1; i <=N; i++)
	{
		
		BFS(i);
		for (j = 1; j <= N; j++)
		{
			result[i] += depth[j];
		}
		memset(visited, 0, sizeof(visited));
		memset(depth, 0, sizeof(depth));
	}
	int min = result[1];
	int min_person=1;
	for (i = 1; i <= N; i++)
	{
		if (min > result[i])
		{
			min = result[i];
			min_person = i;
		}
	}
	printf("%d", min_person);
}
