#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int arr[21][21];
int res = 99999999;
int visited[21];
void DFS(int cnt, int idx)
{
	if (cnt == N / 2)
	{
		int i, j;
		int A, B;
		A = B = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (visited[i] && visited[j]) A += arr[i][j];
				if (!visited[i] && !visited[j])	B += arr[i][j];
			}
		}
		res = min(abs(A - B), res);
		return;
	}
	int i;
	for (i = idx; i < N; i++)
	{
		visited[i] = 1;
		DFS(cnt + 1, i + 1);
		visited[i] = 0;
	}
}
int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	DFS(0, 0);
	printf("%d", res);
}
