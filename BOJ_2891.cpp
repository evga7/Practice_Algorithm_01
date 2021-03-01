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
int S, R;
vec b;
vec m;
bool is_inside(int x, int y)
{		
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N >> S >> R;
	for (i = 0; i < S; i++)
	{
		cin >> num;
		b.push_back(num);
	}
	for (i = 0; i < R; i++)
	{
		cin >> num;
		m.push_back(num);
	}
	int idx = 0;
	for (i = 0; i < S; i++)
	{
		if (idx < R && abs(m[idx] - b[i]) <= 1)
		{
			idx++;
		}
		else
			res++;
	}
	cout << res;
}
