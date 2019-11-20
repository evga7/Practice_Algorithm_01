#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int arr[65][65];
void solve(int size,int x,int y)
{
	if (size==1)
	{
		printf("%d",arr[x][y]);
		return;
	}
		int chk = arr[x][y];
		int i, j;
		int half = size / 2;
		for (i=x;i<x+size;i++)
			for (j=y;j<y+size;j++)
				if (chk != arr[i][j])
				{
					printf("(");
					solve(half, x, y);
					solve(half, x, y+half);
					solve(half, x+half, y);
					solve(half, x+half, y+half);
					printf(")");
					return;
				}
	printf("%d", chk);
	return;
}
int main()
{
	int N;
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%1d", &arr[i][j]);
	solve(N,0,0);
}