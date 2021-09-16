#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int num;
int res;
int ju[101];
int visited[101][1 << 16];
typedef pair<int, int> pii;
vector<vector<pii>>graph;
typedef struct info {
	int cur, state, cnt;
};
void solve()
{
	queue<info>q;
	q.push({ 1,0,0 });
	visited[1][0] = 1;
	while (!q.empty())
	{
		int cur = q.front().cur;
		int state = q.front().state;
		int cnt = q.front().cnt;
		q.pop();
		if (cur == 1)
		{
			int n_cnt = cnt;
			if (ju[1]&&cnt<14&&!(state&(1<<1)))
				n_cnt++;
			res = max(res, n_cnt);
		}
		for (auto next : graph[cur])
		{
			int _next = next.first;
			int limit = next.second;
			int ju_chk = ju[_next];
			if (ju_chk)
			{
				int n_state = state | (1 << ju_chk);
				if (cnt + 1 <= limit && !visited[_next][n_state]&& !(state & (1 << ju_chk)))
				{
					visited[_next][n_state] = 1;
					q.push({ _next,n_state,cnt + 1 });
				}
			}
			if (cnt > limit || visited[_next][state])continue;
			visited[_next][state] = 1;
			q.push({ _next,state,cnt });
		}
	}
	cout << res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N >> M >> K;
	for (i = 1; i <=K; i++)
	{
		cin >> num;
		ju[num] = i;
	}
	int a, b, c;
	graph.resize(N + 1);
	for (i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	
	solve();

}
