#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
deque<int> dq[5];
int visited[5];
void rotate(int num,int direction)
{
	if (direction == 1)
	{
		int temp = dq[num].back();
		dq[num].pop_back();
		dq[num].push_front(temp);
	}
	else if (direction == -1)
	{
		int temp = dq[num].front();
		dq[num].pop_front();
		dq[num].push_back(temp);
	}
}
void solve(int num, int direction)
{
	visited[num] = 1;
	int pre_num, next_num;
	pre_num = num - 1;
	next_num = num + 1;
	if (pre_num >=1 && !visited[pre_num])
	{
		if (dq[pre_num][2]!=dq[num][6])
		solve(pre_num, direction * -1);
	}
	if (next_num <=4 && !visited[next_num])
	{
		if (dq[next_num][6]!=dq[num][2])
		solve(next_num, direction * -1);
	}
	rotate(num, direction);
}
void main()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 8; j++)
		{
			int temp;
			scanf("%1d", &temp);
			dq[i+1].push_back(temp);
		}
	}
	int N;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		int num, direction;
		cin >> num >> direction;
		memset(visited, 0, sizeof(visited));
		solve(num, direction);

	}
	int score = 1;
	int res = 0;
	for (i = 1; i <=4; i++)
	{
		
		if (dq[i].front() == 1)
		{
			res += score;
		}
		score *= 2;
	}
	cout << res;
}

