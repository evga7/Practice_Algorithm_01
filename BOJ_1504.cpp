#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 987654321
int N, M;
typedef pair<int, int> pi;

vector<vector<pi>>graph;
vector<int>solve(int start)
{
	priority_queue<pi, vector<pi>, greater<pi>>pq;
	pq.push({ 0,start });
	vector<int>dist(N + 1, MAX);
	dist[start] = 0;
	int i;
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (auto& g : graph[cur])
		{
			int next = g.second;
			int next_cost = g.first+cost;
			if (next_cost < dist[next])
			{
				dist[next] = next_cost;
				pq.push({ next_cost,next });
			}
		}
	}
	return dist;
}
int main()
{
	int i;
	cin >> N >> M;
	graph.resize(N + 1);
	int a, b, c;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}
	cin >> a >> b;
	vector<int>A = solve(1);
	vector<int>B = solve(a);
	vector<int>C = solve(b);
	int res = min(A[a] + B[b] + C[N], A[b] + C[a] + B[N]);
	if (res < 0 || res >= MAX)
		cout << "-1";
	else
		cout << res;
}