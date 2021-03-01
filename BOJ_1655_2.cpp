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
priority_queue<int, vector<int>, greater<int>>minpq;
priority_queue<int>maxpq;
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
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++)
		cin >> v[i];
	for (i = 0; i < N; i++)
	{
		if (minpq.size() == maxpq.size())
			maxpq.push(v[i]);
		else
			minpq.push(v[i]);
		if (!minpq.empty() && !maxpq.empty() && minpq.top() < maxpq.top())
		{
			int min_top = minpq.top();
			int max_top = maxpq.top();
			minpq.pop();
			maxpq.pop();
			minpq.push(max_top);
			maxpq.push(min_top);
		}
		cout << maxpq.top() << "\n";
	}
}
