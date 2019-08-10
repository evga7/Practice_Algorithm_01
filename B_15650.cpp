#include <iostream>
#include <queue>
using namespace std;
vector<int> v;
int visited[10];
int N, M;
void dfs(int idx,int cnt){
	int i, j;
	if (cnt == M)
	{
		for (i = 0; i < v.size(); i++)
		{
			printf("%d ", v[i]);
		}
		printf("\n");
	}
	for (i = idx; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			v.push_back(i);
			dfs(i,cnt + 1);
			visited[i] = 0;
			v.pop_back();
		}
	}

}
int main()
{
 	scanf("%d %d", &N, &M);
	dfs(1,0);
}