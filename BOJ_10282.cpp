#include <iostream>
#include <cstring> 
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#define MAX 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
int N,D,C;
int T;
vector<vector<pi>>graph;
int i;
int res_time;
int res_cnt;
int infected[10001];
int time[10001];
void solve()
{
	priority_queue<pi, vector<pi>, greater<pi>>pq;
	pq.push({ 0,C });
	infected[C] = 1;
	time[C] = 0;
	while (!pq.empty())
	{
		auto tmp = pq.top();
		int cur = tmp.second;
		int t = tmp.first;
		pq.pop();

		for (auto g : graph[cur])
		{
			int next = g.second;
			int n_t = g.first+t;
			if (infected[cur])
			{
				if (!infected[next])
				{
					infected[next] = 1;
					res_cnt++;
				}
				if (time[next] > n_t)
				{
					time[next] = n_t;
					pq.push({ n_t,next });
				}
			}

		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> D >> C;
		graph.clear();
		graph.resize(N + 1);
		int a, b, c;
		fill(infected, infected + N + 1,0);
		fill(time, time + N + 1, MAX);
		res_cnt = 1;
		res_time = 0;
		for (i = 0; i < D; i++)
		{
			cin >> a >> b >> c;
			graph[b].push_back({ c,a });
		}
		solve();
		for (i = 1; i <= N; i++)
		{
			if (time[i] != MAX)
				res_time = max(res_time, time[i]);
		}
		cout << res_cnt << " " << res_time << "\n";
	}
	
	
}
