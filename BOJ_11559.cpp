#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
typedef vector<pi> vec2;
typedef queue<pi> que;
typedef vector<vector<pi>> gra;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int res;
int num;
vector<string>m;
int visited[13][7];
int flag = 0;
bool is_inside(int x, int y)
{
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}
void solve(int x,int y,int t)
{
	queue<pi>q;
	q.push({ x,y });
	visited[x][y] = 1;
	int cnt = 1;
	while (!q.empty())
	{
		int i,j;
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (!is_inside(n_x, n_y)||t!=m[n_x][n_y]||visited[n_x][n_y])continue;
			cnt++;
			visited[n_x][n_y] = 1;
			q.push({ n_x,n_y });
			if (cnt >= 4)
			{
				flag = 1;
				for (i = 0; i < N; i++)
				{
					for (j = 0; j < M; j++)
					{
						if (visited[i][j])
						{
							m[i][j] = '.';
						}
					}
				}
				break;
			}

		}
	}
}
void fall()
{
	int i, j,k;
	for (i = N - 1; i >= 1; i--)
	{
		for (j = 0; j < M; j++)
		{
			if (m[i][j] == '.' && m[i - 1][j] != '.')
			{
				for (k = i; k < N; k++)
				{
					if (m[k][j] != '.')break;
					m[k][j] = m[k - 1][j];
					m[k - 1][j] = '.';
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	N = 12, M = 6;
	string str;
	for (i = 0; i < N; i++)
	{
		cin >> str;
		m.push_back(str);
	}
	while (1)
	{
		flag = 0;
		for (i = N - 1; i >= 0; i--)
		{
			for (j = 0; j < M; j++)
			{
				int t = m[i][j];
				if (t != '.')
				{
					memset(visited, 0, sizeof(visited));
					solve(i, j, t);
				}
			}
		}
		if (flag)
		{
			fall();
			res++;
		}
		else
			break;
	}
	cout << res;
}

