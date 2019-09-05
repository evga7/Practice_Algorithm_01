#include <iostream>
#include <algorithm>
using namespace std;
char arr[21][21];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int chk[27];
int R, C;
int res = 0;
void DFS(int cnt,int x,int y)
{
	int i;
	chk[arr[x][y] - 'A'] = 1;
	for (i = 0; i < 4; i++)
	{
		int n_x, n_y;
		n_x = x + dx[i];
		n_y = y + dy[i];
		if (n_x < 0 || n_x >= R || n_y < 0 || n_y >=C ||chk[arr[n_x][n_y] - 'A'])
			continue;
		DFS(cnt + 1, n_x, n_y);
		chk[arr[n_x][n_y] - 'A'] = 0;
	}
	res = max(res, cnt);
}
int main()
{
	scanf("%d %d", &R, &C);
	int i, j;
	getchar();
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	DFS(1, 0, 0);
	printf("%d", res);
}