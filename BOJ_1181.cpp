#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
map<string,int> m;
vector<string>v;
bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}
int main()
{
	int N;
	int i;
	string str;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		cin >> str;
		if (!m[str])
		{
			m[str]++;
			v.push_back(str);
		}
	}
	sort(v.begin(), v.end(),cmp);
	for (i = 0; i < v.size() ;i++)
		cout << v[i] << endl;
}
