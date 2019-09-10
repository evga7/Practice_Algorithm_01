#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[11][11];
int res = 9999;
int cnt = 0;
int paper[6] = { 0,5,5,5,5,5 };
int chk_size(int x, int y, int len)
{
	int i, j;
	int flag = 0;
	if (x + len > 10 || y + len > 10||paper[len]==0)
		return 0;
	for (i = x; i < x + len; i++)
	{
		for (j = y; j < y+len; j++)
		{
			if (arr[i][j] == 0)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag)
		return 0;
	return len;
}

void DFS(int x, int y)
{
	if (x == 10)
	{
		res = min(res, cnt);
		return;
	}
	if (y == 10)
	{
		DFS(x + 1, 0);
		return;
	}
	if (arr[x][y] == 0)
	{
		DFS(x, y + 1);
		return;
	}
	int i,j,k;
	for (i = 5; i > 0; i--)
	{
		int len = chk_size(x, y, i);
		if (len == 0)
			continue;
		for (j = x; j < x + len; j++)
			for (k = y; k < y + len; k++)
				arr[j][k] = 0;
		cnt++;
		paper[len]--;
		DFS(x, y + len);
		for (j = x; j < x + len; j++)
			for (k = y; k < y + len; k++)
				arr[j][k] = 1;
		paper[len]++;
		cnt--;
	}
}
int main()
{
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			scanf("%d", &arr[i][j]);
	DFS(0, 0);
	if (res == 9999)
		printf("-1");
	else
	printf("%d", res);

}