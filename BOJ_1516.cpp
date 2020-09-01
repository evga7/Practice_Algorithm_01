#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int N;
vector<int> indegree;
vector<vector<int>> graph;
vector<int> time;
vector<int> res;
void dfs()
{
	int i;
	queue<int>q;
	for (i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			res[i] = time[i];
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int& next : graph[cur])
		{
			if (--indegree[next] == 0)
				q.push(next);
			res[next] = max(res[next], res[cur] + time[next]);
		}
	}
	for (i = 1; i <= N; i++)
		cout << res[i] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i;
	cin >> N;
	indegree.resize(N + 1);
	graph.resize(N + 1);
	time.resize(N + 1);
	res.resize(N + 1);
	for (i = 1; i <=N; i++)
	{
		int num=-2;
		int flag = 0;
		while (1)
		{
			cin >> num;
			if (num == -1)
			{
				flag = 0;
				break;
			}
			if (!flag)
			{
				flag = 1;
				time[i] = num;
			}
			else
			{
				indegree[i]++;
				graph[num].push_back(i);
			}
		}
	}
	dfs();
}
