#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef pair<int, char> pi4;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res = 0;
int K, L;
int m[101][101];
queue<pi4>v;
int solve()
{
	queue<pi2>q;
	queue<pi>tail;
	q.push({ 0, { 0,0 }  });
	m[0][0] = 1;
	int t = 0;
	tail.push({ 0,0 });
	while (!q.empty())
	{
		t++;
		int dir = q.front().first;
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;
		int tail_x = tail.front().first;
		int tail_y = tail.front().second;
		int n_x = cur_x + dx[dir];
		int n_y = cur_y + dy[dir];
		q.pop();
		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N || m[n_x][n_y] == 1)break;
		if (m[n_x][n_y] == 2)
		{
			tail.push({ n_x,n_y });
		}
		else
		{
			m[tail_x][tail_y] = 0;
			tail.push({ n_x,n_y });
			tail.pop();
		}
		m[n_x][n_y] = 1;
		if (!v.empty()&&v.front().first == t)
		{
			int i;
			if (v.front().second == 'L')
			{
				dir--;
				if (dir < 0)
					dir = 3;
			}
			else
			{
				dir++;
				dir %= 4;
			}
			v.pop();
		}
		q.push({ dir, {n_x,n_y}  });
	}
	return t;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> K;
	int i;
	int a, b;
	for (i = 0; i < K; i++)
	{
		cin >> a >> b;
		m[a - 1][b - 1] = 2;
	}
	cin >> L;
	int x;
	char c;
	for (i = 0; i < L; i++)
	{
		cin >> x >> c;
		v.push({ x,c });
	}
	cout << solve();
}