#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
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
			printf("%d ", v[i]);
		printf("\n");
	}
	int chk[10000] = { 0 };
	for (i = idx; i < N; i++)
	{
		if (!visited[i] && !chk[arr[i]])
		{
			visited[i] = 1;
			chk[arr[i]] = 1;
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
	int j = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	dfs(0,0);
}