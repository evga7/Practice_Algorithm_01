#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <map>
#include <stack>
using namespace std;
#define MAX 2147483647
int N;
vector<int>v;
int ans[1000001];
int cnt[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	int num;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		cnt[num]++;
		v.push_back(num);
	}
	stack<int>s;
	s.push(0);
	cnt[0] = MAX;
	for (i = N - 1; i >= 0; i--)
	{
		while (cnt[s.top()] <= cnt[v[i]]) s.pop();
		if (cnt[s.top()] >= MAX) ans[i] = -1;
		else ans[i] = s.top();
		s.push(v[i]);

	}
	for (i = 0; i < N; i++)
		cout << ans[i] << " ";
}

