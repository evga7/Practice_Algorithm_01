#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
int arr[11][11];
int chk[11];
int min_value = 99999999;
int n;
int Min(int a, int b)
{
	return a < b ? a : b;
}

void dfs(int start,int cnt,int sum,int end)
{
	int i;
	if (n == cnt && start == end)
	{
		min_value = Min(min_value, sum);
	}
	if (!chk[start])
	{
		chk[start] = 1;
		for (i = 0; i < n; i++)
		{
			if (arr[start][i]==0)
				continue;
			dfs(i, cnt+1, sum + arr[start][i],end);
		}
		chk[start] = 0;
	}
}
int main() {
	int i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}
	for (i = 0; i < n; i++)
		dfs(i, 0, 0, i);
	printf("%d", min_value);
}