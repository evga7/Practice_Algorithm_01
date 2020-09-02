#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
vector<pair<int, int>>graph[MAX];
int N;
int	e[MAX];
int cost[MAX];
int v[MAX][18];
void bfs()
{
	queue<int>q;
	q.push(1);
	int i;
	cost[1] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int n_f = graph[cur][i].first;
			int n_s = graph[cur][i].second;
			if (cost[n_f] == -1)
			{
				cost[n_f] = cost[cur] + n_s;
				v[n_f][0] = cur;
				q.push(n_f);
			}

		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++)
	{
		cin >> e[i+1];
	}
	int a, b, c;
	for (i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	fill(cost, cost + N + 1, -1);
	for (i = 0; i <= N; i++)
	{
		fill(v[i], v[i] + 18, -1);
	}
	bfs();
	for (j = 0; j < 18; j++)
	{
		for (i = 2; i <= N; i++)
		{
			if (v[i][j] != -1)
				v[i][j + 1] = v[v[i][j]][j];
		}
	}
	for (i = 1; i <= N; i++)
	{
		int cur = i, c = e[i];
		for (j = 17; j >= 0; j--)
		{
			int u = v[cur][j];
			int dist = cost[cur] - cost[u];
			if (dist < 0)
				dist *= -1;
			if (u == -1 || dist > c)continue;
			cur = u; c -= dist;
		}
		cout << cur << "\n";
	}
}

