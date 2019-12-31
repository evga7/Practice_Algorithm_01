#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <map>
using namespace std;
int arr[101][101];
int N;
long long visited[101][101];
int res = 0;
long long go(int x,int y)
{
	if (x==N-1&&y==N-1)
		return 1;
	if (x >= N || y >= N)
		return 0;
	long long &ret = visited[x][y];
	if (ret!=-1)
		return ret;
	ret = 0;
	ret+=go(x + arr[x][y], y);
	ret+=go(x, y + arr[x][y]);
	return ret;
}
int main()
{
	cin >> N;
	int i,j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			visited[i][j] = -1;
		}
	}

	printf("%lld", go(0, 0));
}