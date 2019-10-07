#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;
int N, M;
int arr[10001][1001];
int visited[1001];
void DFS(int pos)
{
		int i;
		visited[pos] = 1;
		for (i = 1; i <=N; i++)
		{
			if (!visited[i]&&arr[pos][i])
			{
				DFS(i);
			}
		}
}
int main()
{
	scanf("%d %d", &N, &M);
	int i;
	int a, b;
	int res = 0;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (i = 1; i <= N; i++)
		if (!visited[i])
		{
			DFS(i);
			res++;
		}
	printf("%d", res);
}