#include <iostream>
#include <cstring> 
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#define MAX 987654321
using namespace std;
typedef pair<int, int> pi;
typedef long long int ll;
int N, M;
int s, e;
vector<vector<pi>>graph;
int dist[1001];
int trace[1001];
stack<int>st;
void solve()
{
	dist[s] = 0;
	priority_queue<pi, vector<pi>, greater<pi>>pq;
	pq.push({ 0, s });
	int i;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (auto g : graph[cur])
		{
			int next = g.second;
			int n_cost = g.first;
			int c = cost + n_cost;
			if (c< dist[next])
			{
				dist[next] = c;
				trace[next] = cur;
				pq.push({ c,next });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	int i, j;
	graph.resize(N + 1);
	int a, b, c;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
	}
	for (i = 1; i <= N; i++)
		dist[i] = MAX;
	cin >> s >> e;
	solve();
	int cur = e;
	st.push(e);
	while (1)
	{
		if (trace[cur] == 0)
			break;
		st.push(trace[cur]);
		cur= trace[cur];
	}
	cout << dist[e]<<"\n"<<st.size()<<"\n";
	while (!st.empty())
	{
		cout << st.top()<<" ";
		st.pop();
	}

}