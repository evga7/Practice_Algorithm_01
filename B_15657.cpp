#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v;
int arr[10];
int visited[10];
int N, M;
void dfs(int idx,int cnt)
{
	int i;
	if (cnt == M)
	{
		for (i = 0; i < v.size(); i++)
			printf("%d ",v[i]);
		printf("\n");
	}
	else
	{
		for (i = idx; i < N; i++)
		{

			visited[i] = 1;
			v.push_back(arr[i]);
			dfs(i,cnt + 1);
			v.pop_back();
			visited[i] = 0;

		}
	}
}
int main()
{

	int i;
	int num;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	dfs(0,0);
}