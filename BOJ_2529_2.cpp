#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
typedef vector<pi> vec2;
typedef queue<pi> que;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res;
vector<char> op;
vec v;
int visited[10];
int flag;
bool is_inside(int x, int y)
{
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}
void solve(int idx,int cnt)
{
	if (flag)return;
	if (cnt == N)
	{
		for (auto a : v)
			cout << a;
		flag = 1;
		return;
	}
	int i;
	for (i = 0; i <= 9; i++)
	{
		if (op[cnt] == '>' && !visited[i]&&idx>i)
		{
			visited[i] = 1;
			v.push_back(i);
			solve(i,cnt+1);
			visited[i] = 0;
			v.pop_back();
		}
		else if (op[cnt] == '<' && !visited[i]&&idx<i)
		{
			visited[i] = 1;
			v.push_back(i);
			solve(i,cnt+1);
			visited[i] = 0;
			v.pop_back();
		}
	}
}

void solve2(int idx, int cnt)
{
	if (flag)return;
	if (cnt == N)
	{
		for (auto a : v)
			cout << a;
		flag = 1;
		return;
	}
	int i;
	for (i = 9; i >=0 ; i--)
	{
		if (op[cnt] == '>' && !visited[i] && idx > i)
		{
			visited[i] = 1;
			v.push_back(i);
			solve2(i, cnt + 1);
			visited[i] = 0;
			v.pop_back();
		}
		else if (op[cnt] == '<' && !visited[i] && idx < i)
		{
			visited[i] = 1;
			v.push_back(i);
			solve2(i, cnt + 1);
			visited[i] = 0;
			v.pop_back();
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N;
	char temp;
	for (i = 0; i < N; i++)
	{
		cin >> temp;
		op.push_back(temp);
	}
	for (i = 9; i >= 0; i--)
	{
		memset(visited, 0, sizeof(visited));
		v.clear();
		v.push_back(i);
		visited[i] = 1;
		solve2(i, 0);
	}
	flag = 0;
	cout << "\n";
	for (i = 0; i <= 9; i++)
	{
		memset(visited, 0, sizeof(visited));
		v.clear();
		v.push_back(i);
		visited[i] = 1;
		solve(i,0);
	}
	
}
