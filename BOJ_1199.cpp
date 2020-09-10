#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX 2147483647
int N, M;
int d[1001];
int arr[1001][1001];
void dfs(int node)
{
	int i;
	for (i = 1; i <= N; i++)
		while (arr[node][i])
		{
			arr[node][i]--;
			arr[i][node]--;
			dfs(i);
		}
	cout << node<<" ";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i,j;
	int flag = 0;
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])
			{
				d[i] += arr[i][j];
				d[j] += arr[i][j];
			}
		}
	}
	for (i = 1; i <= N;i++)
	{
		d[i]/= 2;
		if (d[i] %2)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
		cout << "-1";
	else
		dfs(1);
}

