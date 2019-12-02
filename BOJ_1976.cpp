#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int parent[1001];
int N, M;

int Find(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}
void Merge(int x,int y)
{
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}
int main()
{
	scanf("%d %d", &N, &M);
	int i, j;
	int num;
	for (i = 1; i <= N; i++)
		parent[i] = i;
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <=N; j++)
		{
			scanf("%d", &num);
			if (num)
			{
				Merge(i, j);
			}
		}
	}
	scanf("%d",&num);
	int chk = Find(num);
	for (i = 1; i < M; i++)
	{
		scanf("%d", &num);
		if (chk != Find(num))
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}