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
int res = 0;
vec v;
int m[1001][1001];
int visited[1001][1001];
queue<pi>q;
int zero;
bool is_inside(int x,int y)
{
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}
void solve()
{
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
			if (!is_inside(n_x, n_y))continue;
			if (visited[n_x][n_y]||m[n_x][n_y]==-1)continue;
			if (visited[cur_x][cur_y] + 1 < visited[n_x][n_y])continue;
			q.push({ n_x,n_y });
			visited[n_x][n_y] = visited[cur_x][cur_y] + 1;
			res = max(res, visited[n_x][n_y] - 1);
			zero--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> M >> N;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> m[i][j];
			if (m[i][j] == 1)
			{
				visited[i][j] = 1;
				q.push({ i,j });
			}
			else if (!m[i][j])
				zero++;
		}
	}
	solve();
	if (!zero)cout << res;
	else cout << -1;
}
