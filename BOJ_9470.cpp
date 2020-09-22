#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 987654321
int T, K, M, P;
int indegrees[1001];
int c[1001];
int r[1001];
int res;
vector<vector<int>>graph;
void solve()
{
	queue<int>q;
	int i, j;
	for (i = 1; i <= M; i++)
	{
		if (indegrees[i] == 0)
		{
			q.push(i);
			r[i] = 1;
		}
	}
	int cnt = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (c[cur] > 0)r[cur]++;
		res = max(r[cur], res);
		for (auto g : graph[cur])
		{
			int next = g;
			if (r[cur] > r[next])
			{
				r[next] = r[cur];
				c[next] = 0;
			}
			else if (r[next] == r[cur])
				c[next]++;
			if (--indegrees[next] == 0)
			{
				q.push(next);
			}
		}
	}
}
int main() {

	cin >> T;
	int j = 1;
	while (T--)
	{
		cin >> K >> M >> P;
		graph.clear();
		graph.resize(M + 1);
		res = 0;
		memset(indegrees, 0, sizeof(indegrees));
		memset(c, 0, sizeof(c));
		memset(r, 0, sizeof(r));
		int i;
		int a, b;
		for (i = 0; i < P; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			indegrees[b]++;
		}
		solve();
		cout << j++ << " " << res<<"\n";
	}
}