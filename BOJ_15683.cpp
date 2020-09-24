#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;
#define MAX 987654321
typedef long long int ll;
struct cctv
{
	int x, y, type;
};
cctv cc[8];
int N, M;
int map[9][9];
int res = MAX;
int dir[5] = { 4,2,4,4,1 };
int cc_size = 0;
void copy_map(int cmap[9][9],int omap[9][9])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cmap[i][j] = omap[i][j];
}
void update(int index,cctv ccc)
{
	index %= 4;
	int i, j;
	int x = ccc.x;
	int y = ccc.y;
	if (index == 0)
	{
		for (i = y+1; i < M; i++)
		{
			if (map[x][i] == 6)
				break;
			map[x][i] = -1;
		}
	}
	else if (index == 1)
	{
		for (i = x + 1; i < N; i++)
		{
			if (map[i][y] == 6)
				break;
			map[i][y] = -1;
		}
	}
	else if (index == 2)
	{
		for (i = y-1; i >=0; i--)
		{
			if (map[x][i] == 6)
				break;
			map[x][i] = -1;
		}
	}
	else if (index == 3)
	{
		for (i = x - 1; i >= 0; i--)
		{
			if (map[i][y] == 6)
				break;
			map[i][y] = -1;
		}
	}
}
void solve(int index)
{
	int i, j;
	if (index ==cc_size)
	{
		int cnt = 0;
		for (i=0;i<N;i++)
			for (j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
					cnt++;
			}
		res = min(cnt, res);
		return;
	}
	int cmap[9][9];
	int type = cc[index].type;
	for (i = 0; i < dir[type]; i++)
	{
		copy_map(cmap, map);
		if (type == 0)
		{
			update(i, cc[index]);
		}
		else if (type == 1)
		{
			update(i, cc[index]);
			update(i+2, cc[index]);
		}
		else if (type == 2)
		{
			update(i, cc[index]);
			update(i+1, cc[index]);
		}
		else if (type == 3)
		{
			update(i, cc[index]);
			update(i+2, cc[index]);
			update(i+3, cc[index]);
		}
		else if (type == 4)
		{
			update(i, cc[index]);
			update(i+1, cc[index]);
			update(i+2, cc[index]);
			update(i+3, cc[index]);
		}
		solve(index + 1);
		copy_map(map, cmap);
	}

}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
			{
				cc[cc_size].x = i;
				cc[cc_size].y = j;
				cc[cc_size++].type = map[i][j] - 1;
			}
		}
	}
	solve(0);
	cout << res;
}


