#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, int>> q;

char arr[101][101];
int dp[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int N;
void BFS(int x, int y, int blind)
{
	char color = arr[x][y];
	q.push(make_pair(x, y));
	dp[x][y] = 1;
	int i;
	while (!q.empty())
	{
		int cur_x, cur_y;
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int n_X, n_Y;
			n_X = dx[i] + cur_x;
			n_Y = dy[i] + cur_y;
			if (n_X<0 || n_X>=N || n_Y<0 || n_Y>=N || dp[n_X][n_Y] == 1)
			{
				continue;
			}
			if (blind == 0)
			{
				if (arr[n_X][n_Y] != color)
					continue;
				dp[n_X][n_Y] = 1;
				q.push(make_pair(n_X, n_Y));
			}
			else
			{
				if ((color == 'R'&&arr[n_X][n_Y] == 'B') || (color == 'G'&&arr[n_X][n_Y] == 'B') || (color == 'B'&&color != arr[n_X][n_Y]))
					continue;
				else
				{
					dp[n_X][n_Y] = 1;
					q.push(make_pair(n_X, n_Y));
				}
			}

		}
	}
}


int main()
{
	int i, j;
	scanf("%d", &N);
	getchar();
	memset(dp, 0, sizeof(dp));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	int cnt = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (dp[i][j] == 0)
			{
				BFS(i, j, 0);
				cnt++;
			}
		}
	}
	memset(dp, 0, sizeof(dp));
	int cnt2 = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (dp[i][j] == 0)
			{
				BFS(i, j, 1);
				cnt2++;
			}
		}
	}
	printf("%d %d", cnt, cnt2);
}