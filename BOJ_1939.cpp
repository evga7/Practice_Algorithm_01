#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
using namespace std;
int N, M;
int S, E;
vector<pair<int,int>>v[100001];
queue<int>q;
bool visited[100001];
bool BFS(int cost)
{
	q.push(S);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int i;
		if (cur == E)
			return true;
		for (i = 0; i < v[cur].size(); i++)
		{
			int n_x = v[cur][i].first;
			int n_c = v[cur][i].second;
			if (!visited[n_x] && cost <= n_c)
			{
				visited[n_x] = true;
				q.push(n_x);
			}
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int a, b, c;
	int i;
	int right = 0;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
		right = max(right, c);
	}
	cin >> S >> E;
	int left = 0;
	int res = 0;
	while (left <= right)
	{
		memset(visited, false, sizeof(visited));
		int mid = (left + right) / 2;
		if (BFS(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << right;
}

