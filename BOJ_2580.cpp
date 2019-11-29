#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int arr[10][10];
int row_chk[10][10];
int col_chk[10][10];
int square_chk[10][10];
void solve(int cnt)
{
	int i, j;
	if (cnt == 81)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
				printf("%d ", arr[i][j]);
			printf("\n");
		}
		exit(0);
	}
	int x = cnt / 9;
	int y = cnt % 9;
	int s = (x / 3) * 3 + (y / 3);
	if (arr[x][y] == 0)
	{
		for (i = 1; i <= 9; i++)
		{
			if (row_chk[x][i] == 0 && col_chk[y][i] == 0 && square_chk[s][i] == 0)
			{
				row_chk[x][i] = 1;
				col_chk[y][i] = 1;
				square_chk[s][i] = 1;
				arr[x][y] = i;
				solve(cnt + 1);
				arr[x][y] = 0;
				row_chk[x][i] = 0;
				col_chk[y][i] = 0;
				square_chk[s][i] = 0;
			}
		}
	}
	else
		solve(cnt + 1);
}
int main()
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0)
			{
				row_chk[i][arr[i][j]] = 1;
				col_chk[j][arr[i][j]] = 1;
				square_chk[(i / 3) * 3 + (j / 3)][arr[i][j]] = 1;
			}
		}
	}
	solve(0);
}