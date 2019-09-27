#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
int arr[3001][3001];
int N, M;
int visited[3001][3001];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int res = 999999999;
queue<pair<pair<int, int>, int>>q;
void BFS()
{
	while (!q.empty())
	{
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (arr[cur_x][cur_y] > 2)
		{
			res = min(res, cnt);
			return;
		}
		int i;
		for (i = 0; i < 4; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M|| visited[n_x][n_y] || arr[n_x][n_y] == 1)
				continue;
			q.push(make_pair(make_pair(n_x, n_y), cnt + 1));
			visited[n_x][n_y] = 1;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	int i, j;
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (j = 0; j < M; j++)
		{
			arr[i][j] = str[j] - '0';
			if (arr[i][j] == 2)
			{
				visited[i][j] = 1;
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}
	BFS();
	if (res != 999999999)
		printf("TAK\n%d", res);
	else
		printf("NIE");
}