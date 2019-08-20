#include <iostream>
using namespace std;
#include <string.h>
#include <queue>
int arr[305][305];
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int T;
int N;
int sx, sy, desx, desy;
void BFS()
{
	queue <pair<pair<int, int>, int>> q;
	arr[sx][sy] = 1;
	q.push(make_pair(make_pair(sx, sy), 0));
	while (!q.empty())
	{
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (cur_x == desx && cur_y == desy)
		{
			printf("%d\n", cnt);
			return;
		}
		for (int i = 0; i < 8; i++)
		{

			int n_x, n_y;
			n_x = cur_x + dx[i];
			n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N)
				continue;
			if (arr[n_x][n_y])
				continue;
			arr[n_x][n_y] = 1;
			q.push(make_pair(make_pair(n_x, n_y), cnt + 1));
		}
	}
}

int main()
{
	int i, j, k;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);
		scanf("%d %d %d %d", &sx, &sy, &desx, &desy);
		memset(arr, 0, sizeof(arr));
		BFS();
	}

}

