#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
vector<int> v;
int arr[14];
int arr2[14];
int n;
void dfs(int start,int depth)
{
	int i;
	if (depth== 6)
	{
		for (i = 0; i < 6; i++)
			printf("%d ", arr2[i]);
		printf("\n");
	}

	for (i = start; i < n; i++)
	{
		arr2[depth] = arr[i];
		dfs(i + 1, depth + 1);
	}
}
int main() {
	int i;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		dfs(0, 0);
		printf("\n");
	}
}