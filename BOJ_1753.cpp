#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;
int V, E,S;
typedef pair<int, int> pi;
#define MAX 987654321
vector<vector<pi>>graph;
int dist[200001];
void bfs()
{
	priority_queue <pi,vector<pi>,greater<pi>> pq;
	pq.push({ 0, S });
	dist[S] = 0;
	int i;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (auto &next:graph[cur])
		{
			int next_x = next.first;
			int Ncost = next.second;
			if (dist[next_x] > cost + Ncost)
			{
				dist[next_x] = cost + Ncost;
				pq.push({dist[next_x], next_x });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E>>S;
	int i;
	int u, v, w;
	graph.resize(V + 1);
	for (i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	fill(dist, dist + V + 1,MAX);
	bfs();
	for (i = 1; i <= V; i++)
	{
		if (dist[i] == MAX)
			cout << "INF\n";
		else
			cout << dist[i]<<"\n";
	}
}