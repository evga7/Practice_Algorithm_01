#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
int N;
vector<pair<int, int>>v;
bool cmp(const pair<int,int> a,const pair<int,int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int i;
	int a, b;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), cmp);
	for (auto num : v)
		cout << num.first << ' ' << num.second<<'\n';
}

