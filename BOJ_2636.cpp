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
int res = 0;
int K, L;
int m[101][101];
int visited[101][101];
int chk()
{
	int i, j;
	int cnt = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (m[i][j])cnt++;
		}
	}
	return cnt;
}
void solve()
{
	int sec = 0;
	int ret;
	while (1)
	{
		ret = chk();
		if (!ret)break;
		else
		{
			sec++;
			res = ret;
		}
		queue<pi>q;
		memset(visited, 0, sizeof(visited));
		q.push({ 1,1 });
		visited[1][1] = 1;
		while (!q.empty())
		{
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			int i;
			q.pop();
			for (i = 0; i < 4; i++)
			{
				int n_x = cur_x + dx[i];
				int n_y = cur_y + dy[i];
				if (n_x > 0 && n_x <= N && n_y > 0 && n_y <= M&&!visited[n_x][n_y]) {
					if (!m[n_x][n_y])
					{
						q.push({ n_x,n_y });
					}
					else
					{
						m[n_x][n_y] = 0;
					}
					visited[n_x][n_y] = 1;
				}
			}
		}
	}
	cout << sec << "\n" << res;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int i, j;
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <=M; j++)
		{
			cin >> m[i][j];
		}
	}
	solve();
}