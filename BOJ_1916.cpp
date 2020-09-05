#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#define MAX 987654321
using namespace std;
typedef pair<int, int>pi;
vector<vector<pi>>graph;
int dist[1001];
int N, M;
int S, E;
void bfs()
{
	priority_queue<pi, vector<pi>, greater<pi>>pq;
	pq.push({ 0, S });
	dist[S] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (auto g : graph[cur])
		{
			int next = g.first;
			int n_cost = g.second;
			if (dist[next] > cost + n_cost)
			{
				dist[next] = cost + n_cost;
				pq.push({dist[next],next });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i;
	cin >> N >> M;
	graph.resize(N + 1);
	int a, b, c;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	cin >> S >> E;
	fill(dist, dist + N + 1, MAX);
	bfs();
	cout << dist[E];
}

