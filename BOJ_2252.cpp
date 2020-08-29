#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int N, M;
int indegrees[32001];
vector<int> v[32001];
void bfs()
{
	int i;
	queue<int>q;
	for (i = 1; i <= N; i++)
	{
		if (indegrees[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur<<" ";
		for (i = 0; i < v[cur].size(); i++)
		{
			if (--indegrees[v[cur][i]] == 0)
			{
				q.push(v[cur][i]);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int i;
	int a, b;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b;
		indegrees[b]++;
		v[a].push_back(b);
	}
	bfs();
	
}
