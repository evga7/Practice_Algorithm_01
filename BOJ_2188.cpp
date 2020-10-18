#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>pi2;
int T, N, M;
int num;
int visited[205];
int d[205];
vector<vector<int>>v;
bool solve(int x)
{
	for (auto num : v[x])
	{
		if (visited[num])continue;
		visited[num] = 1;
		if (!d[num] || solve(d[num]))
		{
			d[num]=x;
			return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);	cout.tie(NULL);
	cin >> N >> M;
	int i;
	v.resize(201);
	for (i = 1; i <=N; i++)
	{
		cin >> T;
		while (T--)
		{
			cin >> num;
			v[i].push_back(num);
		}
	}
	int res = 0;
	for (i = 1; i <= N; i++)
	{
		fill(visited, visited + 201, 0);
		if (solve(i))
		{
			res++;
		}
	}
	cout << res;
}