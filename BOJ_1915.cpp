#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int N, M;
int arr[1001][1001];
int res = 0;
int main()
{
	scanf("%d %d", &N, &M);
	int i, j;
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <=M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <=M; j++)
		{
			if (arr[i][j])
			{
					arr[i][j] = min({ arr[i - 1][j],arr[i - 1][j - 1],arr[i][j - 1] }) + 1;
					res = max(res, arr[i][j]);
			}
		}
	}
	cout << res*res;
}