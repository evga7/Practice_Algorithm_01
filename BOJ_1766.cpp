#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;
int N,M;
typedef pair<int,int>pi;
#define MAX 987654321
vector<vector<int>>graph;
int indegrees[32001];
void solve()
{
	int i;
	priority_queue<int,vector<int>,greater<int>>q;
	for (i=1;i<=N;i++)
	{
		if (indegrees[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int cur=q.top();
		q.pop();
		cout<<cur<<" ";
		for (auto g:graph[cur])
		{
			if (--indegrees[g]==0)
				q.push(g);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);	
	cin>>N>>M;
	graph.resize(N+1);
	int i,j;
	int a,b;
	for (i=0;i<M;i++)
	{
		cin>>a>>b;
		graph[a].push_back(b);
		indegrees[b]++;
	}
	solve();

}
