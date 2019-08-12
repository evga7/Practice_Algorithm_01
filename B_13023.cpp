#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
vector<int> v[2001];
int N, M;
int visited[2001] = { 0 };
int dfs(int start, int depth)
{
	if (depth == 5)
	{
		return 1;
	}
	visited[start] = 1;
	int i;
	for (i = 0; i <v[start].size(); i++)
	{
		int next = v[start][i];
		if (!visited[next]){
		if (dfs(next, depth + 1))
            return 1;
        }
		
	}
	visited[start] = 0;
	return 0;
}
int main()
{
	int i;
	int a, b;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (i = 0; i < N; i++)
	{
		if (dfs(i, 1))
		{
			printf("1");
			return 0; 
		}
	}
		printf("0");
}