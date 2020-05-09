#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
using namespace std;
int T, N, M;
vector<pair<int,int>> v(1001);
int chk[1001];
bool visited[1001];
bool solve(int x)
{
	int i;
	int size = v[x].second - v[x].first+1;
	for (i = 0; i < size; i++)
	{
		int t = v[x].first + i;
		if (visited[t])
			continue;
		visited[t] = true;
		if (chk[t]==0|| solve(chk[t]))
		{
			chk[t] = x;
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	int i;
	while (T--)
	{
		cin >> N >> M;
		int res = 0;
		v.clear();
		//memset 썼다가 틀림
		fill(chk, chk + 1001, 0);
		v.push_back(make_pair(0, 0));
		for (i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		for (i = 1; i <= M; i++)
		{
			fill(visited, visited + 1001, false);
			if (solve(i))
				res++;
		}
		cout << res << "\n";
	}
	
}

