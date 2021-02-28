#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef pair<int, char> pi4;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res = 0;
int T;
int K;
int m[101][101];
int visited[101][101];
vec v;
bool is_inside(int x,int y)
{
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}

int solve(int x,int y)
{
	queue<pi>q;
	visited[x][y] = 1;
	q.push({ x,y });
	int cnt = 0;
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		cnt++;
		int i;
		for (i = 0; i < 4; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (!is_inside(n_x, n_y) || m[n_x][n_y] || visited[n_x][n_y])continue;
			visited[n_x][n_y] = 1;
			q.push({ n_x,n_y });
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	int i,j,k;
	for (i = 0; i < K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (j = b; j <d; j++)
		{
			for (k = a; k <c; k++)
			{
				m[j][k] = 1;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for(j=0;j<M;j++)
		{
			if (!visited[i][j] && !m[i][j])
			{
				v.push_back(solve(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto a : v)
		cout << a << " ";
}
