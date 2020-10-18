#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>pi2;
int N, M;
int num;
int arr[301][301];
int visited[301][301];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int res = 0;
vector<pi>v;
vector<int>cntv;
void dfs(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= M||visited[x][y])
		return;
	visited[x][y] = 1;
	int i;
	for (i = 0; i < 4; i++)
	{
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if (arr[n_x][n_y])
		dfs(n_x, n_y);
	}
}
int chk(int x, int y)
{
	int cnt = 0;
	if (x - 1 >= 0 &&!arr[x - 1][y])
		cnt++;
	if (x + 1 < N && !arr[x + 1][y])
		cnt++;
	if (y + 1 < M && !arr[x][y + 1])
		cnt++;
	if (y - 1 >= 0 &&!arr[x][y - 1])
		cnt++;
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);	cout.tie(NULL);
	int i, j;
	cin >> N >> M;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])
				v.push_back({ i,j });
		}
	}
	int flag = 0;
	while (1)
	{
		vector<pi>v2;
		int len = v.size();
		for (i = 0; i < len; i++)
		{
			int x = v[i].first;
			int y = v[i].second;
			cntv.push_back(chk(x, y));
		}
		for (i = 0; i < len; i++)
		{
			int x = v[i].first;
			int y = v[i].second;
			int num = arr[x][y] - cntv[i];
			if (num <= 0)
				num = 0;
			else
				v2.push_back({ x,y });
			arr[x][y] = num;
		}
		res++;
		int cnt = 0;
		len = v2.size();
		if (len == 0)
		{
			cout << 0;
			return 0;
		}
		for (i = 0; i < len; i++)
		{
			int x = v2[i].first;
			int y = v2[i].second;
			if (!visited[x][y])
			{
				dfs(x, y);
				cnt++;
				if (cnt > 1)
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag)
		{
			break;
		}
		fill(&visited[0][0], &visited[N][M], 0);
		cntv.clear();
		v = v2;


	}
	cout << res;
}