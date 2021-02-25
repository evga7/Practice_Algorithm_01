#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef pair<int, char> pi4;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res;
vector<vector<pi>>v;
int dist[1001];
int t[1001];
int S, E;
stack<int>s;
void solve()
{
	priority_queue < pi, vector <pi>,greater<pi> > pq;
	pq.push({ 0,S });
	dist[S] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (auto a : v[cur])
		{
			int next = a.first;
			int n_cost = cost + a.second;
			if (dist[next] > n_cost)
			{
				dist[next] = n_cost;
				pq.push({ n_cost,next });
				t[next] = cur;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int a, b, c;
	int i;
	v.resize(N + 1);
	for (i = 1; i <= N; i++)
		dist[i] = MAX;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> S >> E;
	solve();
	int cur = E;
	s.push(E);
	while (1)
	{
		if (t[cur] ==0)break;
		s.push(t[cur]);
		cur = t[cur];
	}
	cout << dist[E]<<"\n";
	cout << s.size() << "\n";
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}