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
priority_queue<int, vector<int>, greater<int>>pq;
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
	{
		cin >> num;
		pq.push(num);
	}
	while (pq.size() > 1)
	{
		int top = pq.top();
		pq.pop();
		if (!pq.empty())
		{
			int top2 = pq.top();
			res += top + top2;
			pq.pop();
			pq.push(top +top2);
		}
	}
	cout << res;

}
