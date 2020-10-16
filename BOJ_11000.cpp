#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
int N, M;
int num;
int i, j;
int chk[200001];
vector<pi>v;
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> N;
	int a, b;
	int res = 0;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>>pq;
	pq.push(v[0].second);
	for (i = 1; i < N; i++)
	{
		if (pq.top() <= v[i].first)
		{
			pq.pop();
			pq.push(v[i].second);
		}
		else
			pq.push(v[i].second);
	}
	cout << pq.size();
}


