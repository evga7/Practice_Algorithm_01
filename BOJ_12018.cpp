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
vec v;
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
	cin >> N >> M;
	int a, b;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		vec temp;
		for (j = 0; j < a; j++)
		{
			cin >> num;
			temp.push_back(num);
		}
		if (a < b)
			v.push_back(1);
		else
		{
			sort(temp.begin(), temp.end(), greater<int>());
			v.push_back(temp[b - 1]);
		}
	}
	sort(v.begin(), v.end());
	for (i = 0; i < v.size(); i++)
	{
		if (M - v[i] >= 0)
		{
			M-= v[i];
			res++;
		}
	}
	cout << res;
}
