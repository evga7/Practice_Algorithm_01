#include <iostream>
#include <queue>
using namespace std;
vector<int> v;
int visited[8];
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
		for (i = idx; i <= N; i++)
		{
			v.push_back(i);
			dfs(i,cnt + 1);
			v.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	dfs(1,0);
}