
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, K;
int L;
int arr[101][101];
queue<pair<int, int>>q;
queue<pair<int, int>>tail;
queue<pair<int, char>>v2;
int select_dir(int dir, char X)
{
	if (X == 'L')
	{
		return (dir + 3) % 4;
	}
	else if (X == 'D')
		return (dir + 1) % 4;

}

void BFS()
{
	int cur_x = 0;
	int cur_y = 0;
	int dir = 0;
	arr[0][0] = -1;
	tail.push(make_pair(0, 0));
	int sec = 0;
	while (1)
	{
		sec++;
		cur_x += dx[dir];
		cur_y += dy[dir];
		if (cur_x<0 || cur_x>=N || cur_y<0 || cur_y>=N || arr[cur_x][cur_y] == -1)
			break;
		if (arr[cur_x][cur_y] == 0)
		{
			arr[tail.front().first][tail.front().second] = 0;
			tail.push(make_pair(cur_x, cur_y));
			tail.pop();
		}
		else
		{
			tail.push(make_pair(cur_x, cur_y));
		}
		arr[cur_x][cur_y] = -1;
		int i;

		if (v2.size()&&v2.front().first == sec)
		{
			dir = select_dir(dir, v2.front().second);
			v2.pop();
		}
	}
	printf("%d", sec);
}

int main()
{
	int i;
	scanf("%d %d", &N, &K);
	for (i = 0; i < K; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x-1][y-1] = 1;
	}
	scanf("%d", &L);
	for (i = 0; i < L; i++)
	{
		int x;
		char y;
		scanf("%d %c", &x, &y);
		v2.push(make_pair(x, y));
	}
	BFS();
}
