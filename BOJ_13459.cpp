#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
char map[12][12];
int visited[12][12][12][12];
int N, M;
int des_x, des_y;
queue<pair<int, int>>rq;
queue<pair<int, int>>bq;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int cnt = 0;
int flag = 0;
int rx, ry, bx, by;
int BFS()
{
	while (!rq.empty())
	{
		int Size = rq.size();
		while (Size--)
		{

			rx = rq.front().first;
			ry = rq.front().second;
			bx = bq.front().first;
			by = bq.front().second;
			rq.pop();
			bq.pop();
			if (cnt > 10)
				break;
			if (rx == des_x && ry == des_y)
			{
				flag = 1;
				break;
			}
			int i;
			for (i = 0; i < 4; i++)
			{
				int b_flag = 0;
				int n_rx = rx + dx[i];
				int n_ry = ry + dy[i];
				int n_bx = bx + dx[i];
				int n_by = by + dy[i];
				int r_cnt = 0;
				int b_cnt = 0;
				while (1)
				{
					r_cnt++;
					if (map[n_rx][n_ry] == '#')
					{
						n_rx -= dx[i];
						n_ry -= dy[i];
						break;
					}
					if (map[n_rx][n_ry] == 'O')break;
					n_rx += dx[i];
					n_ry += dy[i];
				}
				while (1)
				{
					b_cnt++;
					if (map[n_bx][n_by] == '#')
					{
						n_bx -= dx[i];
						n_by -= dy[i];
						break;
					}
					if (map[n_bx][n_by] == 'O') {
						b_flag = 1; break;
					}
					n_bx += dx[i];
					n_by += dy[i];
				}
				if (b_flag) continue;
				if (n_rx == n_bx && n_ry == n_by)
				{
					if (r_cnt > b_cnt)
					{
						n_rx -= dx[i];
						n_ry -= dy[i];
					}
					else
					{
						n_bx -= dx[i];
						n_by -= dy[i];
					}

				}
				if (visited[n_rx][n_ry][n_bx][n_by]) continue;
				visited[n_rx][n_ry][n_bx][n_by] = 1;
				rq.push(make_pair(n_rx, n_ry));
				bq.push(make_pair(n_bx, n_by));
			}
		}
		if (flag) return 1;
		else cnt++;
	}
	return 0;
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	getchar();
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'R')
			{
				rq.push(make_pair(i, j));
				rx = i;
				ry = j;
			}
			else if (map[i][j] == 'B')
			{
				bq.push(make_pair(i, j));
				bx = i;
				by = j;
			}
			else if (map[i][j] == 'O')
			{
				des_x = i;
				des_y = j;
			}
		}
		getchar();
	}
	visited[rx][ry][bx][by] = 1;
	printf("%d", BFS());

}