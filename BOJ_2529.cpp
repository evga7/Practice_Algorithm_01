#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
using namespace std;
int N;
int visited[10];
char arr[10];
vector<int> v;
int flag=0;	
void solve(int cnt,int num)
{
	int i;
	if (flag) return;
	if (cnt == N) {
		for (i = 0; i < v.size(); i++)
			cout << v[i];
		flag = 1;
		return;
	}
	for (i = 0; i <=9; i++)
	{
		if (!visited[i])
		{
			if (arr[cnt] == '>')
			{
				if (num <= i)
					continue;
			}
			else
			{
				if (num >= i)
					continue;
			}
			visited[i] = 1;
			v.push_back(i);
			solve( cnt + 1, i);
			v.pop_back();
			visited[i] = 0;
		}
	}

}
void solve2(int cnt, int num)
{
	int i;
	if (flag) return;
	if (cnt == N) {
		for (i = 0; i < v.size(); i++)
			cout << v[i];
		flag = 1;
		return;
	}
	for (i = 9; i >=0; i--)
	{
		if (!visited[i])
		{
			if (arr[cnt] == '>')
			{
				if (num <= i)
					continue;
			}
			else
			{
				if (num >= i)
					continue;
			}
			visited[i] = 1;
			v.push_back(i);
			solve2(cnt + 1, i);
			v.pop_back();
			visited[i] = 0;
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (i = 9; i >= 0; i--)
	{
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		v.clear();
		v.push_back(i);
		solve2(0, i);
	}
	v.clear();
	cout << endl;
	flag = 0;
	for (i = 0; i <= 9; i++)
	{
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		v.clear();
		v.push_back(i);
		solve(0, i);
	}



}

