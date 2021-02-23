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
int res;
int m[26][26];
int visited[26][26];
vec v;

int solve(int x,int y)
{
	int& ret = visited[x][y];
	if (x < 0 || x >= N || y < 0 || y >= N||!m[x][y]||ret)return 1;
	res++;
	ret = 1;
	int i;
	for (i = 0; i < 4; i++)
	{
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		ret=solve(n_x, n_y);
	}
	return ret;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%1d", &m[i][j]);
		}
	}
	for (i=0;i<N;i++)
	{
		for (j = 0; j < N; j++)
			if (m[i][j]&&!visited[i][j]) {
				res = 0;
				solve(i, j);
				v.push_back(res);
			}
	}
	cout<<v.size()<<"\n";
	sort(v.begin(), v.end());
	for (auto a : v)
		cout << a << "\n";
}