#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>pi2;
int T, N, L, R;
int num;
int arr[51][51];
int visited[51][51];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int res = 0;
bool solve(int x, int y)
{
	queue<pi>q;
	int i, j;
	q.push({ x,y });
	int sum = 0;
	int cnt = 0;
	int flag = 0;
	int update[51][51] = { 0, };
	visited[x][y]=1;
	update[x][y] = 1;
	vector<pi>v;
	v.push_back({ x,y });
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		int cost = arr[cur_x][cur_y];
		sum += cost;
		cnt++;
		for (i = 0; i < 4; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N ||update[n_x][n_y]||visited[n_x][n_y])
				continue;
			int n_cost = abs(arr[n_x][n_y] - cost);
			if (n_cost >= L && n_cost <= R)
			{
				update[n_x][n_y] = 1;
				visited[n_x][n_y] = 1;
				q.push({ n_x,n_y });
				v.push_back({ n_x,n_y });
			}
		}
	}
	int len = v.size();
	int val = 0;
	if (cnt!=0)
	val = sum / cnt;
	for (i = 0; i < len; i++)
	{
		int X = v[i].first;
		int Y = v[i].second;
		arr[X][Y] = val;
	}
	if (cnt > 1)
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);	cout.tie(NULL);
	int i, j;
	cin >> N >> L >> R;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	int cnt = 1;
	int is_update = 1;
	while (is_update)
	{
		is_update = 0;
		fill(&visited[0][0], &visited[N][N], 0);
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					if (solve(i, j))
					{
						is_update = 1;
					}
				}
			}
		}
		if (is_update)
			res++;
	}
	cout << res;
}