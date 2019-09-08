#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> q;
int map[101][101];
int check[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int bfs(int N,int M);
int main()
{
	int N, M;
	int i, j;
	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	cout << bfs(N, M);
}
int bfs(int N,int M)
{
	int x, y;
	int i;
	x = y = 1;
	check[x][y]++;
	q.push(make_pair(x,y));
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 1 || next_x > N || next_y < 1 || next_y > M
				||check[next_x][next_y]
				||map[next_x][next_y]!=1)
				continue;
			check[next_x][next_y] = check[x][y]+1;
			q.push(make_pair(next_x,next_y));
		}
	}
	return check[N][M];
}