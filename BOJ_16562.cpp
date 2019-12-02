#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int parent[10001];
int money[10001];
int N, M, K;
int res = 0;
int Find(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}
void Merge(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y)
		return;
	if (money[x] < money[y])
		parent[y] = x;
	else
		parent[x] = y;
	return;
}
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	int i;
	int a, b;
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &money[i]);
		parent[i] = i;
	}
	for (i = 1; i <= M; i++)
	{
		scanf("%d %d", &a, &b);
		Merge(a, b);
	}
	for (i = 1; i <= N; i++)
	{
		if (parent[i]==i)
			res += money[i];
	}
		if (K < res) printf("Oh no");
		else printf("%d", res);
	
}