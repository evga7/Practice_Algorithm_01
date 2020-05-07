#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
using namespace std;
int N, K;
vector<pair<int, int>> v;
vector<int>v2;
priority_queue<int> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N>>K;
	int i;
	int a, b;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	for (i = 0; i < K; i++)
	{
		cin >> a;
		v2.push_back(a);
	}
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());
	long long res = 0;
	int index = 0;
	for (i = 0; i < K; i++)
	{
		while (index < N&&v[index].first <= v2[i])
		{
			pq.push(v[index].second);
			index++;
		}
		if (!pq.empty())
		{
			res += pq.top();
			pq.pop();
		}
	}
	cout << res;
}

