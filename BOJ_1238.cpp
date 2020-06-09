#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
using namespace std;
int N, M,X;
vector<vector<pair<int, int>>> graph;
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}

};

vector<int> dijkstra(int x)
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp>pq;
	vector<int> dist(N + 1, 987654321);
	dist[x] = 0;
	pq.push(make_pair(x, 0));
	while (!pq.empty())
	{
		int cur_x = pq.top().first;
		int d = pq.top().second;
		pq.pop();
		if (d > dist[cur_x]) continue;
		int i;
		for (i = 0; i < graph[cur_x].size(); i++)
		{
			int v = graph[cur_x][i].first;
			int w = d + graph[cur_x][i].second;
			if (dist[v] >w)
			{
				dist[v] = w;
				pq.push(make_pair(v, w));
			}
		}
	}
	return dist;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M>>X;
	graph.resize(N+1);
	int i;
	int A, B, T;
	for (i = 0; i < M; i++)
	{
		cin >> A >> B >> T;
		graph[A - 1].push_back(make_pair(B-1, T));
	}
	int res = -1;
	for (i = 0; i < N; i++)
	{
		vector<int> tmp = dijkstra(i);
		vector<int> tmp2 = dijkstra(X-1);
		if (tmp[X - 1] + tmp2[i] >= 987654321 || tmp[X - 1] + tmp2[i] < 0) continue;
		res = max(res, tmp[X - 1] + tmp2[i]);
	}
	cout << res;

}

