#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef pair<int, char> pi4;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res = MAX;
int K;
vector<pi>c;
vector<pi>h;
int visited[51];
vector<pi>v;
int dist[51];
void solve(int idx,int cnt)
{
	int i, j;
	if (cnt == M)
	{
		int sum = 0;
		for (auto a : h)
		{
			int temp = MAX;
			for (auto b : v)
			{
				int t = abs(a.first - b.first) + abs(a.second - b.second);
				temp = min(temp, t);
			}
			sum += temp;
		}
		res = min(res, sum);
		return;
	}
	else
	{

		for (i = idx; i < c.size(); i++)
		{
			if (!visited[i])
			{
				visited[i] = 1;
				v.push_back(c[i]);
				solve(i, cnt + 1);
				visited[i] = 0;
				v.pop_back();
			}
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N >> M;
	
	for (i = 0; i < N; i++)
	{
		for (j=0;j<N;j++)
		{
			cin >> num;
			if (num == 1)
				h.push_back({ i,j });
			else if (num == 2)
				c.push_back({ i,j });
		}
	}

	solve(0,0);
	cout << res;
}